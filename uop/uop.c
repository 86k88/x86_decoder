#include "uop.h"
#define CASE(x) case x: return #x;

const char* uop_alu_op_name(uop_alu_op_t op) {
    switch (op) {
        CASE(UOP_ALU_NONE)
        CASE(UOP_ALU_MOV)
        CASE(UOP_ALU_XCHG)
        CASE(UOP_ALU_LEA)
        CASE(UOP_ALU_ADD) CASE(UOP_ALU_ADC)
        CASE(UOP_ALU_SUB) CASE(UOP_ALU_SBB)
        CASE(UOP_ALU_AND) CASE(UOP_ALU_OR) CASE(UOP_ALU_XOR)
        CASE(UOP_ALU_CMP) CASE(UOP_ALU_TEST)
        CASE(UOP_ALU_INC) CASE(UOP_ALU_DEC)
        CASE(UOP_ALU_NEG) CASE(UOP_ALU_NOT)
        CASE(UOP_ALU_SHL) CASE(UOP_ALU_SHR) CASE(UOP_ALU_SAR)
        CASE(UOP_ALU_ROL) CASE(UOP_ALU_ROR)
        CASE(UOP_ALU_RCL) CASE(UOP_ALU_RCR)
        CASE(UOP_ALU_SHLD) CASE(UOP_ALU_SHRD)
        CASE(UOP_ALU_MUL) CASE(UOP_ALU_IMUL)
        CASE(UOP_ALU_DIV) CASE(UOP_ALU_IDIV)
        CASE(UOP_ALU_BSF) CASE(UOP_ALU_BSR)
        CASE(UOP_ALU_BT) CASE(UOP_ALU_BTC) CASE(UOP_ALU_BTS) CASE(UOP_ALU_BTR)
        CASE(UOP_ALU_BSWAP)
        CASE(UOP_ALU_XADD)
        CASE(UOP_ALU_CMPXCHG)
    default: return "UOP_ALU_?";
    }
}

const char* uop_cc_name(uop_cc_t cc) {
    switch (cc) {
        CASE(UOP_CC_NONE)
        CASE(UOP_CC_O) CASE(UOP_CC_NO)
        CASE(UOP_CC_B) CASE(UOP_CC_AE)
        CASE(UOP_CC_E) CASE(UOP_CC_NE)
        CASE(UOP_CC_BE) CASE(UOP_CC_A)
        CASE(UOP_CC_S) CASE(UOP_CC_NS)
        CASE(UOP_CC_P) CASE(UOP_CC_NP)
        CASE(UOP_CC_L) CASE(UOP_CC_GE)
        CASE(UOP_CC_LE) CASE(UOP_CC_G)
        CASE(UOP_CC_CX_Z)
    default: return "UOP_CC_?";
    }
}

const char* uop_recipe_name(uop_recipe_t r) {
    switch (r) {
        CASE(UOP_REC_NOP)
        CASE(UOP_REC_MOV)
        CASE(UOP_REC_MOVX)
        CASE(UOP_REC_ALU)
        CASE(UOP_REC_SHIFT)
        CASE(UOP_REC_MULDIV)
        CASE(UOP_REC_BIT)
        CASE(UOP_REC_BSWAP)
        CASE(UOP_REC_XADD)
        CASE(UOP_REC_CMPXCHG)
        CASE(UOP_REC_JMP)
        CASE(UOP_REC_JCC)
        CASE(UOP_REC_LOOP)
        CASE(UOP_REC_CALL)
        CASE(UOP_REC_RET)
        CASE(UOP_REC_SETCC)
        CASE(UOP_REC_CMOVCC)
        CASE(UOP_REC_STACK)
        CASE(UOP_REC_STRING)
        CASE(UOP_REC_PORTIO)
        CASE(UOP_REC_FLAGS)
        CASE(UOP_REC_CTRL)
        CASE(UOP_REC_SYSTEM)
        CASE(UOP_REC_FPU)
        CASE(UOP_REC_SIMD)
        CASE(UOP_REC_BCD)
        CASE(UOP_REC_MISC)
        CASE(UOP_REC_HLT)
    default: return "UOP_REC_?";
    }
}
