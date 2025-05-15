#include "window.h"

#define GL_SILENCE_DEPRECATION
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>

static b8 smWindowInitialized = FALSE;
static u8 smWindowCount = 0;

static void smWindowCursorPosCallback(GLFWwindow *handle, f64 x, f64 y);
static void smWindowMouseButtonCallback(GLFWwindow *handle, int button, int action, int mods);

b32 smWindowCreate(smWindow *window, smWindowInfo *info)
{
    assert(window);
    assert(info);

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
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, info->resizable);

    window->handle = glfwCreateWindow(info->width, info->height, info->title, NULL, NULL);

    if (!window->handle)
        return 0;

    window->input = (smInput){ 0 };

    glfwMakeContextCurrent(window->handle);
    glfwSetWindowUserPointer(window->handle, window);
    glfwSwapInterval(1);

    // Set window callbacks
    glfwSetCursorPosCallback(window->handle, smWindowCursorPosCallback);
    glfwSetMouseButtonCallback(window->handle, smWindowMouseButtonCallback);

    smWindowCount ++;
    return 1;
}

void smWindowDestroy(smWindow *window)
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

b32 smWindowShouldClose(smWindow *window)
{
    assert(window);
    assert(window->handle);

    glfwSwapBuffers(window->handle);

    int width, height;
    glfwGetFramebufferSize(window->handle, &width, &height);
    glViewport(0, 0, width, height);
    smInputNewFrame(&window->input);
    glfwPollEvents();

    return glfwWindowShouldClose(window->handle);
}

smInput smWindowGetInput(smWindow *window)
{
    assert(window);
    assert(window->handle);

    return window->input;
}

static void smWindowCursorPosCallback(GLFWwindow *handle, f64 x, f64 y)
{
    smWindow *window = (smWindow *)glfwGetWindowUserPointer(handle);

    window->input.mouseState.x = (f32)x;
    window->input.mouseState.y = (f32)y;
}

static void smWindowMouseButtonCallback(GLFWwindow *handle, i32 button, i32 action, i32 mods)
{
    smWindow *window = (smWindow *)glfwGetWindowUserPointer(handle);

    if (button < MOUSE_BUTTON_MAX)
        window->input.mouseState.buttons[button] = (b8)action;
}