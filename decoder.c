#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>


#define MEM_SIZE (16 * 1024 * 1024)
extern uint8_t memory[];

#include "decoder.h"
#include "opcode_desc.h"
#include "opcode_flags.h"

extern const opcode_desc_t opcode_1byte[256];
extern const opcode_desc_t opcode_0f[256];


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

// static uint8_t dec_peek(decoder_t *d, size_t off)
// {
    // if (off >= d->length) {
        // size_t got = d->fetch(
            // d->fetch_user,
            // d->ip + d->length,
            // &d->bytes[d->length],
            // 15 - d->length
        // );
        // if (!got)
            // return 0xFF;
        // d->length += got;
    // }
    // return d->bytes[off];
// }
static inline uint8_t dec_peek(decoder_t *d, size_t off)
{
    if (off >= d->length) {
        d->resume_state = d->state;
		d->state = DEC_FETCH;
        return 0xFF;   
    }
    return d->bytes[off];
}

static uint8_t calc_disp_len(const decoder_t *d)
{
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
    uint32_t f = desc->flags;

    /* ENTER */
    if (f & OP_IMM16_8)
        return 3;

    /* far call/jmp */
    if (f & OP_FAR_PTR)
        return 6;

    /* F6 / F7 TEST */
	/* F6 / F7 are Group 3: only /0 (TEST) has an immediate */
	if (d->opcode == 0xF6)
		return (d->group == 0) ? 1 : 0;

	if (d->opcode == 0xF7)
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
decoder_t *decoder_create(void)
{
    return calloc(1, sizeof(decoder_t));
}


void decoder_reset(decoder_t *d, uint32_t ip)
{
    fetch_cb_t fetch = d->fetch;
    void *fetch_user = d->fetch_user;
    trace_cb_t trace = d->trace;
    void *trace_user = d->trace_user;

    memset(d, 0, sizeof *d);

    d->fetch = fetch;
    d->fetch_user = fetch_user;
    d->trace = trace;
    d->trace_user = trace_user;

    d->ip = ip;

    d->off = 0;
    d->length = 0;
    d->instr_len = 0;

    /* FSM: start by fetching first byte */
    d->state = DEC_FETCH;
    d->resume_state = DEC_PREFIX;

    /* defaults */
    d->default_op_size   = 32;
    d->default_addr_size = 32;

    d->opcode = 0;
    d->opcode_bytes = 0;
    d->has_modrm = false;
    d->group = 0;
}


void decoder_init(decoder_t *d)
{
    memset(d, 0, sizeof(*d));
    d->state = DEC_PREFIX;
	d->default_op_size   = 32;
	d->default_addr_size = 32;
}

void decoder_set_fetch(decoder_t *d, fetch_cb_t cb, void *user)
{
    d->fetch = cb;
    d->fetch_user = user;
}

void decoder_set_trace(decoder_t *d, trace_cb_t cb, void *user)
{
    d->trace = cb;
    d->trace_user = user;
}

bool decoder_step(decoder_t *d)
{
    uint8_t b;

    if (d->off >= 15) {
        d->state = DEC_FAULT;
        trace_emit(d, TRACE_FAULT);
        return true;
    }

    switch (d->state) {
	case DEC_FETCH: {
		if (d->length >= 15) {
			d->state = DEC_FAULT;
			trace_emit(d, TRACE_FAULT);
			return false;
		}

		uint8_t b;
		size_t n = d->fetch(
			d->fetch_user,
			d->ip + d->length,
			&b,
			1
		);

		if (n != 1) {
			d->state = DEC_FAULT;
			trace_emit(d, TRACE_FAULT);
			return false;
		}

		d->bytes[d->length++] = b;

		d->state = d->resume_state; 
		return true;
	}


    case DEC_PREFIX:
        b = dec_peek(d, d->off);

        if (is_prefix(b)) {
            apply_prefix(d, b);
            d->off++;
            trace_emit(d, TRACE_PREFIX);
        } else {
            d->state = DEC_OPCODE;
        }
        break;

	case DEC_OPCODE:
		b = dec_peek(d, d->off++);

		d->opcode_bytes = 1;


		if ((b & 0xFC) == 0xA0) {
			d->opcode = b;
		} else if (b == 0x0F) {
			uint8_t b2 = dec_peek(d, d->off++);
			d->opcode = 0x0F00 | b2;
			d->opcode_bytes = 2;
		} else {
			d->opcode = b;
		}


		d->opsz32   = (d->default_op_size   == 32) ^ d->prefix.op_size;
		d->addrsz32 = (d->default_addr_size == 32) ^ d->prefix.addr_size;


		const opcode_desc_t *desc = decoder_get_desc(d);
		if (desc->flags & OP_MOFFS) {
			d->disp_len = d->addrsz32 ? 4 : 2;
			d->state = DEC_DISP;
			break;
		}

		if (d->prefix.lock && !(desc->flags & OP_LOCKABLE))
			goto fault;

		if (d->prefix.rep == 1 && !(desc->flags & OP_REPABLE))
			goto fault;

		if (d->prefix.rep == 2 && !(desc->flags & OP_REPNEABLE))
			goto fault;

		trace_emit(d, TRACE_OPCODE);


		if ((b & 0xFC) == 0xA0) {
			d->disp_len = d->addrsz32 ? 4 : 2;
			d->state = DEC_DISP;
			break;
		}


		if ((desc->flags & OP_NO_OPERANDS) &&
			!(desc->flags & (OP_HAS_MODRM | OP_HAS_IMM | OP_HAS_DISP))) {
			d->state = DEC_DONE;
			break;
		}

		if (desc->flags & OP_STRING) {
			d->state = DEC_DONE;
			break;
		}

		d->state = DEC_MODRM;
		break;


    case DEC_MODRM: {
        const opcode_desc_t *desc = decoder_get_desc(d);

        if (!(desc->flags & OP_HAS_MODRM)) {
            d->state = DEC_IMM;
            break;
        }

        b = dec_peek(d, d->off++);

        d->has_modrm = true;
        d->modrm = b;

        if (desc->flags & OP_GROUP)
            d->group = (b >> 3) & 7;

        uint8_t mod = (b >> 6) & 3;
        uint8_t rm  = b & 7;

        trace_emit(d, TRACE_MODRM);

        if (d->addrsz32 && mod != 3 && rm == 4)

            d->state = DEC_SIB;
        else
            d->state = DEC_DISP;
        break;
    }

    case DEC_SIB:
        b = dec_peek(d, d->off++);

        d->has_sib = true;
        d->sib = b;
        trace_emit(d, TRACE_SIB);
        d->state = DEC_DISP;
        break;

    case DEC_DISP:
        d->disp_len = calc_disp_len(d);
        d->disp = 0;

        for (uint8_t i = 0; i < d->disp_len; i++) {
            b = dec_peek(d, d->off++);
            d->disp |= (uint32_t)b << (8 * i);
        }

        if (d->disp_len)
            trace_emit(d, TRACE_DISP);

        d->state = DEC_IMM;
        break;

    case DEC_IMM:
        d->imm_len = calc_imm_len(d);
        d->imm = 0;

        for (uint8_t i = 0; i < d->imm_len; i++) {
            b = dec_peek(d, d->off++);
            d->imm |= (uint32_t)b << (8 * i);
        }

        if (d->imm_len)
            trace_emit(d, TRACE_IMM);

        d->state = DEC_DONE;
        break;

    case DEC_DONE:
        trace_emit(d, TRACE_DONE);
		d->instr_len = d->off;
        return true;

    case DEC_FAULT:
    fault:
        d->state = DEC_FAULT;
        trace_emit(d, TRACE_FAULT);
        return true;
    }

    return false;
}
