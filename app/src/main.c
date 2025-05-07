#include <window.h>
#include <graphics.h>
#include <mesh.h>
#include <texture.h>

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

    u8 data[3] = {0x1A, 0xFF, 0x1A };

    smTextureInfo textureInfo =
    {
            WRAP_REPEAT,
            WRAP_REPEAT,
            FILTER_NEAREST,
            FILTER_NEAREST,
            1, 1, 3,
            data,
    };

    smTexture texture = {};
    smTextureCreate(&texture, &textureInfo);

    while (!smWindowShouldClose(&window))
    {
        smClearColor(BACKGROUND_COLOR);
        smClear(FALSE);

        smTextureBind(&texture, 0);
        smShaderBind(&shader);
        smMeshDraw(&mesh);
    }

    smWindowDestroy(&window);

    return 0;
}

