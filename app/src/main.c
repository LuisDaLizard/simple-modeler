#include <stdio.h>
#include <window.h>
#include <graphics.h>

#include "constants.h"

int main()
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

    while (!smWindowShouldClose(&window))
    {
        smClearColor(BACKGROUND_COLOR);
        smClear(FALSE);
    }

    smWindowDestroy(&window);
    return 0;
}
