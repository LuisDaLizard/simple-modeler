#include <window.h>
#include <graphics.h>
#include <mesh.h>
#include <font.h>
#include <printf.h>

#include "constants.h"
#include "shaders.h"

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
            DEFAULT_VERTEX_SHADER,
            DEFAULT_FRAGMENT_SHADER
    };

    smShader shader = {};
    smShaderCreate(&shader, &shaderInfo);

    smMeshInfo meshInfo =
    {
            sizeof(VERTICES),
            VERTICES,
            shader.attributeLayout
    };

    smMesh mesh = {};
    smMeshCreate(&mesh, &meshInfo);

    smFont font;
    smFontCreate(&font);

    while (!smWindowShouldClose(&window))
    {
        smClearColor(BACKGROUND_COLOR);
        smClear(FALSE);

        smShaderBind(&shader);
        smTextureBind(&font.texture, 0);
        smMeshDraw(&mesh);
    }

    smWindowDestroy(&window);

    return 0;
}

