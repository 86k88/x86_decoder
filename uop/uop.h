#ifndef UOP_H
#define UOP_H

#include <stdint.h>
#include <stddef.h>

typedef enum {
    UOP_ALU_NONE = 0,
    UOP_ALU_MOV,
    UOP_ALU_XCHG,
    UOP_ALU_LEA,

    UOP_ALU_ADD, UOP_ALU_ADC,
    UOP_ALU_SUB, UOP_ALU_SBB,

    UOP_ALU_AND, UOP_ALU_OR, UOP_ALU_XOR,
    UOP_ALU_CMP, UOP_ALU_TEST,

    UOP_ALU_INC, UOP_ALU_DEC,
    UOP_ALU_NEG, UOP_ALU_NOT,

    UOP_ALU_SHL, UOP_ALU_SHR, UOP_ALU_SAR,
    UOP_ALU_ROL, UOP_ALU_ROR,
    UOP_ALU_RCL, UOP_ALU_RCR,
    UOP_ALU_SHLD, UOP_ALU_SHRD,

    UOP_ALU_MUL, UOP_ALU_IMUL,
    UOP_ALU_DIV, UOP_ALU_IDIV,

    UOP_ALU_BSF, UOP_ALU_BSR,
    UOP_ALU_BT, UOP_ALU_BTC, UOP_ALU_BTS, UOP_ALU_BTR,

    UOP_ALU_BSWAP,
    UOP_ALU_XADD,
    UOP_ALU_CMPXCHG,
} uop_alu_op_t;

typedef enum {
    UOP_CC_NONE = 0,
    UOP_CC_O, UOP_CC_NO,
    UOP_CC_B, UOP_CC_AE,
    UOP_CC_E, UOP_CC_NE,
    UOP_CC_BE, UOP_CC_A,
    UOP_CC_S, UOP_CC_NS,
    UOP_CC_P, UOP_CC_NP,
    UOP_CC_L, UOP_CC_GE,
    UOP_CC_LE, UOP_CC_G,
    UOP_CC_CX_Z,
} uop_cc_t;

typedef enum {
    UOP_REC_NOP = 0,

    UOP_REC_MOV,
    UOP_REC_MOVX,
    UOP_REC_ALU,
    UOP_REC_SHIFT,
    UOP_REC_MULDIV,
    UOP_REC_BIT,
    UOP_REC_BSWAP,
    UOP_REC_XADD,
    UOP_REC_CMPXCHG,
    UOP_REC_HLT,
    UOP_REC_JMP,
    UOP_REC_JCC,
    UOP_REC_LOOP,
    UOP_REC_CALL,
    UOP_REC_RET,
    UOP_REC_SETCC,
    UOP_REC_CMOVCC,

    UOP_REC_STACK,
    UOP_REC_STRING,
    UOP_REC_PORTIO,
    UOP_REC_FLAGS,
    UOP_REC_CTRL,
    UOP_REC_SYSTEM,
    UOP_REC_FPU,
    UOP_REC_SIMD,

    UOP_REC_BCD,
    UOP_REC_MISC,
} uop_recipe_t;
typedef enum {
    UOP_OP_NONE = 0,

    UOP_OP_REG,     // GPR
    UOP_OP_IMM,     // immediate
    UOP_OP_MEM,     // memory operand (EA already computed later)
    UOP_OP_XMM,     // SIMD reg

    UOP_OP_FLAGS,   // flags register
} uop_op_kind_t;
typedef struct {
    uop_op_kind_t kind;

    union {
        uint8_t   reg;     // reg_id_t
        uint32_t  imm;     // immediate value
        struct {
            uint8_t base;  // reg_id_t
            uint8_t index; // reg_id_t
            uint8_t scale;
            int32_t disp;
        } mem;
    };
} uop_operand_t;
const char* uop_alu_op_name(uop_alu_op_t op);
const char* uop_cc_name(uop_cc_t cc);
const char* uop_recipe_name(uop_recipe_t r);

#endif /* UOP_H */
