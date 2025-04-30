#include <stdio.h>

#include "defines.h"

#ifdef WIN32
#include <windows.h>
#endif

void
smQuit(i32 code)
{
#if WIN32 && !DEBUG
    PostQuitMessage(code);
#else
    exit(code);
#endif
}

void
smAssert(b64 condition, const char *function, int line)
{
    if (condition) return;

    fprintf(stdout, "Assertion failed (%s : %d)\n", function, line); // TODO: Logging
    smQuit(0);
}

void
smAssertF(b64 condition, const char *msg, const char *function, int line)
{
    if (condition) return;

    fprintf(stdout, "Assertion failed (%s : %d): %s\n", function, line, msg); // TODO: Logging
    smQuit(0);
}