#include "window.h"
#include <GLFW/glfw3.h>

static b8 smg_window_initialized = FALSE;
static u8 smg_window_count = 0;

b32
smg_window_create(smg_window *window, smg_window_info *info)
{
    assert(window != NULL);
    assert(info != NULL);

    if (!smg_window_initialized)
    {
        if (!glfwInit()) return 0;
        smg_window_initialized = TRUE;
    }

    if (smg_window_count == U8_MAX)
        return 0;

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, TRUE);
    glfwWindowHint(GLFW_RESIZABLE, info->resizable);

    window->handle = glfwCreateWindow(info->width, info->height, info->title, NULL, NULL);

    if (!window->handle)
        return 0;

    glfwMakeContextCurrent(window->handle);
    glfwSwapInterval(0);

    smg_window_count ++;
    return 1;
}

void
smg_window_destroy(smg_window *window)
{
    assert(window);
    assert(window->handle);
    assert(smg_window_count > 0);

    smg_window_count --;
    glfwDestroyWindow(window->handle);
    window->handle = NULL;

    if (!smg_window_count)
    {
        glfwTerminate();
        smg_window_initialized = FALSE;
    }
}

b32
smg_window_should_close(smg_window *window)
{
    assert(window);
    assert(window->handle);

    glfwPollEvents();
    glfwSwapBuffers(window->handle);
    return glfwWindowShouldClose(window->handle);
}