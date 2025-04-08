#include "memory.h"
#include <stdlib.h>
#include <string.h>

b32
smc_allocate(smc_mem *memory, u64 size, b32 clear)
{
    assert(memory != NULL);
    assert(memory->ptr == NULL);
    assert(memory->refs == 0);
    assert(size > 0);

    if ((memory->ptr = malloc(size)) == NULL)
        return 0;

    if (clear) memset(memory->ptr, 0, size);

    smc_grab(memory);

    return 1;
}

b32
smc_reallocate(smc_mem *memory, u64 size)
{
    assert(memory != NULL);
    assert(memory->ptr != NULL);
    assert(memory->refs > 0);
    assert(size > 0);

    void* ptr = realloc(memory->ptr, size);
    if (ptr == NULL)
        return 0;

    memory->ptr = ptr;
    return 1;
}

void
smc_grab(smc_mem *memory)
{
    assert(memory != NULL);
    assert(memory->ptr != NULL);

    memory->refs++;
}

void
smc_release(smc_mem *memory)
{
    assert(memory != NULL);
    assert(memory->ptr != NULL);

    memory->refs--;
    if (memory->refs) return;

    free(memory->ptr);
    memory->ptr = NULL;
}
