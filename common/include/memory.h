#pragma once

#include "defines.h"

typedef struct
{
    void* ptr;
    i32 refs;
} smMem;

/**
 * Allocate memory of the given size and sets the reference count to 1.
 *
 * @param memory A pointer to an smc_mem struct to allocate.
 * @param size How many bytes to allocate.
 * @param clear Whether to set the memory to zero.
 * @return Returns 0 if the allocation failed.
 */
b32
smAllocate(smMem *memory, u64 size, b32 clear);

/**
 * Reallocates the memory passed in to size bytes.
 *
 * @param memory A pointer to an smc_mem struct to reallocate.
 * @param size How many bytes to reallocate.
 * @return Returns 0 if the allocation failed.
 */
b32
smReallocate(smMem *memory, u64 size);

/**
 * Grabs a reference to the memory allocated in smc_mem.
 *
 * @param memory An smc_mem struct pointer with allocated memory.
 */
void
smGrab(smMem *memory);

/**
 * Releases the reference to memory allocated in smc_mem and frees it if
 * there are no more references
 *
 * @param memory An smc_mem struct pointer with allocated memory.
 */
void
smRelease(smMem *memory);
