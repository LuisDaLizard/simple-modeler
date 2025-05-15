#pragma once

#include "defines.h"
#include "texture.h"

#include "memory.h"

typedef struct
{
    smMem nkAtlas;
    void *nkFont;
    smMem nkTextureNull;
    smTexture texture;
} smFont;

b32
smFontCreateDefault(smFont *font);

void
smFontDestroy(smFont *font);