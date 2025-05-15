#pragma once

#include "defines.h"

int
smGraphicsInit();

void
smClearColor(rgba8 color);

void
smClearColorF(rgba32f color);

void
smClear(b32 depth);