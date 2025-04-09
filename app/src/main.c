#include <stdio.h>
#include <window.h>

int main()
{
    smg_window window = { 0 };
    smg_window_info settings =
    {
        "Simple Modeler",
        800, 600,
        TRUE,
    };

    if (!smg_window_create(&window, &settings))
    {
        printf("Failed to create window\n");
        return 1;
    }

    while (!smg_window_should_close(&window))
    {

    }

    smg_window_destroy(&window);
}
