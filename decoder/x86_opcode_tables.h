#pragma once
#include "x86_opcode_desc.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const opcode_desc_t opcode_1byte[256];
extern const opcode_desc_t opcode_0f[256];
extern const opcode_desc_t opcode_0f38[256];
extern const opcode_desc_t opcode_0f3a[256];

#ifdef __cplusplus
}
#endif
