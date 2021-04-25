#include "cpu.h"
#include <stdio.h>

void Reset(cpu_s* cpus, mem_s* mems) {
	cpus->PC = 0xFFFC;
	cpus->SP = 0x0100;

	cpus->A = 0;
	cpus->X = 0;
	cpus->Y = 0;

	// clear flags
	cpus->C = 0;
	cpus->Z = 0;
	cpus->I = 0;
	cpus->D = 0;
	cpus->B = 0;
	cpus->V = 0;
	cpus->N = 0;

	// initialize memory
	MemInit(mems);
}

__byte FetchByte(u32* cycles, cpu_s* cpus, mem_s* mems) {
	__byte d = mems->memory[cpus->PC];
	cpus->PC++;
	(*cycles)--;

	return d;
}

void Execute(u32 cycles, cpu_s* cpus, mem_s* mems) {
	while (cycles > 0) {
		__byte instruction = FetchByte(&cycles, cpus, mems);
		switch (instruction) {
		case INS_LDA_IM:
		{
			__byte val = FetchByte(&cycles, cpus, mems);
			cpus->A = val;
			cpus->Z = cpus->A == 0;
			cpus->N = (cpus->A & 0b10000000) > 0;
		} break;
		case INS_ADC_IM:
		{
			cpus->Z = cpus->A == 0;
			cpus->N = (cpus->A & 0b10000000) > 0;
		} break;
		default: {
			fprintf(stderr, "instruction %u not handled!", instruction);
			break;
		}
	}

	return;
}