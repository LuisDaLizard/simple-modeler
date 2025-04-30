#include <window.h>
#include <graphics.h>
#include <shader.h>

#include "constants.h"

#if WIN32
#include <windows.h>
#endif

#if DEBUG
int main(i32 argc, char *argv[])
#elif WIN32
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
#endif
{
    smWindow window = { 0 };
    smWindowInfo settings =
    {
        WINDOW_TITLE,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        TRUE,
    };

    if (!smWindowCreate(&window, &settings))
        return 1;

    if (!smGraphicsInit())
        return 1;

    smShaderInfo shaderInfo =
    {
        "#version 410 core\nlayout(location=0) in vec3 aPosition;\nvoid main() { gl_Position = vec4(aPosition, 0); }",
        "#version 410 core\nout vec4 oColor;\nvoid main() { oColor = vec4(1, 0, 0, 1); }"
    };

    smShader shader = {};

    smShaderCreate(&shader, &shaderInfo);

    while (!smWindowShouldClose(&window))
    {
        smClearColor(BACKGROUND_COLOR);
        smClear(FALSE);
    }

    smWindowDestroy(&window);

    assertf(0, "BRO");

    return 0;
}

