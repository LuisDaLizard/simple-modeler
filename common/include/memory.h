#pragma once

#include "defines.h"

typedef struct
{
    void* ptr;
    i32 refs;
} smc_mem;

/**
 * Allocate memory of the given size and sets the reference count to 1.
 *
 * @param size How many bytes to allocate.
 * @param clear Whether to set the memory to zero.
 * @return An smc_mem struct. If no memory is available, ptr is NULL.
 */
smc_mem
smc_allocate(u64 size, b32 clear);

/**
 * Grabs a reference to the memory allocated in smc_mem.
 *
 * @param memory An smc_mem struct pointer with allocated memory.
 */
void
smc_grab(smc_mem *memory);

/**
 * Releases the reference to memory allocated in smc_mem and frees it if
 * there are no more references
 *
 * @param memory An smc_mem struct pointer with allocated memory.
 */
void
smc_release(smc_mem *memory);
