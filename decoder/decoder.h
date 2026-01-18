#pragma once
#define BUF_LEN 512
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "x86_opcode_desc.h"
#include "x86_opcode_tables.h"
#include "..\ringbuf\ringbuf.h"
#include "..\uop\uop.h"
#include "..\uop\opcode_uop.h"
typedef struct decoder_s decoder_t;
extern const opcode_desc_t opcode_1byte[256];
extern const opcode_desc_t opcode_0f[256];
extern const opcode_desc_t opcode_0f38[256];
extern const opcode_desc_t opcode_0f3a[256];
#define OPC_MAP_1B   0
#define OPC_MAP_0F   1
#define OPC_MAP_0F38 2
#define OPC_MAP_0F3A 3

typedef size_t (*fetch_cb_t)(
    void *user,
    uint32_t addr,
    uint8_t *out,
    size_t max_len
);


typedef enum {
    DEC_IDLE,
	DEC_FETCH,
    DEC_PREFIX,
    DEC_OPCODE,
    DEC_MODRM,
    DEC_SIB,
    DEC_DISP,
    DEC_IMM,
    DEC_DONE,
    DEC_UPDATE,
    DEC_FAULT,
    DEC_REFETCH
} dec_state_t;


struct decoder_s {
    void *trace_user;
    uint8_t bytes[15];
    uint8_t bytes_len;
    bool opcode_done;
    struct {
        uint8_t segment;
        bool op_size;
        bool addr_size;
        uint8_t rep;
        bool lock;
    } prefix;
    uint8_t buffer[BUF_LEN];
	bool no_operand;
    struct {
        uint8_t opc1;
        uint8_t opc2;
        uint8_t opc3;
    } opcode;
    uint8_t opcode_len;

    bool has_modrm;
    uint8_t modrm;

    bool has_sib;
    uint8_t sib;

    uint32_t disp;
    uint8_t disp_len;

    uint32_t imm;
    uint8_t imm_len;
    uint32_t ip;
    fetch_cb_t fetch;
    void *fetch_user;

    size_t off;

    dec_state_t state;
	dec_state_t resume_state;
    uint8_t imm_read;
    uint8_t disp_read;
	uint8_t group;
    
	uint8_t default_op_size;   
	uint8_t default_addr_size; 
	bool opsz32;
    bool addrsz32;
	
	uint8_t instr_len;  
    uint8_t opcode_map;   /* 0=1b, 1=0f, 2=0f38, 3=0f3a */
    uint8_t opcode_last;  /* final opcode byte */
    int8_t  modrm_ext;    /* /digit or -1 */
    uint8_t mand_pf;      /* UOP_PF_* mask */
    const x86_uop_entry_t *uop_recipe; /* result */ 
    uint32_t far_offset;
    uint16_t far_selector;
};

static inline const opcode_desc_t *
decoder_get_desc(const decoder_t *d)
{
    switch (d->opcode_len)
    {
        case 1:
            return &opcode_1byte[d->opcode.opc2];
        case 2:
            return &opcode_0f[d->opcode.opc2];
        case 3:
            if (d->opcode.opc2 == 0x3A)
            {
                return &opcode_0f3a[d->opcode.opc3];
            }
            else if (d->opcode.opc2 == 0x38) 
            {
                return &opcode_0f38[d->opcode.opc3];    
            }
            
    }
}


decoder_t *decoder_create(void);
void decoder_init(decoder_t *d);

void decoder_reset(decoder_t *d);

void decoder_set_fetch(decoder_t *d, fetch_cb_t cb, void *user);

dec_state_t decoder_step(decoder_t *d, ringbuf_t *r);