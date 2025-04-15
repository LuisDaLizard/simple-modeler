#pragma once

#include "defines.h"

typedef struct
{
    const char *title;
    u32 width, height;
    b32 resizable;
} smWindowInfo;

typedef struct
{
    void* handle;
} smWindow;


/**
 *
 * @param window
 * @param info
 * @return
 */
b32
smWindowCreate(smWindow *window, smWindowInfo *info);

/**
 *
 * @param window
 */
void
smWindowDestroy(smWindow *window);

/**
 *
 * @param window
 * @return
 */
b32
smWindowShouldClose(smWindow *window);