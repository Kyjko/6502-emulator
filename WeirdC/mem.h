#ifndef _MEM_H
#define _MEM_H

#include "common.h"

typedef struct mem_s {

	__byte* memory;

} mem_s;

u32 MemInit(mem_s* mems);
void MemDeInit(mem_s* mems);

#endif
