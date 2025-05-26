#pragma once

#include "defines.h"
#include "texture.h"
#include "allocator.h"

typedef struct
{
    void *nkAtlas;
    void *nkFont;
    void *nkTextureNull;
    smTexture texture;
} smFont;

b32
smFontCreateDefault(smFont *font);

void
smFontDestroy(smFont *font);