#include <stdio.h>
#include <window.h>
#include <graphics.h>

int main()
{
    smWindow window = { 0 };
    smWindowInfo settings =
    {
        "Simple Modeler",
        800, 600,
        TRUE,
    };

    if (!smWindowCreate(&window, &settings))
        return 1;

    if (!smGraphicsInit())
        return 1;


    while (!smWindowShouldClose(&window))
    {
        smClearColor(0.08f, 0.1f, 0.15f);
        smClear(FALSE);
    }

    smWindowDestroy(&window);
}
