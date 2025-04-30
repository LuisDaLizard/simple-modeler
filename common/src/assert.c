#include <stdio.h>

#include "defines.h"

#ifdef WIN32
#include <windows.h>
#endif

void
smAssert(b32 condition)
{
    if (condition) return;

    PostQuitMessage(0);
}

void
smAssertF(b32 condition, const char *format, ...)
{
    if (condition) return;

    char buffer[MESSAGE_BUFFER_MAX];

    va_list args;
    va_start(args, format);
    vsprintf_s(buffer, MESSAGE_BUFFER_MAX, format, args);
    va_end(args);

    MessageBoxA(0, buffer, NULL, MB_ABORTRETRYIGNORE | MB_ICONERROR);

    PostQuitMessage(0);
}