#pragma once

#include "defines.h"

void *smAlloc(u64 size, b32 clear);
void *smRealloc(u64 size, void *ptr, b32 clear);
void smFree(void *ptr);