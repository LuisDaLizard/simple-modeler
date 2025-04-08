#include "memory.h"
#include <stdlib.h>
#include <string.h>

smc_mem
smc_allocate(u64 size, b32 clear)
{
    assert(size > 0);
    smc_mem new_mem = { NULL, 0 };

    if ((new_mem.ptr = malloc(size)) == NULL)
    {
        return new_mem;
    }

    if (clear) memset(new_mem.ptr, 0, size);

    smc_grab(&new_mem);

    return new_mem;
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
