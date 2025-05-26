#include <window.h>
#include <graphics.h>
#include <mesh.h>
#include <font.h>
#include <printf.h>

#include "constants.h"
#include "shaders.h"
#include "ui.h"
#include "styles/dark.h"
#include "styles/light.h"
#include "styles/dracula.h"
#include "styles/catppuccin_latte.h"

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

    smUI ui = {};
    smUICreate(&ui);
    smUISetStyle(&ui, smStyleDracula());

    smClearColor(BACKGROUND_COLOR);

    while (!smWindowShouldClose(&window))
    {
        smInput input = smWindowGetInput(&window);
        smUIHandleInput(&ui, input);

        smUITest(&ui);

        smClear(FALSE);

        smUIRender(&ui);
    }

    smUIDestroy(&ui);
    smWindowDestroy(&window);

    return 0;
}

