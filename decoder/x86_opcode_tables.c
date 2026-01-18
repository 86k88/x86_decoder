#include "x86_opcode_tables.h"

const opcode_desc_t opcode_1byte[256] = {
    /* 00 */ { 0x0000000E0F807805 }, /* mnem=ADD; op=r/m; lock; rep */
    /* 01 */ { 0x0000000E0F807805 }, /* mnem=ADD; op=r/m; lock; rep */
    /* 02 */ { 0x0000000E0F807005 }, /* mnem=ADD; op=r/m; rep */
    /* 03 */ { 0x0000000E0F807005 }, /* mnem=ADD; op=r/m; rep */
    /* 04 */ { 0x000002000F802018 }, /* mnem=ADD; op=imm */
    /* 05 */ { 0x000002000F802088 }, /* mnem=ADD; op=imm */
    /* 06 */ { 0x0002000010020000 }, /* mnem=PUSH */
    /* 07 */ { 0x0002000010020000 }, /* mnem=POP */
    /* 08 */ { 0x0000000E0F807805 }, /* mnem=OR; op=r/m; lock; rep */
    /* 09 */ { 0x0000000E0F807805 }, /* mnem=OR; op=r/m; lock; rep */
    /* 0A */ { 0x0000000E0F807005 }, /* mnem=OR; op=r/m; rep */
    /* 0B */ { 0x0000000E0F807005 }, /* mnem=OR; op=r/m; rep */
    /* 0C */ { 0x000002000F802018 }, /* mnem=OR; op=imm */
    /* 0D */ { 0x000002000F802088 }, /* mnem=OR; op=imm */
    /* 0E */ { 0x0002000010020000 }, /* mnem=PUSH */
    /* 0F */ { 0x0002000010020000 }, /* mnem=POP */
    /* 10 */ { 0x0000000E0F807805 }, /* mnem=ADC; op=r/m; lock; rep */
    /* 11 */ { 0x0000000E0F807805 }, /* mnem=ADC; op=r/m; lock; rep */
    /* 12 */ { 0x0000000E0F807005 }, /* mnem=ADC; op=r/m; rep */
    /* 13 */ { 0x0000000E0F807005 }, /* mnem=ADC; op=r/m; rep */
    /* 14 */ { 0x000002000F802018 }, /* mnem=ADC; op=imm */
    /* 15 */ { 0x000002000F802088 }, /* mnem=ADC; op=imm */
    /* 16 */ { 0x0002000010020000 }, /* mnem=PUSH */
    /* 17 */ { 0x0002000010020000 }, /* mnem=POP */
    /* 18 */ { 0x0000000E0F807805 }, /* mnem=SBB; op=r/m; lock; rep */
    /* 19 */ { 0x0000000E0F807805 }, /* mnem=SBB; op=r/m; lock; rep */
    /* 1A */ { 0x0000000E0F807005 }, /* mnem=SBB; op=r/m; rep */
    /* 1B */ { 0x0000000E0F807005 }, /* mnem=SBB; op=r/m; rep */
    /* 1C */ { 0x000002000F802018 }, /* mnem=SBB; op=imm */
    /* 1D */ { 0x000002000F802088 }, /* mnem=SBB; op=imm */
    /* 1E */ { 0x0002000010020000 }, /* mnem=PUSH */
    /* 1F */ { 0x0002000010020000 }, /* mnem=POP */
    /* 20 */ { 0x0000000E0F807805 }, /* mnem=AND; op=r/m; lock; rep */
    /* 21 */ { 0x0000000E0F807805 }, /* mnem=AND; op=r/m; lock; rep */
    /* 22 */ { 0x0000000E0F807005 }, /* mnem=AND; op=r/m; rep */
    /* 23 */ { 0x0000000E0F807005 }, /* mnem=AND; op=r/m; rep */
    /* 24 */ { 0x000002000F802018 }, /* mnem=AND; op=imm */
    /* 25 */ { 0x000002000F802088 }, /* mnem=AND; op=imm */
    /* 26 */ { 0x0002000010000000 }, /* mnem=ES */
    /* 27 */ { 0x000200001F800000 }, /* mnem=DAA */
    /* 28 */ { 0x0000000E0F807805 }, /* mnem=SUB; op=r/m; lock; rep */
    /* 29 */ { 0x0000000E0F807805 }, /* mnem=SUB; op=r/m; lock; rep */
    /* 2A */ { 0x0000000E0F807005 }, /* mnem=SUB; op=r/m; rep */
    /* 2B */ { 0x0000000E0F807005 }, /* mnem=SUB; op=r/m; rep */
    /* 2C */ { 0x000002000F802018 }, /* mnem=SUB; op=imm */
    /* 2D */ { 0x000002000F802088 }, /* mnem=SUB; op=imm */
    /* 2E */ { 0x0002000010000000 }, /* mnem=CS/NTAKEN */
    /* 2F */ { 0x000200001F800000 }, /* mnem=DAS */
    /* 30 */ { 0x0000000E0F807805 }, /* mnem=XOR; op=r/m; lock; rep */
    /* 31 */ { 0x0000000E0F807805 }, /* mnem=XOR; op=r/m; lock; rep */
    /* 32 */ { 0x0000000E0F807005 }, /* mnem=XOR; op=r/m; rep */
    /* 33 */ { 0x0000000E0F807005 }, /* mnem=XOR; op=r/m; rep */
    /* 34 */ { 0x000002000F802018 }, /* mnem=XOR; op=imm */
    /* 35 */ { 0x000002000F802088 }, /* mnem=XOR; op=imm */
    /* 36 */ { 0x0002000010000000 }, /* mnem=SS */
    /* 37 */ { 0x000200001F800000 }, /* mnem=AAA */
    /* 38 */ { 0x0000000E0F807005 }, /* mnem=CMP; op=r/m; rep */
    /* 39 */ { 0x0000000E0F807005 }, /* mnem=CMP; op=r/m; rep */
    /* 3A */ { 0x0000000E0F807005 }, /* mnem=CMP; op=r/m; rep */
    /* 3B */ { 0x0000000E0F807005 }, /* mnem=CMP; op=r/m; rep */
    /* 3C */ { 0x000002000F802018 }, /* mnem=CMP; op=imm */
    /* 3D */ { 0x000002000F802088 }, /* mnem=CMP; op=imm */
    /* 3E */ { 0x0002000010000000 }, /* mnem=DS/TAKEN */
    /* 3F */ { 0x000200001F800000 }, /* mnem=AAS */
    /* 40 */ { 0x000200021F002200 }, /* mnem=INC/REX */
    /* 41 */ { 0x0000000010000000 }, /* mnem=REX.B */
    /* 42 */ { 0x0000000010000000 }, /* mnem=REX.X */
    /* 43 */ { 0x0000000010000000 }, /* mnem=REX.XB */
    /* 44 */ { 0x0000000010000000 }, /* mnem=REX.R */
    /* 45 */ { 0x0000000010000000 }, /* mnem=REX.RB */
    /* 46 */ { 0x0000000010000000 }, /* mnem=REX.RX */
    /* 47 */ { 0x0000000010000000 }, /* mnem=REX.RXB */
    /* 48 */ { 0x000200021F002200 }, /* mnem=DEC/REX.W */
    /* 49 */ { 0x0000000010000000 }, /* mnem=REX.WB */
    /* 4A */ { 0x0000000010000000 }, /* mnem=REX.WX */
    /* 4B */ { 0x0000000010000000 }, /* mnem=REX.WXB */
    /* 4C */ { 0x0000000010000000 }, /* mnem=REX.WR */
    /* 4D */ { 0x0000000010000000 }, /* mnem=REX.WRB */
    /* 4E */ { 0x0000000010000000 }, /* mnem=REX.WRX */
    /* 4F */ { 0x0000000010000000 }, /* mnem=REX.WRXB */
    /* 50 */ { 0x0002000200022200 }, /* mnem=PUSH */
    /* 51 */ { 0x0000000000000000 },
    /* 52 */ { 0x0000000000000000 },
    /* 53 */ { 0x0000000000000000 },
    /* 54 */ { 0x0000000000000000 },
    /* 55 */ { 0x0000000000000000 },
    /* 56 */ { 0x0000000000000000 },
    /* 57 */ { 0x0000000000000000 },
    /* 58 */ { 0x0002000200022200 }, /* mnem=POP */
    /* 59 */ { 0x0000000000000000 },
    /* 5A */ { 0x0000000000000000 },
    /* 5B */ { 0x0000000000000000 },
    /* 5C */ { 0x0000000000000000 },
    /* 5D */ { 0x0000000000000000 },
    /* 5E */ { 0x0000000000000000 },
    /* 5F */ { 0x0000000000000000 },
    /* 60 */ { 0x0002000010020000 }, /* mnem=PUSHA/PUSHAD */
    /* 61 */ { 0x0002000010020000 }, /* mnem=POPA/POPAD */
    /* 62 */ { 0x0002000E10007005 }, /* mnem=BOUND; op=r/m; rep */
    /* 63 */ { 0x0002000E01007005 }, /* mnem=ARPL/MOVSXD; op=r/m; rep */
    /* 64 */ { 0x0002000010000000 }, /* mnem=FS/ALTER */
    /* 65 */ { 0x0002000010000000 }, /* mnem=GS */
    /* 66 */ { 0x0002000010000000 },
    /* 67 */ { 0x0000000010000000 },
    /* 68 */ { 0x0000020000022088 }, /* mnem=PUSH; op=imm */
    /* 69 */ { 0x0000020E0F80708D }, /* mnem=IMUL; op=r/m,imm; rep */
    /* 6A */ { 0x0000020000022018 }, /* mnem=PUSH; op=imm */
    /* 6B */ { 0x0000020E0F80701D }, /* mnem=IMUL; op=r/m,imm; rep */
    /* 6C */ { 0x0000000010009000 }, /* mnem=INS/INSB; string; rep */
    /* 6D */ { 0x0002000010009000 }, /* mnem=INS/INSW/INSD; string; rep */
    /* 6E */ { 0x0000000010009000 }, /* mnem=OUTS/OUTSB; string; rep */
    /* 6F */ { 0x0002000010009000 }, /* mnem=OUTS/OUTSW/OUTSD; string; rep */
    /* 70 */ { 0x0000040000002008 }, /* mnem=JO */
    /* 71 */ { 0x0000040000002008 }, /* mnem=JNO */
    /* 72 */ { 0x0000000010000000 }, /* mnem=JB/JNAE/JC */
    /* 73 */ { 0x0000000010000000 }, /* mnem=JNB/JAE/JNC */
    /* 74 */ { 0x0000000010000000 }, /* mnem=JZ/JE */
    /* 75 */ { 0x0000000010000000 }, /* mnem=JNZ/JNE */
    /* 76 */ { 0x0000000010000000 }, /* mnem=JBE/JNA */
    /* 77 */ { 0x0000000010000000 }, /* mnem=JNBE/JA */
    /* 78 */ { 0x0000040000002008 }, /* mnem=JS */
    /* 79 */ { 0x0000040000002008 }, /* mnem=JNS */
    /* 7A */ { 0x0000000010000000 }, /* mnem=JP/JPE */
    /* 7B */ { 0x0000000010000000 }, /* mnem=JNP/JPO */
    /* 7C */ { 0x0000000010000000 }, /* mnem=JL/JNGE */
    /* 7D */ { 0x0000000010000000 }, /* mnem=JNL/JGE */
    /* 7E */ { 0x0000000010000000 }, /* mnem=JLE/JNG */
    /* 7F */ { 0x0000000010000000 }, /* mnem=JNLE/JG */
    /* 80 */ { 0x03FE020C0F80691D }, /* mnem=ADD/OR/ADC; ext=/0,/1,/2,/3,/4,/5,/6,/7; op=r/m,imm; lock */
    /* 81 */ { 0x03FE020C0F80698D }, /* mnem=ADD/OR/ADC; ext=/0,/1,/2,/3,/4,/5,/6,/7; op=r/m,imm; lock */
    /* 82 */ { 0x03FE020C1F80691D }, /* mnem=ADD/OR/ADC; ext=/0,/1,/2,/3,/4,/5,/6,/7; op=r/m,imm; lock */
    /* 83 */ { 0x03FE020C0F80691D }, /* mnem=ADD/OR/ADC; ext=/0,/1,/2,/3,/4,/5,/6,/7; op=r/m,imm; lock */
    /* 84 */ { 0x0000000E0F807005 }, /* mnem=TEST; op=r/m; rep */
    /* 85 */ { 0x0000000E0F807005 }, /* mnem=TEST; op=r/m; rep */
    /* 86 */ { 0x0000000E00007805 }, /* mnem=XCHG; op=r/m; lock; rep */
    /* 87 */ { 0x0000000E00007805 }, /* mnem=XCHG; op=r/m; lock; rep */
    /* 88 */ { 0x0000000E00007005 }, /* mnem=MOV; op=r/m; rep */
    /* 89 */ { 0x0000000E00007005 }, /* mnem=MOV; op=r/m; rep */
    /* 8A */ { 0x0000000E00007005 }, /* mnem=MOV; op=r/m; rep */
    /* 8B */ { 0x0000000E00007005 }, /* mnem=MOV; op=r/m; rep */
    /* 8C */ { 0x0000000010001000 }, /* mnem=MOV; rep */
    /* 8D */ { 0x0000000E00007005 }, /* mnem=LEA; op=r/m; rep */
    /* 8E */ { 0x0000000C00007005 }, /* mnem=MOV; op=r/m; rep */
    /* 8F */ { 0x0006000C00026105 }, /* mnem=POP; ext=/0; op=r/m */
    /* 90 */ { 0x0002800210012200 }, /* mnem=XCHG/NOP/PAUSE; mand=F3 */
    /* 91 */ { 0x0000000000000000 },
    /* 92 */ { 0x0000000000000000 },
    /* 93 */ { 0x0000000000000000 },
    /* 94 */ { 0x0000000000000000 },
    /* 95 */ { 0x0000000000000000 },
    /* 96 */ { 0x0000000000000000 },
    /* 97 */ { 0x0000000000000000 },
    /* 98 */ { 0x0002000010000000 }, /* mnem=CBW/CWDE/CDQE */
    /* 99 */ { 0x0002000010000000 }, /* mnem=CWD/CDQ/CQO */
    /* 9A */ { 0x0002100050002008 }, /* mnem=CALLF; op=far */
    /* 9B */ { 0x0002000010010000 }, /* mnem=FWAIT/WAIT */
    /* 9C */ { 0x0002000010020000 }, /* mnem=PUSHF/PUSHFD/PUSHFQ */
    /* 9D */ { 0x0002000010020000 }, /* mnem=POPF/POPFD/POPFQ */
    /* 9E */ { 0x000000001B800000 }, /* mnem=SAHF */
    /* 9F */ { 0x0000000010000000 }, /* mnem=LAHF */
    /* A0 */ { 0x0000080080004004 }, /* mnem=MOV; op=moffs */
    /* A1 */ { 0x0000080080004004 }, /* mnem=MOV; op=moffs */
    /* A2 */ { 0x0000080080004004 }, /* mnem=MOV; op=moffs */
    /* A3 */ { 0x0000080080004004 }, /* mnem=MOV; op=moffs */
    /* A4 */ { 0x0000000010009000 }, /* mnem=MOVS/MOVSB; string; rep */
    /* A5 */ { 0x0002000010009000 }, /* mnem=MOVS/MOVSW/MOVSD; string; rep */
    /* A6 */ { 0x000000001F809000 }, /* mnem=CMPS/CMPSB; string; rep */
    /* A7 */ { 0x000200001F809000 }, /* mnem=CMPS/CMPSW/CMPSD; string; rep */
    /* A8 */ { 0x000002000F802018 }, /* mnem=TEST; op=imm */
    /* A9 */ { 0x000002000F802088 }, /* mnem=TEST; op=imm */
    /* AA */ { 0x0000000010009000 }, /* mnem=STOS/STOSB; string; rep */
    /* AB */ { 0x0002000010009000 }, /* mnem=STOS/STOSW/STOSD; string; rep */
    /* AC */ { 0x0000000010009000 }, /* mnem=LODS/LODSB; string; rep */
    /* AD */ { 0x0002000010009000 }, /* mnem=LODS/LODSW/LODSD; string; rep */
    /* AE */ { 0x000000001F809000 }, /* mnem=SCAS/SCASB; string; rep */
    /* AF */ { 0x000200001F809000 }, /* mnem=SCAS/SCASW/SCASD; string; rep */
    /* B0 */ { 0x0000020200002218 }, /* mnem=MOV; op=imm */
    /* B1 */ { 0x0000020200002218 },
    /* B2 */ { 0x0000020200002218 },
    /* B3 */ { 0x0000020200002218 },
    /* B4 */ { 0x0000020200002218 },
    /* B5 */ { 0x0000020200002218 },
    /* B6 */ { 0x0000020200002218 },
    /* B7 */ { 0x0000020200002218 },
    /* B8 */ { 0x0000020200002288 }, /* mnem=MOV; op=imm */
    /* B9 */ { 0x0000020200002288 },
    /* BA */ { 0x0000020200002288 },
    /* BB */ { 0x0000020200002288 },
    /* BC */ { 0x0000020200002288 },
    /* BD */ { 0x0000020200002288 },
    /* BE */ { 0x0000020200002288 },
    /* BF */ { 0x0000020200002288 },
    /* C0 */ { 0x03FE020C1F80611D }, /* mnem=ROL/ROR/RCL; ext=/0,/1,/2,/3,/4,/5,/6,/7; op=r/m,imm */
    /* C1 */ { 0x03FE020C1F80611D }, /* mnem=ROL/ROR/RCL; ext=/0,/1,/2,/3,/4,/5,/6,/7; op=r/m,imm */
    /* C2 */ { 0x0000020000002028 }, /* mnem=RETN; op=imm */
    /* C3 */ { 0x0000000010000000 }, /* mnem=RETN */
    /* C4 */ { 0x0002000E10007005 }, /* mnem=LES; op=r/m; rep */
    /* C5 */ { 0x0002000E10007005 }, /* mnem=LDS; op=r/m; rep */
    /* C6 */ { 0x0004020C0000611D }, /* mnem=MOV; ext=/0; op=r/m,imm */
    /* C7 */ { 0x0004020C0000618D }, /* mnem=MOV; ext=/0; op=r/m,imm */
    /* C8 */ { 0x0002020020022038 }, /* mnem=ENTER; op=imm */
    /* C9 */ { 0x0002000010020000 }, /* mnem=LEAVE */
    /* CA */ { 0x0000020000012028 }, /* mnem=RETF; op=imm */
    /* CB */ { 0x0000000010010000 }, /* mnem=RETF */
    /* CC */ { 0x0000000010010000 }, /* mnem=INT */
    /* CD */ { 0x0000020000012018 }, /* mnem=INT; op=imm */
    /* CE */ { 0x0000000010010000 }, /* mnem=INTO */
    /* CF */ { 0x0002000010010000 }, /* mnem=IRET/IRETD/IRETQ */
    /* D0 */ { 0x03FE000C1F806105 }, /* mnem=ROL/ROR/RCL; ext=/0,/1,/2,/3,/4,/5,/6,/7; op=r/m */
    /* D1 */ { 0x03FE000C1F806105 }, /* mnem=ROL/ROR/RCL; ext=/0,/1,/2,/3,/4,/5,/6,/7; op=r/m */
    /* D2 */ { 0x03FE000C1F806105 }, /* mnem=ROL/ROR/RCL; ext=/0,/1,/2,/3,/4,/5,/6,/7; op=r/m */
    /* D3 */ { 0x03FE000C1F806105 }, /* mnem=ROL/ROR/RCL; ext=/0,/1,/2,/3,/4,/5,/6,/7; op=r/m */
    /* D4 */ { 0x000202001F802018 }, /* mnem=AAM/AMX; op=imm */
    /* D5 */ { 0x000202001F802018 }, /* mnem=AAD/ADX; op=imm */
    /* D6 */ { 0x0002000010000000 }, /* mnem=SALC/SETALC */
    /* D7 */ { 0x0000000010000000 }, /* mnem=XLAT/XLATB */
    /* D8 */ { 0x03FE000010000101 }, /* mnem=FADD/FMUL/FCOM; ext=/0,/1,/2,/3,/4,/5,/6,/7 */
    /* D9 */ { 0x03FF000C10016105 }, /* mnem=FLD/FXCH/FST; mand=9B; ext=/0,/1,/2,/3,/4,/5,/6,/7; op=r/m */
    /* DA */ { 0x03FE000C10006105 }, /* mnem=FIADD/FCMOVB/FIMUL; ext=/0,/1,/2,/3,/4,/5,/6,/7; op=r/m */
    /* DB */ { 0x03FF000C1D816105 }, /* mnem=FILD/FCMOVNB/FISTTP; mand=9B; ext=/0,/1,/2,/3,/4,/5,/6,/7; op=r/m */
    /* DC */ { 0x03FE000C00006105 }, /* mnem=FADD/FMUL/FCOM; ext=/0,/1,/2,/3,/4,/5,/6,/7; op=r/m */
    /* DD */ { 0x03FF010C10016105 }, /* mnem=FLD/FFREE/FISTTP; mand=9B; ext=/0,/1,/2,/3,/4,/5,/6,/7; op=r/m */
    /* DE */ { 0x03FE000C10006105 }, /* mnem=FIADD/FADDP/FIMUL; ext=/0,/1,/2,/3,/4,/5,/6,/7; op=r/m */
    /* DF */ { 0x03FF000C1D816105 }, /* mnem=FILD/FFREEP/FISTTP; mand=9B; ext=/0,/1,/2,/3,/4,/5,/6,/7; op=r/m */
    /* E0 */ { 0x0002000010010000 }, /* mnem=LOOPNZ/LOOPNE */
    /* E1 */ { 0x0002000010010000 }, /* mnem=LOOPZ/LOOPE */
    /* E2 */ { 0x0002040000012008 }, /* mnem=LOOP */
    /* E3 */ { 0x0002000010010000 }, /* mnem=JCXZ/JECXZ/JRCXZ */
    /* E4 */ { 0x0000020000002018 }, /* mnem=IN; op=imm */
    /* E5 */ { 0x0000020000002018 }, /* mnem=IN; op=imm */
    /* E6 */ { 0x0000020000002018 }, /* mnem=OUT; op=imm */
    /* E7 */ { 0x0000020000002018 }, /* mnem=OUT; op=imm */
    /* E8 */ { 0x0000040000012008 }, /* mnem=CALL */
    /* E9 */ { 0x0000040000012008 }, /* mnem=JMP */
    /* EA */ { 0x0002100050002028 }, /* mnem=JMPF; op=far */
    /* EB */ { 0x0000040000012008 }, /* mnem=JMP */
    /* EC */ { 0x0000000010000000 }, /* mnem=IN */
    /* ED */ { 0x0000000010000000 }, /* mnem=IN */
    /* EE */ { 0x0000000010000000 }, /* mnem=OUT */
    /* EF */ { 0x0000000010000000 }, /* mnem=OUT */
    /* F0 */ { 0x0000000010000000 }, /* mnem=LOCK */
    /* F1 */ { 0x0002000010000000 }, /* mnem=INT1/ICEBP */
    /* F2 */ { 0x0002000010000000 }, /* mnem=REPNZ/REPNE/REP */
    /* F3 */ { 0x0002000010000000 }, /* mnem=REPZ/REPE/REP */
    /* F4 */ { 0x0000000010000000 }, /* mnem=HLT */
    /* F5 */ { 0x0000000010800000 }, /* mnem=CMC */
    /* F6 */ { 0x03FE020C0F80611D }, /* mnem=TEST/NOT/NEG; ext=/0,/1,/2,/3,/4,/5,/6,/7; op=r/m,imm */
    /* F7 */ { 0x03FE020C0F80618D }, /* mnem=TEST/NOT/NEG; ext=/0,/1,/2,/3,/4,/5,/6,/7; op=r/m,imm */
    /* F8 */ { 0x0000000010800000 }, /* mnem=CLC */
    /* F9 */ { 0x0000000010800000 }, /* mnem=STC */
    /* FA */ { 0x0000000010000000 }, /* mnem=CLI */
    /* FB */ { 0x0000000010000000 }, /* mnem=STI */
    /* FC */ { 0x0000000010000000 }, /* mnem=CLD */
    /* FD */ { 0x0000000010000000 }, /* mnem=STD */
    /* FE */ { 0x000E000C0F006105 }, /* mnem=INC/DEC; ext=/0,/1; op=r/m */
    /* FF */ { 0x01FE000C0F036105 }, /* mnem=INC/DEC/CALL; ext=/0,/1,/2,/3,/4,/5,/6; op=r/m */
};

const opcode_desc_t opcode_0f[256] = {
    /* 00 */ { 0x01FE000C11006505 }, /* mnem=SLDT/STR/LLDT; ext=/0,/1,/2,/3,/4,/5,/6; op=r/m */
    /* 01 */ { 0x037E000C1F806505 }, /* mnem=SGDT/VMCALL/VMLAUNCH; ext=/0,/1,/2,/3,/4,/6,/7; op=r/m */
    /* 02 */ { 0x0000000011001400 }, /* mnem=LAR; rep */
    /* 03 */ { 0x0000000011001400 }, /* mnem=LSL; rep */
    /* 04 */ { 0x0000000000000000 },
    /* 05 */ { 0x0002000010010400 }, /* mnem=LOADALL/SYSCALL */
    /* 06 */ { 0x0000000010000400 }, /* mnem=CLTS */
    /* 07 */ { 0x0002000010010400 }, /* mnem=LOADALL/SYSRET */
    /* 08 */ { 0x0000000010000400 }, /* mnem=INVD */
    /* 09 */ { 0x0000000010000400 }, /* mnem=WBINVD */
    /* 0A */ { 0x0000000000000000 },
    /* 0B */ { 0x0000000010010400 }, /* mnem=UD2 */
    /* 0C */ { 0x0000000000000000 },
    /* 0D */ { 0x0000000C00016405 }, /* mnem=NOP; op=r/m */
    /* 0E */ { 0x0000000000000000 },
    /* 0F */ { 0x0000000000000000 },
    /* 10 */ { 0x0002E01C0000F405 }, /* mnem=MOVUPS/MOVSS/MOVUPD; mand=66,F2,F3; op=r/m,xmm; string; rep */
    /* 11 */ { 0x0002E01C0000F405 }, /* mnem=MOVUPS/MOVSS/MOVUPD; mand=66,F2,F3; op=r/m,xmm; string; rep */
    /* 12 */ { 0x0002E01C00007405 }, /* mnem=MOVHLPS/MOVLPS/MOVLPD; mand=66,F2,F3; op=r/m,xmm; rep */
    /* 13 */ { 0x0002201C00007405 }, /* mnem=MOVLPS/MOVLPD; mand=66; op=r/m,xmm; rep */
    /* 14 */ { 0x0002201C00007405 }, /* mnem=UNPCKLPS/UNPCKLPD; mand=66; op=r/m,xmm; rep */
    /* 15 */ { 0x0002201C00007405 }, /* mnem=UNPCKHPS/UNPCKHPD; mand=66; op=r/m,xmm; rep */
    /* 16 */ { 0x0002A01C00007405 }, /* mnem=MOVLHPS/MOVHPS/MOVHPD; mand=66,F3; op=r/m,xmm; rep */
    /* 17 */ { 0x0002201C00007405 }, /* mnem=MOVHPS/MOVHPD; mand=66; op=r/m,xmm; rep */
    /* 18 */ { 0x03FE000C00016505 }, /* mnem=HINT_NOP/PREFETCHNTA/PREFETCHT0; ext=/0,/1,/2,/3,/4,/5,/6,/7; op=r/m */
    /* 19 */ { 0x0000000C00016405 }, /* mnem=HINT_NOP; op=r/m */
    /* 1A */ { 0x0000000C00016405 }, /* mnem=HINT_NOP; op=r/m */
    /* 1B */ { 0x0000000C00016405 }, /* mnem=HINT_NOP; op=r/m */
    /* 1C */ { 0x0000000C00016405 }, /* mnem=HINT_NOP; op=r/m */
    /* 1D */ { 0x0000000C00016405 }, /* mnem=HINT_NOP; op=r/m */
    /* 1E */ { 0x0000000C00016405 }, /* mnem=HINT_NOP; op=r/m */
    /* 1F */ { 0x03FE000C00016505 }, /* mnem=HINT_NOP/NOP; ext=/0,/1,/2,/3,/4,/5,/6,/7; op=r/m */
    /* 20 */ { 0x0002000A0F803401 }, /* mnem=MOV; op=r/m; rep */
    /* 21 */ { 0x0002000A0F803401 }, /* mnem=MOV; op=r/m; rep */
    /* 22 */ { 0x0002000A0F803401 }, /* mnem=MOV; op=r/m; rep */
    /* 23 */ { 0x0002000A0F803401 }, /* mnem=MOV; op=r/m; rep */
    /* 24 */ { 0x0002000A0F803401 }, /* mnem=MOV; op=r/m; rep */
    /* 25 */ { 0x0000000000000000 },
    /* 26 */ { 0x0002000A0F803401 }, /* mnem=MOV; op=r/m; rep */
    /* 27 */ { 0x0000000000000000 },
    /* 28 */ { 0x0002201C00007405 }, /* mnem=MOVAPS/MOVAPD; mand=66; op=r/m,xmm; rep */
    /* 29 */ { 0x0002201C00007405 }, /* mnem=MOVAPS/MOVAPD; mand=66; op=r/m,xmm; rep */
    /* 2A */ { 0x0002E09C00007405 }, /* mnem=CVTPI2PS/CVTSI2SS/CVTPI2PD; mand=66,F2,F3; op=r/m,xmm; rep */
    /* 2B */ { 0x0002201C00007405 }, /* mnem=MOVNTPS/MOVNTPD; mand=66; op=r/m,xmm; rep */
    /* 2C */ { 0x0002E09E00007405 }, /* mnem=CVTTPS2PI/CVTTSS2SI/CVTTPD2PI; mand=66,F2,F3; op=r/m,xmm; rep */
    /* 2D */ { 0x0002E09E00007405 }, /* mnem=CVTPS2PI/CVTSS2SI/CVTPD2PI; mand=66,F2,F3; op=r/m,xmm; rep */
    /* 2E */ { 0x0002201C09807405 }, /* mnem=UCOMISS/UCOMISD; mand=66; op=r/m,xmm; rep */
    /* 2F */ { 0x0002201C09807405 }, /* mnem=COMISS/COMISD; mand=66; op=r/m,xmm; rep */
    /* 30 */ { 0x0000000010000400 }, /* mnem=WRMSR */
    /* 31 */ { 0x0000000010000400 }, /* mnem=RDTSC */
    /* 32 */ { 0x0000000010000400 }, /* mnem=RDMSR */
    /* 33 */ { 0x0000000010000400 }, /* mnem=RDPMC */
    /* 34 */ { 0x0002000010010400 }, /* mnem=SYSENTER */
    /* 35 */ { 0x0000000010010400 }, /* mnem=SYSEXIT */
    /* 36 */ { 0x0000000000000000 },
    /* 37 */ { 0x0000000010000400 }, /* mnem=GETSEC */
    /* 38 */ { 0x0000000000000000 },
    /* 39 */ { 0x0000000000000000 },
    /* 3A */ { 0x0000000000000000 },
    /* 3B */ { 0x0000000000000000 },
    /* 3C */ { 0x0000000000000000 },
    /* 3D */ { 0x0000000000000000 },
    /* 3E */ { 0x0000000000000000 },
    /* 3F */ { 0x0000000000000000 },
    /* 40 */ { 0x0000000E00007405 }, /* mnem=CMOVO; op=r/m; rep */
    /* 41 */ { 0x0000000E00007405 }, /* mnem=CMOVNO; op=r/m; rep */
    /* 42 */ { 0x0000000010001400 }, /* mnem=CMOVB/CMOVNAE/CMOVC; rep */
    /* 43 */ { 0x0000000010001400 }, /* mnem=CMOVNB/CMOVAE/CMOVNC; rep */
    /* 44 */ { 0x0000000010001400 }, /* mnem=CMOVZ/CMOVE; rep */
    /* 45 */ { 0x0000000010001400 }, /* mnem=CMOVNZ/CMOVNE; rep */
    /* 46 */ { 0x0000000010001400 }, /* mnem=CMOVBE/CMOVNA; rep */
    /* 47 */ { 0x0000000010001400 }, /* mnem=CMOVNBE/CMOVA; rep */
    /* 48 */ { 0x0000000E00007405 }, /* mnem=CMOVS; op=r/m; rep */
    /* 49 */ { 0x0000000E00007405 }, /* mnem=CMOVNS; op=r/m; rep */
    /* 4A */ { 0x0000000010001400 }, /* mnem=CMOVP/CMOVPE; rep */
    /* 4B */ { 0x0000000010001400 }, /* mnem=CMOVNP/CMOVPO; rep */
    /* 4C */ { 0x0000000010001400 }, /* mnem=CMOVL/CMOVNGE; rep */
    /* 4D */ { 0x0000000010001400 }, /* mnem=CMOVNL/CMOVGE; rep */
    /* 4E */ { 0x0000000010001400 }, /* mnem=CMOVLE/CMOVNG; rep */
    /* 4F */ { 0x0000000010001400 }, /* mnem=CMOVNLE/CMOVG; rep */
    /* 50 */ { 0x0002201A00003401 }, /* mnem=MOVMSKPS/MOVMSKPD; mand=66; op=r/m,xmm; rep */
    /* 51 */ { 0x0002E01C00007405 }, /* mnem=SQRTPS/SQRTSS/SQRTPD; mand=66,F2,F3; op=r/m,xmm; rep */
    /* 52 */ { 0x0002801C00007405 }, /* mnem=RSQRTPS/RSQRTSS; mand=F3; op=r/m,xmm; rep */
    /* 53 */ { 0x0002801C00007405 }, /* mnem=RCPPS/RCPSS; mand=F3; op=r/m,xmm; rep */
    /* 54 */ { 0x0002201C00007405 }, /* mnem=ANDPS/ANDPD; mand=66; op=r/m,xmm; rep */
    /* 55 */ { 0x0002201C00007405 }, /* mnem=ANDNPS/ANDNPD; mand=66; op=r/m,xmm; rep */
    /* 56 */ { 0x0002201C00007405 }, /* mnem=ORPS/ORPD; mand=66; op=r/m,xmm; rep */
    /* 57 */ { 0x0002201C00007405 }, /* mnem=XORPS/XORPD; mand=66; op=r/m,xmm; rep */
    /* 58 */ { 0x0002E01C00007405 }, /* mnem=ADDPS/ADDSS/ADDPD; mand=66,F2,F3; op=r/m,xmm; rep */
    /* 59 */ { 0x0002E01C00007405 }, /* mnem=MULPS/MULSS/MULPD; mand=66,F2,F3; op=r/m,xmm; rep */
    /* 5A */ { 0x0002E01C00007405 }, /* mnem=CVTPS2PD/CVTPD2PS/CVTSS2SD; mand=66,F2,F3; op=r/m,xmm; rep */
    /* 5B */ { 0x0002A01C00007405 }, /* mnem=CVTDQ2PS/CVTPS2DQ/CVTTPS2DQ; mand=66,F3; op=r/m,xmm; rep */
    /* 5C */ { 0x0002E01C00007405 }, /* mnem=SUBPS/SUBSS/SUBPD; mand=66,F2,F3; op=r/m,xmm; rep */
    /* 5D */ { 0x0002E01C00007405 }, /* mnem=MINPS/MINSS/MINPD; mand=66,F2,F3; op=r/m,xmm; rep */
    /* 5E */ { 0x0002E01C00007405 }, /* mnem=DIVPS/DIVSS/DIVPD; mand=66,F2,F3; op=r/m,xmm; rep */
    /* 5F */ { 0x0002E01C00007405 }, /* mnem=MAXPS/MAXSS/MAXPD; mand=66,F2,F3; op=r/m,xmm; rep */
    /* 60 */ { 0x0002209C00007405 }, /* mnem=PUNPCKLBW; mand=66; op=r/m,xmm; rep */
    /* 61 */ { 0x0002209C00007405 }, /* mnem=PUNPCKLWD; mand=66; op=r/m,xmm; rep */
    /* 62 */ { 0x0002209C00007405 }, /* mnem=PUNPCKLDQ; mand=66; op=r/m,xmm; rep */
    /* 63 */ { 0x0002209C00007405 }, /* mnem=PACKSSWB; mand=66; op=r/m,xmm; rep */
    /* 64 */ { 0x0002209C00007405 }, /* mnem=PCMPGTB; mand=66; op=r/m,xmm; rep */
    /* 65 */ { 0x0002209C00007405 }, /* mnem=PCMPGTW; mand=66; op=r/m,xmm; rep */
    /* 66 */ { 0x0002209C00007405 }, /* mnem=PCMPGTD; mand=66; op=r/m,xmm; rep */
    /* 67 */ { 0x0002209C00007405 }, /* mnem=PACKUSWB; mand=66; op=r/m,xmm; rep */
    /* 68 */ { 0x0002209C00007405 }, /* mnem=PUNPCKHBW; mand=66; op=r/m,xmm; rep */
    /* 69 */ { 0x0002209C00007405 }, /* mnem=PUNPCKHWD; mand=66; op=r/m,xmm; rep */
    /* 6A */ { 0x0002209C00007405 }, /* mnem=PUNPCKHDQ; mand=66; op=r/m,xmm; rep */
    /* 6B */ { 0x0002209C00007405 }, /* mnem=PACKSSDW; mand=66; op=r/m,xmm; rep */
    /* 6C */ { 0x0000201C00007405 }, /* mnem=PUNPCKLQDQ; mand=66; op=r/m,xmm; rep */
    /* 6D */ { 0x0000201C00007405 }, /* mnem=PUNPCKHQDQ; mand=66; op=r/m,xmm; rep */
    /* 6E */ { 0x0002209C10007405 }, /* mnem=MOVD/MOVQ; mand=66; op=r/m,xmm; rep */
    /* 6F */ { 0x0002A09C00007405 }, /* mnem=MOVQ/MOVDQA/MOVDQU; mand=66,F3; op=r/m,xmm; rep */
    /* 70 */ { 0x0002E29C0000741D }, /* mnem=PSHUFW/PSHUFLW/PSHUFHW; mand=66,F2,F3; op=r/m,xmm,imm; rep */
    /* 71 */ { 0x0152229800002519 }, /* mnem=PSRLW/PSRAW/PSLLW; mand=66; ext=/2,/4,/6; op=r/m,xmm,imm */
    /* 72 */ { 0x0152229800002519 }, /* mnem=PSRLD/PSRAD/PSLLD; mand=66; ext=/2,/4,/6; op=r/m,xmm,imm */
    /* 73 */ { 0x0332229800002519 }, /* mnem=PSRLQ/PSRLDQ/PSLLQ; mand=66; ext=/2,/3,/6,/7; op=r/m,xmm,imm */
    /* 74 */ { 0x0002209C00007405 }, /* mnem=PCMPEQB; mand=66; op=r/m,xmm; rep */
    /* 75 */ { 0x0002209C00007405 }, /* mnem=PCMPEQW; mand=66; op=r/m,xmm; rep */
    /* 76 */ { 0x0002209C00007405 }, /* mnem=PCMPEQD; mand=66; op=r/m,xmm; rep */
    /* 77 */ { 0x0000000010010400 }, /* mnem=EMMS */
    /* 78 */ { 0x0002000E0F807405 }, /* mnem=VMREAD; op=r/m; rep */
    /* 79 */ { 0x0002000E0F807405 }, /* mnem=VMWRITE; op=r/m; rep */
    /* 7A */ { 0x0000000000000000 },
    /* 7B */ { 0x0000000000000000 },
    /* 7C */ { 0x0002601C00007405 }, /* mnem=HADDPD/HADDPS; mand=66,F2; op=r/m,xmm; rep */
    /* 7D */ { 0x0002601C00007405 }, /* mnem=HSUBPD/HSUBPS; mand=66,F2; op=r/m,xmm; rep */
    /* 7E */ { 0x0002A09C10007405 }, /* mnem=MOVD/MOVQ; mand=66,F3; op=r/m,xmm; rep */
    /* 7F */ { 0x0002A09C00007405 }, /* mnem=MOVQ/MOVDQA/MOVDQU; mand=66,F3; op=r/m,xmm; rep */
    /* 80 */ { 0x0000040000002408 }, /* mnem=JO */
    /* 81 */ { 0x0000040000002408 }, /* mnem=JNO */
    /* 82 */ { 0x0000000010000400 }, /* mnem=JB/JNAE/JC */
    /* 83 */ { 0x0000000010000400 }, /* mnem=JNB/JAE/JNC */
    /* 84 */ { 0x0000000010000400 }, /* mnem=JZ/JE */
    /* 85 */ { 0x0000000010000400 }, /* mnem=JNZ/JNE */
    /* 86 */ { 0x0000000010000400 }, /* mnem=JBE/JNA */
    /* 87 */ { 0x0000000010000400 }, /* mnem=JNBE/JA */
    /* 88 */ { 0x0000040000002408 }, /* mnem=JS */
    /* 89 */ { 0x0000040000002408 }, /* mnem=JNS */
    /* 8A */ { 0x0000000010000400 }, /* mnem=JP/JPE */
    /* 8B */ { 0x0000000010000400 }, /* mnem=JNP/JPO */
    /* 8C */ { 0x0000000010000400 }, /* mnem=JL/JNGE */
    /* 8D */ { 0x0000000010000400 }, /* mnem=JNL/JGE */
    /* 8E */ { 0x0000000010000400 }, /* mnem=JLE/JNG */
    /* 8F */ { 0x0000000010000400 }, /* mnem=JNLE/JG */
    /* 90 */ { 0x0004000C00006505 }, /* mnem=SETO; ext=/0; op=r/m */
    /* 91 */ { 0x0004000C00006505 }, /* mnem=SETNO; ext=/0; op=r/m */
    /* 92 */ { 0x0004000010000501 }, /* mnem=SETB/SETNAE/SETC; ext=/0 */
    /* 93 */ { 0x0004000010000501 }, /* mnem=SETNB/SETAE/SETNC; ext=/0 */
    /* 94 */ { 0x0004000010000501 }, /* mnem=SETZ/SETE; ext=/0 */
    /* 95 */ { 0x0004000010000501 }, /* mnem=SETNZ/SETNE; ext=/0 */
    /* 96 */ { 0x0004000010000501 }, /* mnem=SETBE/SETNA; ext=/0 */
    /* 97 */ { 0x0004000010000501 }, /* mnem=SETNBE/SETA; ext=/0 */
    /* 98 */ { 0x0004000C00006505 }, /* mnem=SETS; ext=/0; op=r/m */
    /* 99 */ { 0x0004000C00006505 }, /* mnem=SETNS; ext=/0; op=r/m */
    /* 9A */ { 0x0004000010000501 }, /* mnem=SETP/SETPE; ext=/0 */
    /* 9B */ { 0x0004000010000501 }, /* mnem=SETNP/SETPO; ext=/0 */
    /* 9C */ { 0x0004000010000501 }, /* mnem=SETL/SETNGE; ext=/0 */
    /* 9D */ { 0x0004000010000501 }, /* mnem=SETNL/SETGE; ext=/0 */
    /* 9E */ { 0x0004000010000501 }, /* mnem=SETLE/SETNG; ext=/0 */
    /* 9F */ { 0x0004000010000501 }, /* mnem=SETNLE/SETG; ext=/0 */
    /* A0 */ { 0x0000000010020400 }, /* mnem=PUSH */
    /* A1 */ { 0x0000000010020400 }, /* mnem=POP */
    /* A2 */ { 0x0000000010010400 }, /* mnem=CPUID */
    /* A3 */ { 0x0000000E0F807405 }, /* mnem=BT; op=r/m; rep */
    /* A4 */ { 0x0000020E0F80741D }, /* mnem=SHLD; op=r/m,imm; rep */
    /* A5 */ { 0x0000000E0F807405 }, /* mnem=SHLD; op=r/m; rep */
    /* A6 */ { 0x0000000000000000 },
    /* A7 */ { 0x0000000000000000 },
    /* A8 */ { 0x0000000010020400 }, /* mnem=PUSH */
    /* A9 */ { 0x0000000010020400 }, /* mnem=POP */
    /* AA */ { 0x0000000010000400 }, /* mnem=RSM */
    /* AB */ { 0x0000000E0F807C05 }, /* mnem=BTS; op=r/m; lock; rep */
    /* AC */ { 0x0000020E0F80741D }, /* mnem=SHRD; op=r/m,imm; rep */
    /* AD */ { 0x0000000E0F807405 }, /* mnem=SHRD; op=r/m; rep */
    /* AE */ { 0x03FE000C10006505 }, /* mnem=FXSAVE/FXRSTOR/LDMXCSR; ext=/0,/1,/2,/3,/4,/5,/6,/7; op=r/m */
    /* AF */ { 0x0000000E0F807405 }, /* mnem=IMUL; op=r/m; rep */
    /* B0 */ { 0x0000000E0F807C05 }, /* mnem=CMPXCHG; op=r/m; lock; rep */
    /* B1 */ { 0x0000000E0F807C05 }, /* mnem=CMPXCHG; op=r/m; lock; rep */
    /* B2 */ { 0x0000000E00007405 }, /* mnem=LSS; op=r/m; rep */
    /* B3 */ { 0x0000000E0F807C05 }, /* mnem=BTR; op=r/m; lock; rep */
    /* B4 */ { 0x0000000E00007405 }, /* mnem=LFS; op=r/m; rep */
    /* B5 */ { 0x0000000E00007405 }, /* mnem=LGS; op=r/m; rep */
    /* B6 */ { 0x0000000E00007405 }, /* mnem=MOVZX; op=r/m; rep */
    /* B7 */ { 0x0000000E00007405 }, /* mnem=MOVZX; op=r/m; rep */
    /* B8 */ { 0x0002800E1F807405 }, /* mnem=JMPE/POPCNT; mand=F3; op=r/m; rep */
    /* B9 */ { 0x0000000E00017405 }, /* mnem=UD; op=r/m; rep */
    /* BA */ { 0x03C2020C0F806D1D }, /* mnem=BT/BTS/BTR; ext=/4,/5,/6,/7; op=r/m,imm; lock */
    /* BB */ { 0x0000000E0F807C05 }, /* mnem=BTC; op=r/m; lock; rep */
    /* BC */ { 0x0000000E0F807405 }, /* mnem=BSF; op=r/m; rep */
    /* BD */ { 0x0000000E0F807405 }, /* mnem=BSR; op=r/m; rep */
    /* BE */ { 0x0000000E00007405 }, /* mnem=MOVSX; op=r/m; rep */
    /* BF */ { 0x0000000E00007405 }, /* mnem=MOVSX; op=r/m; rep */
    /* C0 */ { 0x0000000E0F807C05 }, /* mnem=XADD; op=r/m; lock; rep */
    /* C1 */ { 0x0000000E0F807C05 }, /* mnem=XADD; op=r/m; lock; rep */
    /* C2 */ { 0x0002E21C0000F41D }, /* mnem=CMPPS/CMPSS/CMPPD; mand=66,F2,F3; op=r/m,xmm,imm; string; rep */
    /* C3 */ { 0x0000000E00007405 }, /* mnem=MOVNTI; op=r/m; rep */
    /* C4 */ { 0x0002200010001400 }, /* mnem=PINSRW; mand=66; rep */
    /* C5 */ { 0x0002229A00003419 }, /* mnem=PEXTRW; mand=66; op=r/m,xmm,imm; rep */
    /* C6 */ { 0x0002221C0000741D }, /* mnem=SHUFPS/SHUFPD; mand=66; op=r/m,xmm,imm; rep */
    /* C7 */ { 0x030AA00C1F806D05 }, /* mnem=CMPXCHG8B/CMPXCHG16B/VMPTRLD; mand=66,F3; ext=/1,/6,/7; op=r/m; lock */
    /* C8 */ { 0x0000000200002600 }, /* mnem=BSWAP */
    /* C9 */ { 0x0000000000000000 },
    /* CA */ { 0x0000000000000000 },
    /* CB */ { 0x0000000000000000 },
    /* CC */ { 0x0000000000000000 },
    /* CD */ { 0x0000000000000000 },
    /* CE */ { 0x0000000000000000 },
    /* CF */ { 0x0000000000000000 },
    /* D0 */ { 0x0002601C00007405 }, /* mnem=ADDSUBPD/ADDSUBPS; mand=66,F2; op=r/m,xmm; rep */
    /* D1 */ { 0x0002209C00007405 }, /* mnem=PSRLW; mand=66; op=r/m,xmm; rep */
    /* D2 */ { 0x0002209C00007405 }, /* mnem=PSRLD; mand=66; op=r/m,xmm; rep */
    /* D3 */ { 0x0002209C00007405 }, /* mnem=PSRLQ; mand=66; op=r/m,xmm; rep */
    /* D4 */ { 0x0002209C00007405 }, /* mnem=PADDQ; mand=66; op=r/m,xmm; rep */
    /* D5 */ { 0x0002209C00007405 }, /* mnem=PMULLW; mand=66; op=r/m,xmm; rep */
    /* D6 */ { 0x0002E09C00007405 }, /* mnem=MOVQ/MOVQ2DQ/MOVDQ2Q; mand=66,F2,F3; op=r/m,xmm; rep */
    /* D7 */ { 0x0002209A00003401 }, /* mnem=PMOVMSKB; mand=66; op=r/m,xmm; rep */
    /* D8 */ { 0x0002209C00007405 }, /* mnem=PSUBUSB; mand=66; op=r/m,xmm; rep */
    /* D9 */ { 0x0002209C00007405 }, /* mnem=PSUBUSW; mand=66; op=r/m,xmm; rep */
    /* DA */ { 0x0002209C00007405 }, /* mnem=PMINUB; mand=66; op=r/m,xmm; rep */
    /* DB */ { 0x0002209C00007405 }, /* mnem=PAND; mand=66; op=r/m,xmm; rep */
    /* DC */ { 0x0002209C00007405 }, /* mnem=PADDUSB; mand=66; op=r/m,xmm; rep */
    /* DD */ { 0x0002209C00007405 }, /* mnem=PADDUSW; mand=66; op=r/m,xmm; rep */
    /* DE */ { 0x0002209C00007405 }, /* mnem=PMAXUB; mand=66; op=r/m,xmm; rep */
    /* DF */ { 0x0002209C00007405 }, /* mnem=PANDN; mand=66; op=r/m,xmm; rep */
    /* E0 */ { 0x0002209C00007405 }, /* mnem=PAVGB; mand=66; op=r/m,xmm; rep */
    /* E1 */ { 0x0002209C00007405 }, /* mnem=PSRAW; mand=66; op=r/m,xmm; rep */
    /* E2 */ { 0x0002209C00007405 }, /* mnem=PSRAD; mand=66; op=r/m,xmm; rep */
    /* E3 */ { 0x0002209C00007405 }, /* mnem=PAVGW; mand=66; op=r/m,xmm; rep */
    /* E4 */ { 0x0002209C00007405 }, /* mnem=PMULHUW; mand=66; op=r/m,xmm; rep */
    /* E5 */ { 0x0002209C00007405 }, /* mnem=PMULHW; mand=66; op=r/m,xmm; rep */
    /* E6 */ { 0x0002E01C00007405 }, /* mnem=CVTPD2DQ/CVTTPD2DQ/CVTDQ2PD; mand=66,F2,F3; op=r/m,xmm; rep */
    /* E7 */ { 0x0002209C00007405 }, /* mnem=MOVNTQ/MOVNTDQ; mand=66; op=r/m,xmm; rep */
    /* E8 */ { 0x0002209C00007405 }, /* mnem=PSUBSB; mand=66; op=r/m,xmm; rep */
    /* E9 */ { 0x0002209C00007405 }, /* mnem=PSUBSW; mand=66; op=r/m,xmm; rep */
    /* EA */ { 0x0002209C00007405 }, /* mnem=PMINSW; mand=66; op=r/m,xmm; rep */
    /* EB */ { 0x0002209C00007405 }, /* mnem=POR; mand=66; op=r/m,xmm; rep */
    /* EC */ { 0x0002209C00007405 }, /* mnem=PADDSB; mand=66; op=r/m,xmm; rep */
    /* ED */ { 0x0002209C00007405 }, /* mnem=PADDSW; mand=66; op=r/m,xmm; rep */
    /* EE */ { 0x0002209C00007405 }, /* mnem=PMAXSW; mand=66; op=r/m,xmm; rep */
    /* EF */ { 0x0002209C00007405 }, /* mnem=PXOR; mand=66; op=r/m,xmm; rep */
    /* F0 */ { 0x0000401C00007405 }, /* mnem=LDDQU; mand=F2; op=r/m,xmm; rep */
    /* F1 */ { 0x0002209C00007405 }, /* mnem=PSLLW; mand=66; op=r/m,xmm; rep */
    /* F2 */ { 0x0002209C00007405 }, /* mnem=PSLLD; mand=66; op=r/m,xmm; rep */
    /* F3 */ { 0x0002209C00007405 }, /* mnem=PSLLQ; mand=66; op=r/m,xmm; rep */
    /* F4 */ { 0x0002209C00007405 }, /* mnem=PMULUDQ; mand=66; op=r/m,xmm; rep */
    /* F5 */ { 0x0002209C00007405 }, /* mnem=PMADDWD; mand=66; op=r/m,xmm; rep */
    /* F6 */ { 0x0002209C00007405 }, /* mnem=PSADBW; mand=66; op=r/m,xmm; rep */
    /* F7 */ { 0x0002209800003401 }, /* mnem=MASKMOVQ/MASKMOVDQU; mand=66; op=r/m,xmm; rep */
    /* F8 */ { 0x0002209C00007405 }, /* mnem=PSUBB; mand=66; op=r/m,xmm; rep */
    /* F9 */ { 0x0002209C00007405 }, /* mnem=PSUBW; mand=66; op=r/m,xmm; rep */
    /* FA */ { 0x0002209C00007405 }, /* mnem=PSUBD; mand=66; op=r/m,xmm; rep */
    /* FB */ { 0x0002209C00007405 }, /* mnem=PSUBQ; mand=66; op=r/m,xmm; rep */
    /* FC */ { 0x0002209C00007405 }, /* mnem=PADDB; mand=66; op=r/m,xmm; rep */
    /* FD */ { 0x0002209C00007405 }, /* mnem=PADDW; mand=66; op=r/m,xmm; rep */
    /* FE */ { 0x0002209C00007405 }, /* mnem=PADDD; mand=66; op=r/m,xmm; rep */
    /* FF */ { 0x0000000000000000 },
};

const opcode_desc_t opcode_0f38[256] = {
    /* 00 */ { 0x0002209C00007405 }, /* mnem=PSHUFB; mand=66; op=r/m,xmm; rep */
    /* 01 */ { 0x0002209C00007405 }, /* mnem=PHADDW; mand=66; op=r/m,xmm; rep */
    /* 02 */ { 0x0002209C00007405 }, /* mnem=PHADDD; mand=66; op=r/m,xmm; rep */
    /* 03 */ { 0x0002209C00007405 }, /* mnem=PHADDSW; mand=66; op=r/m,xmm; rep */
    /* 04 */ { 0x0002209C00007405 }, /* mnem=PMADDUBSW; mand=66; op=r/m,xmm; rep */
    /* 05 */ { 0x0002209C00007405 }, /* mnem=PHSUBW; mand=66; op=r/m,xmm; rep */
    /* 06 */ { 0x0002209C00007405 }, /* mnem=PHSUBD; mand=66; op=r/m,xmm; rep */
    /* 07 */ { 0x0002209C00007405 }, /* mnem=PHSUBSW; mand=66; op=r/m,xmm; rep */
    /* 08 */ { 0x0002209C00007405 }, /* mnem=PSIGNB; mand=66; op=r/m,xmm; rep */
    /* 09 */ { 0x0002209C00007405 }, /* mnem=PSIGNW; mand=66; op=r/m,xmm; rep */
    /* 0A */ { 0x0002209C00007405 }, /* mnem=PSIGND; mand=66; op=r/m,xmm; rep */
    /* 0B */ { 0x0002209C00007405 }, /* mnem=PMULHRSW; mand=66; op=r/m,xmm; rep */
    /* 0C */ { 0x0000000000000000 },
    /* 0D */ { 0x0000000000000000 },
    /* 0E */ { 0x0000000000000000 },
    /* 0F */ { 0x0000000000000000 },
    /* 10 */ { 0x0000201C00007405 }, /* mnem=PBLENDVB; mand=66; op=r/m,xmm; rep */
    /* 11 */ { 0x0000000000000000 },
    /* 12 */ { 0x0000000000000000 },
    /* 13 */ { 0x0000000000000000 },
    /* 14 */ { 0x0000201C00007405 }, /* mnem=BLENDVPS; mand=66; op=r/m,xmm; rep */
    /* 15 */ { 0x0000201C00007405 }, /* mnem=BLENDVPD; mand=66; op=r/m,xmm; rep */
    /* 16 */ { 0x0000000000000000 },
    /* 17 */ { 0x0000201C0F807405 }, /* mnem=PTEST; mand=66; op=r/m,xmm; rep */
    /* 18 */ { 0x0000000000000000 },
    /* 19 */ { 0x0000000000000000 },
    /* 1A */ { 0x0000000000000000 },
    /* 1B */ { 0x0000000000000000 },
    /* 1C */ { 0x0002209C00007405 }, /* mnem=PABSB; mand=66; op=r/m,xmm; rep */
    /* 1D */ { 0x0002209C00007405 }, /* mnem=PABSW; mand=66; op=r/m,xmm; rep */
    /* 1E */ { 0x0002209C00007405 }, /* mnem=PABSD; mand=66; op=r/m,xmm; rep */
    /* 1F */ { 0x0000000000000000 },
    /* 20 */ { 0x0000200010001400 }, /* mnem=PMOVSXBW; mand=66; rep */
    /* 21 */ { 0x0000200010001400 }, /* mnem=PMOVSXBD; mand=66; rep */
    /* 22 */ { 0x0000200010001400 }, /* mnem=PMOVSXBQ; mand=66; rep */
    /* 23 */ { 0x0000200010001400 }, /* mnem=PMOVSXWD; mand=66; rep */
    /* 24 */ { 0x0000200010001400 }, /* mnem=PMOVSXWQ; mand=66; rep */
    /* 25 */ { 0x0000200010001400 }, /* mnem=PMOVSXDQ; mand=66; rep */
    /* 26 */ { 0x0000000000000000 },
    /* 27 */ { 0x0000000000000000 },
    /* 28 */ { 0x0000201C00007405 }, /* mnem=PMULDQ; mand=66; op=r/m,xmm; rep */
    /* 29 */ { 0x0000201C00007405 }, /* mnem=PCMPEQQ; mand=66; op=r/m,xmm; rep */
    /* 2A */ { 0x0000201C00007405 }, /* mnem=MOVNTDQA; mand=66; op=r/m,xmm; rep */
    /* 2B */ { 0x0000201C00007405 }, /* mnem=PACKUSDW; mand=66; op=r/m,xmm; rep */
    /* 2C */ { 0x0000000000000000 },
    /* 2D */ { 0x0000000000000000 },
    /* 2E */ { 0x0000000000000000 },
    /* 2F */ { 0x0000000000000000 },
    /* 30 */ { 0x0000200010001400 }, /* mnem=PMOVZXBW; mand=66; rep */
    /* 31 */ { 0x0000200010001400 }, /* mnem=PMOVZXBD; mand=66; rep */
    /* 32 */ { 0x0000200010001400 }, /* mnem=PMOVZXBQ; mand=66; rep */
    /* 33 */ { 0x0000200010001400 }, /* mnem=PMOVZXWD; mand=66; rep */
    /* 34 */ { 0x0000200010001400 }, /* mnem=PMOVZXWQ; mand=66; rep */
    /* 35 */ { 0x0000200010001400 }, /* mnem=PMOVZXDQ; mand=66; rep */
    /* 36 */ { 0x0000000000000000 },
    /* 37 */ { 0x0000201C00007405 }, /* mnem=PCMPGTQ; mand=66; op=r/m,xmm; rep */
    /* 38 */ { 0x0000201C00007405 }, /* mnem=PMINSB; mand=66; op=r/m,xmm; rep */
    /* 39 */ { 0x0000201C00007405 }, /* mnem=PMINSD; mand=66; op=r/m,xmm; rep */
    /* 3A */ { 0x0000201C00007405 }, /* mnem=PMINUW; mand=66; op=r/m,xmm; rep */
    /* 3B */ { 0x0000201C00007405 }, /* mnem=PMINUD; mand=66; op=r/m,xmm; rep */
    /* 3C */ { 0x0000201C00007405 }, /* mnem=PMAXSB; mand=66; op=r/m,xmm; rep */
    /* 3D */ { 0x0000201C00007405 }, /* mnem=PMAXSD; mand=66; op=r/m,xmm; rep */
    /* 3E */ { 0x0000201C00007405 }, /* mnem=PMAXUW; mand=66; op=r/m,xmm; rep */
    /* 3F */ { 0x0000201C00007405 }, /* mnem=PMAXUD; mand=66; op=r/m,xmm; rep */
    /* 40 */ { 0x0000201C00007405 }, /* mnem=PMULLD; mand=66; op=r/m,xmm; rep */
    /* 41 */ { 0x0000201C00007405 }, /* mnem=PHMINPOSUW; mand=66; op=r/m,xmm; rep */
    /* 42 */ { 0x0000000000000000 },
    /* 43 */ { 0x0000000000000000 },
    /* 44 */ { 0x0000000000000000 },
    /* 45 */ { 0x0000000000000000 },
    /* 46 */ { 0x0000000000000000 },
    /* 47 */ { 0x0000000000000000 },
    /* 48 */ { 0x0000000000000000 },
    /* 49 */ { 0x0000000000000000 },
    /* 4A */ { 0x0000000000000000 },
    /* 4B */ { 0x0000000000000000 },
    /* 4C */ { 0x0000000000000000 },
    /* 4D */ { 0x0000000000000000 },
    /* 4E */ { 0x0000000000000000 },
    /* 4F */ { 0x0000000000000000 },
    /* 50 */ { 0x0000000000000000 },
    /* 51 */ { 0x0000000000000000 },
    /* 52 */ { 0x0000000000000000 },
    /* 53 */ { 0x0000000000000000 },
    /* 54 */ { 0x0000000000000000 },
    /* 55 */ { 0x0000000000000000 },
    /* 56 */ { 0x0000000000000000 },
    /* 57 */ { 0x0000000000000000 },
    /* 58 */ { 0x0000000000000000 },
    /* 59 */ { 0x0000000000000000 },
    /* 5A */ { 0x0000000000000000 },
    /* 5B */ { 0x0000000000000000 },
    /* 5C */ { 0x0000000000000000 },
    /* 5D */ { 0x0000000000000000 },
    /* 5E */ { 0x0000000000000000 },
    /* 5F */ { 0x0000000000000000 },
    /* 60 */ { 0x0000000000000000 },
    /* 61 */ { 0x0000000000000000 },
    /* 62 */ { 0x0000000000000000 },
    /* 63 */ { 0x0000000000000000 },
    /* 64 */ { 0x0000000000000000 },
    /* 65 */ { 0x0000000000000000 },
    /* 66 */ { 0x0000000000000000 },
    /* 67 */ { 0x0000000000000000 },
    /* 68 */ { 0x0000000000000000 },
    /* 69 */ { 0x0000000000000000 },
    /* 6A */ { 0x0000000000000000 },
    /* 6B */ { 0x0000000000000000 },
    /* 6C */ { 0x0000000000000000 },
    /* 6D */ { 0x0000000000000000 },
    /* 6E */ { 0x0000000000000000 },
    /* 6F */ { 0x0000000000000000 },
    /* 70 */ { 0x0000000000000000 },
    /* 71 */ { 0x0000000000000000 },
    /* 72 */ { 0x0000000000000000 },
    /* 73 */ { 0x0000000000000000 },
    /* 74 */ { 0x0000000000000000 },
    /* 75 */ { 0x0000000000000000 },
    /* 76 */ { 0x0000000000000000 },
    /* 77 */ { 0x0000000000000000 },
    /* 78 */ { 0x0000000000000000 },
    /* 79 */ { 0x0000000000000000 },
    /* 7A */ { 0x0000000000000000 },
    /* 7B */ { 0x0000000000000000 },
    /* 7C */ { 0x0000000000000000 },
    /* 7D */ { 0x0000000000000000 },
    /* 7E */ { 0x0000000000000000 },
    /* 7F */ { 0x0000000000000000 },
    /* 80 */ { 0x0002200E0F807405 }, /* mnem=INVEPT; mand=66; op=r/m; rep */
    /* 81 */ { 0x0002200E0F807405 }, /* mnem=INVVPID; mand=66; op=r/m; rep */
    /* 82 */ { 0x0000000000000000 },
    /* 83 */ { 0x0000000000000000 },
    /* 84 */ { 0x0000000000000000 },
    /* 85 */ { 0x0000000000000000 },
    /* 86 */ { 0x0000000000000000 },
    /* 87 */ { 0x0000000000000000 },
    /* 88 */ { 0x0000000000000000 },
    /* 89 */ { 0x0000000000000000 },
    /* 8A */ { 0x0000000000000000 },
    /* 8B */ { 0x0000000000000000 },
    /* 8C */ { 0x0000000000000000 },
    /* 8D */ { 0x0000000000000000 },
    /* 8E */ { 0x0000000000000000 },
    /* 8F */ { 0x0000000000000000 },
    /* 90 */ { 0x0000000000000000 },
    /* 91 */ { 0x0000000000000000 },
    /* 92 */ { 0x0000000000000000 },
    /* 93 */ { 0x0000000000000000 },
    /* 94 */ { 0x0000000000000000 },
    /* 95 */ { 0x0000000000000000 },
    /* 96 */ { 0x0000000000000000 },
    /* 97 */ { 0x0000000000000000 },
    /* 98 */ { 0x0000000000000000 },
    /* 99 */ { 0x0000000000000000 },
    /* 9A */ { 0x0000000000000000 },
    /* 9B */ { 0x0000000000000000 },
    /* 9C */ { 0x0000000000000000 },
    /* 9D */ { 0x0000000000000000 },
    /* 9E */ { 0x0000000000000000 },
    /* 9F */ { 0x0000000000000000 },
    /* A0 */ { 0x0000000000000000 },
    /* A1 */ { 0x0000000000000000 },
    /* A2 */ { 0x0000000000000000 },
    /* A3 */ { 0x0000000000000000 },
    /* A4 */ { 0x0000000000000000 },
    /* A5 */ { 0x0000000000000000 },
    /* A6 */ { 0x0000000000000000 },
    /* A7 */ { 0x0000000000000000 },
    /* A8 */ { 0x0000000000000000 },
    /* A9 */ { 0x0000000000000000 },
    /* AA */ { 0x0000000000000000 },
    /* AB */ { 0x0000000000000000 },
    /* AC */ { 0x0000000000000000 },
    /* AD */ { 0x0000000000000000 },
    /* AE */ { 0x0000000000000000 },
    /* AF */ { 0x0000000000000000 },
    /* B0 */ { 0x0000000000000000 },
    /* B1 */ { 0x0000000000000000 },
    /* B2 */ { 0x0000000000000000 },
    /* B3 */ { 0x0000000000000000 },
    /* B4 */ { 0x0000000000000000 },
    /* B5 */ { 0x0000000000000000 },
    /* B6 */ { 0x0000000000000000 },
    /* B7 */ { 0x0000000000000000 },
    /* B8 */ { 0x0000000000000000 },
    /* B9 */ { 0x0000000000000000 },
    /* BA */ { 0x0000000000000000 },
    /* BB */ { 0x0000000000000000 },
    /* BC */ { 0x0000000000000000 },
    /* BD */ { 0x0000000000000000 },
    /* BE */ { 0x0000000000000000 },
    /* BF */ { 0x0000000000000000 },
    /* C0 */ { 0x0000000000000000 },
    /* C1 */ { 0x0000000000000000 },
    /* C2 */ { 0x0000000000000000 },
    /* C3 */ { 0x0000000000000000 },
    /* C4 */ { 0x0000000000000000 },
    /* C5 */ { 0x0000000000000000 },
    /* C6 */ { 0x0000000000000000 },
    /* C7 */ { 0x0000000000000000 },
    /* C8 */ { 0x0000000000000000 },
    /* C9 */ { 0x0000000000000000 },
    /* CA */ { 0x0000000000000000 },
    /* CB */ { 0x0000000000000000 },
    /* CC */ { 0x0000000000000000 },
    /* CD */ { 0x0000000000000000 },
    /* CE */ { 0x0000000000000000 },
    /* CF */ { 0x0000000000000000 },
    /* D0 */ { 0x0000000000000000 },
    /* D1 */ { 0x0000000000000000 },
    /* D2 */ { 0x0000000000000000 },
    /* D3 */ { 0x0000000000000000 },
    /* D4 */ { 0x0000000000000000 },
    /* D5 */ { 0x0000000000000000 },
    /* D6 */ { 0x0000000000000000 },
    /* D7 */ { 0x0000000000000000 },
    /* D8 */ { 0x0000000000000000 },
    /* D9 */ { 0x0000000000000000 },
    /* DA */ { 0x0000000000000000 },
    /* DB */ { 0x0000000000000000 },
    /* DC */ { 0x0000000000000000 },
    /* DD */ { 0x0000000000000000 },
    /* DE */ { 0x0000000000000000 },
    /* DF */ { 0x0000000000000000 },
    /* E0 */ { 0x0000000000000000 },
    /* E1 */ { 0x0000000000000000 },
    /* E2 */ { 0x0000000000000000 },
    /* E3 */ { 0x0000000000000000 },
    /* E4 */ { 0x0000000000000000 },
    /* E5 */ { 0x0000000000000000 },
    /* E6 */ { 0x0000000000000000 },
    /* E7 */ { 0x0000000000000000 },
    /* E8 */ { 0x0000000000000000 },
    /* E9 */ { 0x0000000000000000 },
    /* EA */ { 0x0000000000000000 },
    /* EB */ { 0x0000000000000000 },
    /* EC */ { 0x0000000000000000 },
    /* ED */ { 0x0000000000000000 },
    /* EE */ { 0x0000000000000000 },
    /* EF */ { 0x0000000000000000 },
    /* F0 */ { 0x0002400E00007405 }, /* mnem=MOVBE/CRC32; mand=F2; op=r/m; rep */
    /* F1 */ { 0x0002400E00007405 }, /* mnem=MOVBE/CRC32; mand=F2; op=r/m; rep */
    /* F2 */ { 0x0000000000000000 },
    /* F3 */ { 0x0000000000000000 },
    /* F4 */ { 0x0000000000000000 },
    /* F5 */ { 0x0000000000000000 },
    /* F6 */ { 0x0000000000000000 },
    /* F7 */ { 0x0000000000000000 },
    /* F8 */ { 0x0000000000000000 },
    /* F9 */ { 0x0000000000000000 },
    /* FA */ { 0x0000000000000000 },
    /* FB */ { 0x0000000000000000 },
    /* FC */ { 0x0000000000000000 },
    /* FD */ { 0x0000000000000000 },
    /* FE */ { 0x0000000000000000 },
    /* FF */ { 0x0000000000000000 },
};

const opcode_desc_t opcode_0f3a[256] = {
    /* 00 */ { 0x0000000000000000 },
    /* 01 */ { 0x0000000000000000 },
    /* 02 */ { 0x0000000000000000 },
    /* 03 */ { 0x0000000000000000 },
    /* 04 */ { 0x0000000000000000 },
    /* 05 */ { 0x0000000000000000 },
    /* 06 */ { 0x0000000000000000 },
    /* 07 */ { 0x0000000000000000 },
    /* 08 */ { 0x0000221C0000741D }, /* mnem=ROUNDPS; mand=66; op=r/m,xmm,imm; rep */
    /* 09 */ { 0x0000221C0000741D }, /* mnem=ROUNDPD; mand=66; op=r/m,xmm,imm; rep */
    /* 0A */ { 0x0000221C0000741D }, /* mnem=ROUNDSS; mand=66; op=r/m,xmm,imm; rep */
    /* 0B */ { 0x0000221C0000741D }, /* mnem=ROUNDSD; mand=66; op=r/m,xmm,imm; rep */
    /* 0C */ { 0x0000221C0000741D }, /* mnem=BLENDPS; mand=66; op=r/m,xmm,imm; rep */
    /* 0D */ { 0x0000221C0000741D }, /* mnem=BLENDPD; mand=66; op=r/m,xmm,imm; rep */
    /* 0E */ { 0x0000221C0000741D }, /* mnem=PBLENDW; mand=66; op=r/m,xmm,imm; rep */
    /* 0F */ { 0x0002209C00007405 }, /* mnem=PALIGNR; mand=66; op=r/m,xmm; rep */
    /* 10 */ { 0x0000000000000000 },
    /* 11 */ { 0x0000000000000000 },
    /* 12 */ { 0x0000000000000000 },
    /* 13 */ { 0x0000000000000000 },
    /* 14 */ { 0x0000200010001400 }, /* mnem=PEXTRB; mand=66; rep */
    /* 15 */ { 0x0000200010001400 }, /* mnem=PEXTRW; mand=66; rep */
    /* 16 */ { 0x0000200010001400 }, /* mnem=PEXTRD/PEXTRQ; mand=66; rep */
    /* 17 */ { 0x0000221C0000741D }, /* mnem=EXTRACTPS; mand=66; op=r/m,xmm,imm; rep */
    /* 18 */ { 0x0000000000000000 },
    /* 19 */ { 0x0000000000000000 },
    /* 1A */ { 0x0000000000000000 },
    /* 1B */ { 0x0000000000000000 },
    /* 1C */ { 0x0000000000000000 },
    /* 1D */ { 0x0000000000000000 },
    /* 1E */ { 0x0000000000000000 },
    /* 1F */ { 0x0000000000000000 },
    /* 20 */ { 0x0000200010001400 }, /* mnem=PINSRB; mand=66; rep */
    /* 21 */ { 0x0000200010001400 }, /* mnem=INSERTPS; mand=66; rep */
    /* 22 */ { 0x0000200010001400 }, /* mnem=PINSRD/PINSRQ; mand=66; rep */
    /* 23 */ { 0x0000000000000000 },
    /* 24 */ { 0x0000000000000000 },
    /* 25 */ { 0x0000000000000000 },
    /* 26 */ { 0x0000000000000000 },
    /* 27 */ { 0x0000000000000000 },
    /* 28 */ { 0x0000000000000000 },
    /* 29 */ { 0x0000000000000000 },
    /* 2A */ { 0x0000000000000000 },
    /* 2B */ { 0x0000000000000000 },
    /* 2C */ { 0x0000000000000000 },
    /* 2D */ { 0x0000000000000000 },
    /* 2E */ { 0x0000000000000000 },
    /* 2F */ { 0x0000000000000000 },
    /* 30 */ { 0x0000000000000000 },
    /* 31 */ { 0x0000000000000000 },
    /* 32 */ { 0x0000000000000000 },
    /* 33 */ { 0x0000000000000000 },
    /* 34 */ { 0x0000000000000000 },
    /* 35 */ { 0x0000000000000000 },
    /* 36 */ { 0x0000000000000000 },
    /* 37 */ { 0x0000000000000000 },
    /* 38 */ { 0x0000000000000000 },
    /* 39 */ { 0x0000000000000000 },
    /* 3A */ { 0x0000000000000000 },
    /* 3B */ { 0x0000000000000000 },
    /* 3C */ { 0x0000000000000000 },
    /* 3D */ { 0x0000000000000000 },
    /* 3E */ { 0x0000000000000000 },
    /* 3F */ { 0x0000000000000000 },
    /* 40 */ { 0x0000201C00007405 }, /* mnem=DPPS; mand=66; op=r/m,xmm; rep */
    /* 41 */ { 0x0000201C00007405 }, /* mnem=DPPD; mand=66; op=r/m,xmm; rep */
    /* 42 */ { 0x0000221C0000741D }, /* mnem=MPSADBW; mand=66; op=r/m,xmm,imm; rep */
    /* 43 */ { 0x0000000000000000 },
    /* 44 */ { 0x0000000000000000 },
    /* 45 */ { 0x0000000000000000 },
    /* 46 */ { 0x0000000000000000 },
    /* 47 */ { 0x0000000000000000 },
    /* 48 */ { 0x0000000000000000 },
    /* 49 */ { 0x0000000000000000 },
    /* 4A */ { 0x0000000000000000 },
    /* 4B */ { 0x0000000000000000 },
    /* 4C */ { 0x0000000000000000 },
    /* 4D */ { 0x0000000000000000 },
    /* 4E */ { 0x0000000000000000 },
    /* 4F */ { 0x0000000000000000 },
    /* 50 */ { 0x0000000000000000 },
    /* 51 */ { 0x0000000000000000 },
    /* 52 */ { 0x0000000000000000 },
    /* 53 */ { 0x0000000000000000 },
    /* 54 */ { 0x0000000000000000 },
    /* 55 */ { 0x0000000000000000 },
    /* 56 */ { 0x0000000000000000 },
    /* 57 */ { 0x0000000000000000 },
    /* 58 */ { 0x0000000000000000 },
    /* 59 */ { 0x0000000000000000 },
    /* 5A */ { 0x0000000000000000 },
    /* 5B */ { 0x0000000000000000 },
    /* 5C */ { 0x0000000000000000 },
    /* 5D */ { 0x0000000000000000 },
    /* 5E */ { 0x0000000000000000 },
    /* 5F */ { 0x0000000000000000 },
    /* 60 */ { 0x0000221C0F80741D }, /* mnem=PCMPESTRM; mand=66; op=r/m,xmm,imm; rep */
    /* 61 */ { 0x0000221C0F80741D }, /* mnem=PCMPESTRI; mand=66; op=r/m,xmm,imm; rep */
    /* 62 */ { 0x0000221C0F80741D }, /* mnem=PCMPISTRM; mand=66; op=r/m,xmm,imm; rep */
    /* 63 */ { 0x0000221C0F80741D }, /* mnem=PCMPISTRI; mand=66; op=r/m,xmm,imm; rep */
    /* 64 */ { 0x0000000000000000 },
    /* 65 */ { 0x0000000000000000 },
    /* 66 */ { 0x0000000000000000 },
    /* 67 */ { 0x0000000000000000 },
    /* 68 */ { 0x0000000000000000 },
    /* 69 */ { 0x0000000000000000 },
    /* 6A */ { 0x0000000000000000 },
    /* 6B */ { 0x0000000000000000 },
    /* 6C */ { 0x0000000000000000 },
    /* 6D */ { 0x0000000000000000 },
    /* 6E */ { 0x0000000000000000 },
    /* 6F */ { 0x0000000000000000 },
    /* 70 */ { 0x0000000000000000 },
    /* 71 */ { 0x0000000000000000 },
    /* 72 */ { 0x0000000000000000 },
    /* 73 */ { 0x0000000000000000 },
    /* 74 */ { 0x0000000000000000 },
    /* 75 */ { 0x0000000000000000 },
    /* 76 */ { 0x0000000000000000 },
    /* 77 */ { 0x0000000000000000 },
    /* 78 */ { 0x0000000000000000 },
    /* 79 */ { 0x0000000000000000 },
    /* 7A */ { 0x0000000000000000 },
    /* 7B */ { 0x0000000000000000 },
    /* 7C */ { 0x0000000000000000 },
    /* 7D */ { 0x0000000000000000 },
    /* 7E */ { 0x0000000000000000 },
    /* 7F */ { 0x0000000000000000 },
    /* 80 */ { 0x0000000000000000 },
    /* 81 */ { 0x0000000000000000 },
    /* 82 */ { 0x0000000000000000 },
    /* 83 */ { 0x0000000000000000 },
    /* 84 */ { 0x0000000000000000 },
    /* 85 */ { 0x0000000000000000 },
    /* 86 */ { 0x0000000000000000 },
    /* 87 */ { 0x0000000000000000 },
    /* 88 */ { 0x0000000000000000 },
    /* 89 */ { 0x0000000000000000 },
    /* 8A */ { 0x0000000000000000 },
    /* 8B */ { 0x0000000000000000 },
    /* 8C */ { 0x0000000000000000 },
    /* 8D */ { 0x0000000000000000 },
    /* 8E */ { 0x0000000000000000 },
    /* 8F */ { 0x0000000000000000 },
    /* 90 */ { 0x0000000000000000 },
    /* 91 */ { 0x0000000000000000 },
    /* 92 */ { 0x0000000000000000 },
    /* 93 */ { 0x0000000000000000 },
    /* 94 */ { 0x0000000000000000 },
    /* 95 */ { 0x0000000000000000 },
    /* 96 */ { 0x0000000000000000 },
    /* 97 */ { 0x0000000000000000 },
    /* 98 */ { 0x0000000000000000 },
    /* 99 */ { 0x0000000000000000 },
    /* 9A */ { 0x0000000000000000 },
    /* 9B */ { 0x0000000000000000 },
    /* 9C */ { 0x0000000000000000 },
    /* 9D */ { 0x0000000000000000 },
    /* 9E */ { 0x0000000000000000 },
    /* 9F */ { 0x0000000000000000 },
    /* A0 */ { 0x0000000000000000 },
    /* A1 */ { 0x0000000000000000 },
    /* A2 */ { 0x0000000000000000 },
    /* A3 */ { 0x0000000000000000 },
    /* A4 */ { 0x0000000000000000 },
    /* A5 */ { 0x0000000000000000 },
    /* A6 */ { 0x0000000000000000 },
    /* A7 */ { 0x0000000000000000 },
    /* A8 */ { 0x0000000000000000 },
    /* A9 */ { 0x0000000000000000 },
    /* AA */ { 0x0000000000000000 },
    /* AB */ { 0x0000000000000000 },
    /* AC */ { 0x0000000000000000 },
    /* AD */ { 0x0000000000000000 },
    /* AE */ { 0x0000000000000000 },
    /* AF */ { 0x0000000000000000 },
    /* B0 */ { 0x0000000000000000 },
    /* B1 */ { 0x0000000000000000 },
    /* B2 */ { 0x0000000000000000 },
    /* B3 */ { 0x0000000000000000 },
    /* B4 */ { 0x0000000000000000 },
    /* B5 */ { 0x0000000000000000 },
    /* B6 */ { 0x0000000000000000 },
    /* B7 */ { 0x0000000000000000 },
    /* B8 */ { 0x0000000000000000 },
    /* B9 */ { 0x0000000000000000 },
    /* BA */ { 0x0000000000000000 },
    /* BB */ { 0x0000000000000000 },
    /* BC */ { 0x0000000000000000 },
    /* BD */ { 0x0000000000000000 },
    /* BE */ { 0x0000000000000000 },
    /* BF */ { 0x0000000000000000 },
    /* C0 */ { 0x0000000000000000 },
    /* C1 */ { 0x0000000000000000 },
    /* C2 */ { 0x0000000000000000 },
    /* C3 */ { 0x0000000000000000 },
    /* C4 */ { 0x0000000000000000 },
    /* C5 */ { 0x0000000000000000 },
    /* C6 */ { 0x0000000000000000 },
    /* C7 */ { 0x0000000000000000 },
    /* C8 */ { 0x0000000000000000 },
    /* C9 */ { 0x0000000000000000 },
    /* CA */ { 0x0000000000000000 },
    /* CB */ { 0x0000000000000000 },
    /* CC */ { 0x0000000000000000 },
    /* CD */ { 0x0000000000000000 },
    /* CE */ { 0x0000000000000000 },
    /* CF */ { 0x0000000000000000 },
    /* D0 */ { 0x0000000000000000 },
    /* D1 */ { 0x0000000000000000 },
    /* D2 */ { 0x0000000000000000 },
    /* D3 */ { 0x0000000000000000 },
    /* D4 */ { 0x0000000000000000 },
    /* D5 */ { 0x0000000000000000 },
    /* D6 */ { 0x0000000000000000 },
    /* D7 */ { 0x0000000000000000 },
    /* D8 */ { 0x0000000000000000 },
    /* D9 */ { 0x0000000000000000 },
    /* DA */ { 0x0000000000000000 },
    /* DB */ { 0x0000000000000000 },
    /* DC */ { 0x0000000000000000 },
    /* DD */ { 0x0000000000000000 },
    /* DE */ { 0x0000000000000000 },
    /* DF */ { 0x0000000000000000 },
    /* E0 */ { 0x0000000000000000 },
    /* E1 */ { 0x0000000000000000 },
    /* E2 */ { 0x0000000000000000 },
    /* E3 */ { 0x0000000000000000 },
    /* E4 */ { 0x0000000000000000 },
    /* E5 */ { 0x0000000000000000 },
    /* E6 */ { 0x0000000000000000 },
    /* E7 */ { 0x0000000000000000 },
    /* E8 */ { 0x0000000000000000 },
    /* E9 */ { 0x0000000000000000 },
    /* EA */ { 0x0000000000000000 },
    /* EB */ { 0x0000000000000000 },
    /* EC */ { 0x0000000000000000 },
    /* ED */ { 0x0000000000000000 },
    /* EE */ { 0x0000000000000000 },
    /* EF */ { 0x0000000000000000 },
    /* F0 */ { 0x0000000000000000 },
    /* F1 */ { 0x0000000000000000 },
    /* F2 */ { 0x0000000000000000 },
    /* F3 */ { 0x0000000000000000 },
    /* F4 */ { 0x0000000000000000 },
    /* F5 */ { 0x0000000000000000 },
    /* F6 */ { 0x0000000000000000 },
    /* F7 */ { 0x0000000000000000 },
    /* F8 */ { 0x0000000000000000 },
    /* F9 */ { 0x0000000000000000 },
    /* FA */ { 0x0000000000000000 },
    /* FB */ { 0x0000000000000000 },
    /* FC */ { 0x0000000000000000 },
    /* FD */ { 0x0000000000000000 },
    /* FE */ { 0x0000000000000000 },
    /* FF */ { 0x0000000000000000 },
};
