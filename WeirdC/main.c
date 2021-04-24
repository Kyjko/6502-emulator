#include <stdio.h>
#include <stdlib.h>

#include "cpu.h"
#include "mem.h"

int main(int argc, char** argv) {
	
	cpu_s CPU;
	mem_s MEM;
	
	MemInit(&MEM);
	Reset(&CPU, &MEM);
	Execute(10, &CPU, &MEM);

	MemDeInit(&MEM);
	return 0;
}