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

    // smFont font;
    // smFontCreate(&font);

    const i32 channels = 4;
    const i32 width = 16;
    const i32 height = 16;

    u8 pixels[height][width][channels];
    for (i32 i = 0; i < height; i++)
    {
        for (i32 j = 0; j < width; j++)
        {
            u8 c = ((((i&0x8)==0)^((j&0x8))==0))*255;

            pixels[i][j][0] = c;
            pixels[i][j][1] = c;
            pixels[i][j][2] = c;
            pixels[i][j][3] = 255;
        }
    }

    smTextureInfo textureInfo = {
            WRAP_REPEAT, WRAP_REPEAT,
            FILTER_NEAREST, FILTER_NEAREST,
            width, height, channels,
            pixels
    };

    smTexture texture = {};
    smTextureCreate(&texture, &textureInfo);


    while (!smWindowShouldClose(&window))
    {
        smClearColor(BACKGROUND_COLOR);
        smClear(FALSE);

        smShaderBind(&shader);
        smTextureBind(&texture, 0);
        smMeshDraw(&mesh);
    }

    smWindowDestroy(&window);

    return 0;
}

