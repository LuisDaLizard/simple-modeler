#include "graphics.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int
smGraphicsInit()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        return 0;

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
smClear(b32 depth)
{
    u32 mask = GL_COLOR_BUFFER_BIT;

    if (depth)
        mask |= GL_DEPTH_BUFFER_BIT;

    glClear(mask);
}