#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct decoder_s decoder_t;

typedef enum {
    TRACE_PREFIX,
    TRACE_OPCODE,
    TRACE_MODRM,
    TRACE_SIB,
    TRACE_DISP,
    TRACE_IMM,
    TRACE_DONE,
    TRACE_FAULT
} trace_event_t;

typedef void (*trace_cb_t)(
    void *user,
    trace_event_t ev,
    const decoder_t *dec
);


typedef size_t (*fetch_cb_t)(
    void *user,
    uint32_t addr,
    uint8_t *out,
    size_t max_len
);


typedef enum {
	DEC_FETCH,
    DEC_PREFIX,
    DEC_OPCODE,
    DEC_MODRM,
    DEC_SIB,
    DEC_DISP,
    DEC_IMM,
    DEC_DONE,
    DEC_FAULT
} dec_state_t;


#include "opcode_desc.h"
#include "opcode_flags.h"

extern const opcode_desc_t opcode_1byte[256];
extern const opcode_desc_t opcode_0f[256];

struct decoder_s {
    uint8_t bytes[15];
    uint8_t length;

    struct {
        uint8_t segment;
        bool op_size;
        bool addr_size;
        uint8_t rep;
        bool lock;
    } prefix;
	bool no_operand;
    uint16_t opcode;
    uint8_t opcode_bytes;

    bool has_modrm;
    uint8_t modrm;

    bool has_sib;
    uint8_t sib;

    uint32_t disp;
    uint8_t disp_len;
    uint32_t imm;
    uint8_t imm_len;
    fetch_cb_t fetch;
    void *fetch_user;
    uint32_t ip;
    size_t off;

    dec_state_t state;
	dec_state_t resume_state;

	uint8_t group;
    trace_cb_t trace;
    void *trace_user;
	uint8_t default_op_size;   // 16 or 32
	uint8_t default_addr_size; 
	bool opsz32;
    bool addrsz32;
	
	uint8_t instr_len;   
};

static inline const opcode_desc_t *
decoder_get_desc(const decoder_t *d)
{
    if (d->opcode & 0x0F00)
        return &opcode_0f[d->opcode & 0xFF];
    else
        return &opcode_1byte[d->opcode & 0xFF];
}

static inline void trace_emit(decoder_t *d, trace_event_t ev)
{
    if (d->trace)
        d->trace(d->trace_user, ev, d);
}


decoder_t *decoder_create(void);
void decoder_init(decoder_t *d);

void decoder_reset(decoder_t *d, uint32_t ip);

void decoder_set_fetch(decoder_t *d, fetch_cb_t cb, void *user);
void decoder_set_trace(decoder_t *d, trace_cb_t cb, void *user);

bool decoder_step(decoder_t *d);