#pragma once

#include "defines.h"

typedef struct
{
    const char *title;
    u32 width, height;
    b32 resizable;
} smg_window_info;

typedef struct
{
    void* handle;
} smg_window;


/**
 *
 * @param window
 * @param info
 * @return
 */
b32
smg_window_create(smg_window *window, smg_window_info *info);

/**
 *
 * @param window
 */
void
smg_window_destroy(smg_window *window);

/**
 *
 * @param window
 * @return
 */
b32
smg_window_should_close(smg_window *window);