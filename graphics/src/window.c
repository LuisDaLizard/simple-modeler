#include "window.h"
#include <GLFW/glfw3.h>

static b8 smWindowInitialized = FALSE;
static u8 smWindowCount = 0;

b32
smWindowCreate(smWindow *window, smWindowInfo *info)
{
    assert(window != NULL);
    assert(info != NULL);

    if (!smWindowInitialized)
    {
        if (!glfwInit()) return 0;
        smWindowInitialized = TRUE;
    }

    if (smWindowCount == U8_MAX)
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

    smWindowCount ++;
    return 1;
}

void
smWindowDestroy(smWindow *window)
{
    assert(window);
    assert(window->handle);
    assert(smWindowCount > 0);

    smWindowCount --;
    glfwDestroyWindow(window->handle);
    window->handle = NULL;

    if (!smWindowCount)
    {
        glfwTerminate();
        smWindowInitialized = FALSE;
    }
}

b32
smWindowShouldClose(smWindow *window)
{
    assert(window);
    assert(window->handle);

    glfwPollEvents();
    glfwSwapBuffers(window->handle);
    return glfwWindowShouldClose(window->handle);
}