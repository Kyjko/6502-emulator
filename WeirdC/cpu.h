#ifndef _CPU_H
#define _CPU_H

#include "common.h"
#include "mem.h"

// opcodes

#define INS_ADC_IM 0x69
#define INS_AND_IM 0x29
#define INS_ASL_IM 0x0A

#define INS_LDA_IM 0xA9
#define INS_LDX_IM 0xA2
#define INS_LDY_IM 0xA0

typedef struct cpu_s {
	
	__word PC;	// program counter 
	__byte SP;	// stack ponter

	__byte A;	// accumulator
	__byte X;	// index register X
	__byte Y;	// index register Y

	// status flags
	__byte C : 1;
	__byte Z : 1;
	__byte I : 1;
	__byte D : 1;
	__byte B : 1;
	__byte V : 1;
	__byte N : 1;

} cpu_s;

void Reset(cpu_s* cpus, mem_s* mems);
__byte FetchByte(u32* cycles, cpu_s* cpus, mem_s* mems);
void Execute(u32 cycles, cpu_s* cpus, mem_s* mems);


#endif
