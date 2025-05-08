#pragma once

#include "defines.h"
#include "texture.h"

#include "memory.h"

typedef struct
{
    smMem nkAtlas;
    void *nkFont;
    smTexture texture;
} smFont;

b32
smFontCreate(smFont *font);

void
smFontDestroy(smFont *font);