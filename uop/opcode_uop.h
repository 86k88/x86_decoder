#ifndef OPCODE_UOP_H
#define OPCODE_UOP_H

#include <stdint.h>
#include <stddef.h>
#include "uop.h"

/*
  Encoding key:
    pf: coder32 mandatory opcode-prefix (0/66/F2/F3)
    op: up to 3 opcode bytes:
      - 1-byte: [xx]
      - 0F map: [0F xx]
      - 0F 38/3A maps: [0F 38 xx] / [0F 3A xx]
    modrm_ext:
      -1  => no ModRM constraint
      -2  => /r (ModRM present)
      0..7=> /digit extension
*/
typedef struct {
    uint8_t pf;
    uint8_t op_len;
    uint8_t op[3];
    int8_t  modrm_ext;
} x86_uop_encoding_t;

typedef struct {
    x86_uop_encoding_t enc;
    uop_recipe_t recipe;
    uop_alu_op_t alu_op;
    uop_cc_t cc;
    const char *mnemonic;
    const char *op1;
    const char *op2;
    const char *op3;
    const char *op4;
    const char *iext;
    const char *notes;
} x86_uop_entry_t;

/*
  Lookup:
    - exact match on pf/op_len/op/modrm_ext
    - if miss and pf is 66/F2/F3, retry with pf=0 ONLY IF this opcode has no pf!=0 variants
    - group families (Jcc, SETcc, CMOVcc, +r reg families) are synthesized first when available
*/
const x86_uop_entry_t* x86_uop_lookup(const x86_uop_encoding_t *k);

size_t x86_uop_entry_count(void);
const x86_uop_entry_t* x86_uop_entry_at(size_t i);

#endif /* OPCODE_UOP_H */
