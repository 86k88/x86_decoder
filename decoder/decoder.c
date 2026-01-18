#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "decoder.h"
#include "x86_opcode_desc.h"
#include "x86_opcode_tables.h"
// include your own ringbuf implementation here.
#include "..\ringbuf\ringbuf.h"
// yes.
#include "..\uop\uop.h"
#include "..\uop\opcode_uop.h"
extern const opcode_desc_t opcode_1byte[256];
extern const opcode_desc_t opcode_0f[256];
extern const opcode_desc_t opcode_0f38[256];
extern const opcode_desc_t opcode_0f3a[256];
static uint8_t decode_mandatory_pf(const decoder_t *d)
{
    if (d->prefix.op_size) return 0x66;
    if (d->prefix.rep == 2) return 0xF2;
    if (d->prefix.rep == 1) return 0xF3;
    return 0;
}

static int8_t decode_modrm_ext(const decoder_t *d, const opcode_desc_t *desc)
{
    if (!d->has_modrm)
        return -1;

    if (desc->bits & OP_GROUP)   /* or (desc->bits & OP_GROUP) */
        return (int8_t)d->group;

    return -2;
}
static void decode_opcode_bytes(const decoder_t *d,
                                uint8_t *op,
                                uint8_t *op_len)
{
    *op_len = d->opcode_len;

    if (d->opcode_len == 1) {
        op[0] = d->opcode.opc2;
    } else if (d->opcode_len == 2) {
        op[0] = 0x0F;
        op[1] = d->opcode.opc2;
    } else if (d->opcode_len == 3) {
        op[0] = 0x0F;
        op[1] = d->opcode.opc2;
        op[2] = d->opcode.opc3;
    }
}

static bool is_prefix(uint8_t b)
{
    switch (b) {
        case 0x26: case 0x2E: case 0x36: case 0x3E:
        case 0x64: case 0x65:
        case 0x66:
        case 0x67:
        case 0xF0:
        case 0xF2:
        case 0xF3:
            return true;
        default:
            return false;
    }
}

static void apply_prefix(decoder_t *d, uint8_t b)
{
    switch (b) {
        case 0x26: d->prefix.segment = 0; break;
        case 0x2E: d->prefix.segment = 1; break;
        case 0x36: d->prefix.segment = 2; break;
        case 0x3E: d->prefix.segment = 3; break;
        case 0x64: d->prefix.segment = 4; break;
        case 0x65: d->prefix.segment = 5; break;
        case 0x66: d->prefix.op_size = true; break;
        case 0x67: d->prefix.addr_size = true; break;
        case 0xF0: d->prefix.lock = true; break;
        case 0xF2: d->prefix.rep = 2; break;
        case 0xF3: d->prefix.rep = 1; break;
    }
}

static uint8_t calc_disp_len(const decoder_t *d)
{
    const opcode_desc_t *desc = decoder_get_desc(d);

    /* moffs: disp without ModRM */
    if (desc->bits & OP_MOFFS)
        return d->addrsz32 ? 4 : 2;

    if (!d->has_modrm)
        return 0;

    uint8_t mod = (d->modrm >> 6) & 3;
    uint8_t rm  = d->modrm & 7;

    if (d->addrsz32) {
        if (mod == 0 && rm == 5) return 4;
        if (mod == 1) return 1;
        if (mod == 2) return 4;
    } else {
        if (mod == 0 && rm == 6) return 2;
        if (mod == 1) return 1;
        if (mod == 2) return 2;
    }

    return 0;
}


static uint8_t calc_imm_len(const decoder_t *d)
{
    const opcode_desc_t *desc = decoder_get_desc(d);
    uint32_t f = desc->bits;

    /* ENTER */
    if (f & OP_IMM16_8)
        return 3;

    /* far call/jmp */
    if (f & OP_FAR_PTR)
        return d->opsz32 ? 6 : 4;


    /* F6 / F7 TEST */
	/* F6 / F7 are Group 3: only /0 (TEST) has an immediate */
	if (d->opcode.opc2 == 0xF6)
		return (d->group == 0) ? 1 : 0;

	if (d->opcode.opc2 == 0xF7)
		return (d->group == 0) ? (d->opsz32 ? 4 : 2) : 0;



    if (!(f & OP_HAS_IMM))
        return 0;

    if (f & OP_IMM8)  return 1;
    if (f & OP_IMM16) return 2;
    if (f & OP_IMM32) return 4;

    if (f & OP_IMM_OPSZ)
            return d->opsz32 ? 4 : 2;

    return 0;
}
static inline bool dec_peek(decoder_t *d, size_t off, uint8_t *byte)
{
    if (off >= d->bytes_len) {
        d->resume_state = d->state;
		d->state = DEC_FETCH;
        return true;  
    }
    *byte = d->bytes[off];
    return false;
}
void decoder_set_fetch(decoder_t *d, fetch_cb_t cb, void *user)
{
    d->fetch = cb;
    d->fetch_user = user;
}

void decoder_init(decoder_t *d)
{
    memset(d, 0, sizeof(*d));
	d->default_op_size   = 32;
	d->default_addr_size = 32;
}

void decoder_reset(decoder_t *d)
{
    fetch_cb_t fetch = d->fetch;
    void *fetch_user = d->fetch_user;

    memset(d, 0, sizeof *d);

    d->fetch = fetch;
    d->fetch_user = fetch_user;


    d->off = 0;
    d->bytes_len = 0;
    d->instr_len = 0;
    d->disp_read = 0;
    d->imm_read = 0;
    /* FSM: start by fetching first byte */
    d->state = DEC_IDLE;
    d->resume_state = DEC_PREFIX;
    /* defaults */
    d->default_op_size   = 32;
    d->default_addr_size = 32;
    d->opcode_map = 0;  
    d->opcode_last = 0;  
    d->modrm_ext = 0;   
    d->mand_pf = 0;      
    d->uop_recipe = 0; 
    d->opcode.opc1 = d->opcode.opc2 = d->opcode.opc3 = 0;
    d->opcode_len = 0;
    d->has_modrm = false;
    d->group = 0;
}

decoder_t *decoder_create(void)
{
    return calloc(1, sizeof(decoder_t));
}


dec_state_t decoder_step(decoder_t *d, ringbuf_t *r)
{
    uint8_t b;
    
    if (d->off >= 15) {
        d->state = DEC_FAULT;
        return d->state;
    }
    switch (d->state) 
    {
        case DEC_IDLE:
        {
            d->state = d->resume_state;
            break;
        }

        case DEC_FETCH: 
        {
            b = 0x00;
            d->bytes[d->bytes_len++] = b;
            d->state = d->resume_state; 
            break;
	    }
        case DEC_PREFIX:
        {
            if (dec_peek(d, d->off, &b))
                   break;

            
            if (is_prefix(b)) {
                apply_prefix(d, b);
                d->off++;
                d->state = DEC_PREFIX; // keep eating prefixes
                break;
            } else {
                d->state = DEC_OPCODE;
            }
            break;
        }


        case DEC_OPCODE:

            if (!d->opcode_done)
            {
                if (dec_peek(d, d->off, &b))
                   break;
                d->off++;
                switch (d->opcode_len)
                {
                    case 0:
                        if (b == 0x0F)
                        {
                            d->opcode.opc1 = 0x0F;
                            d->opcode_len++;
                            break;
                        } else {
                            d->opcode.opc2 = b;
                            d->opcode_len++;
                            d->opcode_done = true;
                            break;
                        }
                    case 1:
                        if ((b == 0x3A) || (b == 0x38))
                        {
                            d->opcode.opc2 = b;
                            d->opcode_len++;
                            break;
                        } else {
                            d->opcode.opc2 = b;
                            d->opcode_len++;
                            d->opcode_done = true;
                            break;
                        }
                    case 2:
                        d->opcode.opc3 = b;
                        d->opcode_len++;
                        d->opcode_done = true;
                        break;
                    default:
                        break;
                }
                break;
            }
            if (d->opcode_len == 1) 
            {
                d->opcode_map  = OPC_MAP_1B;
                d->opcode_last = d->opcode.opc2;
            } else if (d->opcode_len == 2) 
            {
                d->opcode_map  = OPC_MAP_0F;
                d->opcode_last = d->opcode.opc2;
            } else if (d->opcode_len == 3) 
            {
                if (d->opcode.opc2 == 0x38) 
                {
                    d->opcode_map  = OPC_MAP_0F38;
                    d->opcode_last = d->opcode.opc3;
                } else if (d->opcode.opc2 == 0x3A) 
                {
                    d->opcode_map  = OPC_MAP_0F3A;
                    d->opcode_last = d->opcode.opc3;
                }
            }
            


            d->opsz32   = (d->default_op_size   == 32) ^ d->prefix.op_size;
            d->addrsz32 = (d->default_addr_size == 32) ^ d->prefix.addr_size;


            const opcode_desc_t *desc = decoder_get_desc(d);
            if (desc->bits & OP_MOFFS) {
                d->disp_len = d->addrsz32 ? 4 : 2;
                d->state = DEC_DISP;
                break;
            }

            if (d->prefix.lock && !(desc->bits & OP_LOCKABLE))
                goto fault;

            if (d->prefix.rep == 1 && !(desc->bits & OP_REPABLE))
                goto fault;

            if (d->prefix.rep == 2 && !(desc->bits & OP_REPNEABLE))
                goto fault;


            if ((b & 0xFC) == 0xA0) {
                d->disp_len = d->addrsz32 ? 4 : 2;
                d->state = DEC_DISP;
                break;
            }

                        /* String ops terminate here */
            if (desc->bits & OP_STRING) {
                d->state = DEC_UPDATE;
                break;
            }
            /* No ModRM, but immediate or disp still possible */
            if (!(desc->bits & OP_HAS_MODRM)) {
                if (desc->bits & OP_HAS_DISP) {
                    d->state = DEC_DISP;
                } else if (desc->bits & OP_HAS_IMM) {
                    d->state = DEC_IMM;
                } else {
                    d->state = DEC_UPDATE;
                }
                break;
            }



            /* Otherwise, ModRM follows */
            d->state = DEC_MODRM;
            break;



        case DEC_MODRM: {
            const opcode_desc_t *desc = decoder_get_desc(d);

            if (!(desc->bits & OP_HAS_MODRM)) {
                d->state = DEC_IMM;
                break;
            }

            if (dec_peek(d, d->off, &b))
                    break;

            d->off++;

            d->has_modrm = true;
            d->modrm = b;

            if (desc->bits & OP_GROUP)
                d->group = (b >> 3) & 7;

            uint8_t mod = (b >> 6) & 3;
            uint8_t rm  = b & 7;


            if (d->addrsz32 && mod != 3 && rm == 4)

                d->state = DEC_SIB;
            else
                d->state = DEC_DISP;
            break;
        }

        case DEC_SIB:
            if (dec_peek(d, d->off, &b))
                    break;

            d->off++;

            d->has_sib = true;
            d->sib = b;
            d->state = DEC_DISP;
            break;

        case DEC_DISP:
        {
            /* First entry into this state for this instruction */
            if (d->disp_read == 0) {
                d->disp_len = calc_disp_len(d);
                d->disp = 0;
                if (d->disp_len == 0) {
                    d->state = DEC_IMM;
                    break;
                }
            }

            /* Read one disp byte per step (resumable) */
            if (d->disp_read < d->disp_len) {
                if (dec_peek(d, d->off, &b))
                    break; /* went to DEC_FETCH */

                d->off++;
                d->disp |= (uint32_t)b << (8 * d->disp_read);
                d->disp_read++;
            }

            if (d->disp_read >= d->disp_len) {
                d->state = DEC_IMM;
            } else {
                d->state = DEC_DISP; /* keep going */
            }
            break;
        }

        case DEC_IMM:
        {
            const opcode_desc_t *desc = decoder_get_desc(d);

            if (desc->bits & OP_FAR_PTR) {
                if (d->imm_read == 0) {
                    d->far_offset = 0;
                    d->far_selector = 0;
                }

                /* read offset first */
                if (d->imm_read < (d->opsz32 ? 4 : 2)) {
                    if (dec_peek(d, d->off, &b))
                        break;

                    d->far_offset |= (uint32_t)b << (8 * d->imm_read);
                    d->off++;
                    d->imm_read++;
                    break;
                }

                /* then selector */
                uint32_t sel_off = d->opsz32 ? 4 : 2;
                if (d->imm_read < sel_off + 2) {
                    if (dec_peek(d, d->off, &b))
                        break;

                    d->far_selector |= (uint16_t)b << (8 * (d->imm_read - sel_off));
                    d->off++;
                    d->imm_read++;
                    break;
                }

                d->state = DEC_UPDATE;
                break;
            }
            if (d->imm_read == 0) {
                d->imm_len = calc_imm_len(d);
                d->imm = 0;
                if (d->imm_len == 0) {
                    d->state = DEC_UPDATE;
                    break;
                }
            }

            if (d->imm_read < d->imm_len) {
                if (dec_peek(d, d->off, &b))
                    break; /* went to DEC_FETCH */

                d->off++;
                d->imm |= (uint32_t)b << (8 * d->imm_read);
                d->imm_read++;
            }

            if (d->imm_read >= d->imm_len) {
                d->state = DEC_UPDATE;
            } else {
                d->state = DEC_IMM;
            }
            break;
        }



        case DEC_UPDATE:
        {
            uint8_t mand = 0;
            const opcode_desc_t *desc = decoder_get_desc(d);

            d->uop_recipe = x86_uop_lookup(&k);
            

            
            d->modrm_ext = (desc->bits & OP_GROUP) ? d->group : -1;
            d->mand_pf = mand;
            d->instr_len = d->off;
            d->state = DEC_DONE;
            break;

        }

        
        case DEC_DONE:
            d->state = DEC_DONE;
            break;
        case DEC_FAULT:
        fault:
            d->state = DEC_FAULT;
            break;
        }
    return d->state;
}
   
