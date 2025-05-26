#pragma once

#include "defines.h"
#include "input.h"

typedef struct
{
    const char *title;
    u32 width, height;
    b32 resizable;
} smWindowInfo;

typedef struct
{
    void* handle;
    smInput input;
} smWindow;


/**
 *
 * @param window
 * @param info
 * @return
 */
b32 smWindowCreate(smWindow *window, smWindowInfo *info);

/**
 *
 * @param window
 */
void smWindowDestroy(smWindow *window);

/**
 *
 * @param window
 * @return
 */
b32 smWindowShouldClose(smWindow *window);

/**
 *
 * @param window
 * @return
 */
smInput smWindowGetInput(smWindow *window);