#include "mem.h"

#include <stdlib.h>
#include <memory.h>

u32 MemInit(mem_s* mems) {
	mems->memory = malloc(sizeof(__byte) * MAX_MEM);
	if (mems->memory == NULL) {
		return -1;
	}
	memset(mems->memory, 0, MAX_MEM);
}

void MemDeInit(mem_s* mems) {
	free(mems->memory);
}