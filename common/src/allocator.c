#include "allocator.h"

#include <stdlib.h>
#include <string.h>

#define INITIAL_ALLOCATION_COUNT 8

typedef struct
{
    void *ptr;
    u64 size;
} smAllocInfo;

typedef struct
{
    smAllocInfo *allocations;
    u32 count;
    u32 capacity;
} smAllocations;

static smAllocations sAllocations;

static void smAllocatorInit(void);
static void smAllocatorExpand(void);
static i32 smAllocatorFind(void *ptr);

void *smAlloc(u64 size, b32 clear)
{
    smAllocatorInit();
    smAllocatorExpand();

    smAllocInfo info;
    info.size = size;
    info.ptr = malloc(size);

    if (clear) memset(info.ptr, 0, size);

    sAllocations.allocations[sAllocations.count] = info;
    sAllocations.count++;

    return info.ptr;
}

void *smRealloc(u64 size, void *ptr, b32 clear)
{
    smAllocatorInit();
    smAllocatorExpand();

    i32 index = -1;
    for (i32 i = 0; i < sAllocations.count; i++)
    {
        smAllocInfo info = sAllocations.allocations[i];
        if (info.ptr == ptr)
        {
            index = i;
            break;
        }
    }

    // TODO: cannot reallocate data allocated from other methods
    if (index == -1) return smAlloc(size, clear);

    void *data = realloc(ptr, size);
    assertf(data != NULL, "smAllocator: Failed to reallocate memory");

    sAllocations.allocations[index].ptr = data;
    sAllocations.allocations[index].size = size;

    return data;
}

void smFree(void *ptr)
{
    smAllocatorInit();

    i32 index = smAllocatorFind(ptr);
    if (index == -1) goto free;

    // Shift elements down to remove the element
    for (i32 i = index; i < sAllocations.count - 1; i++)
        sAllocations.allocations[i] = sAllocations.allocations[i + 1];

free:
    free(ptr);
}

static void smAllocatorInit(void)
{
    if (sAllocations.allocations != NULL) return;

    sAllocations.allocations = malloc(sizeof(smAllocInfo) * INITIAL_ALLOCATION_COUNT);
    assertf(sAllocations.allocations != NULL, "smAllocator: Failed to allocate memory");

    sAllocations.capacity = INITIAL_ALLOCATION_COUNT;
    sAllocations.count = 0;
}

static void smAllocatorExpand(void)
{
    if (sAllocations.count < sAllocations.capacity) return;

    u64 newCapacity = sAllocations.capacity * 2;

    void *data = realloc(sAllocations.allocations, sizeof(smAllocInfo) * newCapacity);
    assertf(data != NULL, "smAllocator: Failed to reallocate memory");

    sAllocations.allocations = data;
    sAllocations.capacity = newCapacity;
}

static i32 smAllocatorFind(void *ptr)
{
    for (i32 i = 0; i < sAllocations.count; i++)
    {
        smAllocInfo info = sAllocations.allocations[i];
        if (info.ptr == ptr)
            return i;
    }

    return -1;
}