#include "graphics.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int
smGraphicsInit()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        return 0;

    glEnable(GL_BLEND);
    glBlendEquation(GL_FUNC_ADD);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);

    return 1;
}

void
smClearColor(const rgba8 color)
{
    f32 r = (f32)color.r / 255.0f;
    f32 g = (f32)color.g / 255.0f;
    f32 b = (f32)color.b / 255.0f;
    f32 a = (f32)color.a / 255.0f;

    glClearColor(r, g, b, a);
}

void
smClearColorF(const rgba32f color)
{
    glClearColor(color.r, color.g, color.b, color.a);
}

void
smClear(b32 depth)
{
    u32 mask = GL_COLOR_BUFFER_BIT;

    if (depth)
        mask |= GL_DEPTH_BUFFER_BIT;

    glClear(mask);
}