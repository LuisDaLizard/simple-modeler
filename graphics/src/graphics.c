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
smClearColor(f32 r, f32 g, f32 b)
{
    glClearColor(r, g, b, 1.0f);
}

void
smClear(b32 depth)
{
    u32 mask = GL_COLOR_BUFFER_BIT;

    if (depth)
        mask |= GL_DEPTH_BUFFER_BIT;

    glClear(mask);
}