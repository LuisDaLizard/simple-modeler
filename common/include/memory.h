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
 * @param memory A pointer to an smc_mem struct to allocate.
 * @param size How many bytes to allocate.
 * @param clear Whether to set the memory to zero.
 * @return Returns 0 if the allocation failed.
 */
b32
smc_allocate(smc_mem *memory, u64 size, b32 clear);

/**
 * Reallocates the memory passed in to size bytes.
 *
 * @param memory A pointer to an smc_mem struct to reallocate.
 * @param size How many bytes to reallocate.
 * @return Returns 0 if the allocation failed.
 */
b32
smc_reallocate(smc_mem *memory, u64 size);

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
