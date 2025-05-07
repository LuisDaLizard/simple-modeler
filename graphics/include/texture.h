#pragma once

#include "defines.h"

typedef enum
{
    WRAP_REPEAT,
    WRAP_MIRRORED_REPEAT,
    WRAP_CLAMP_TO_EDGE,
    WRAP_CLAMP_TO_BORDER,
} smTextureWrap;

typedef enum
{
    FILTER_NEAREST,
    FILTER_LINEAR,
} smTextureFilter;

typedef struct
{
    smTextureWrap wrapS, wrapT;
    smTextureFilter filterMin, filterMag;

    i32 width, height, channels;
    u8 *data;
} smTextureInfo;

typedef struct
{
    i32 width, height, channels;
    u32 id;
} smTexture;

b32
smTextureCreate(smTexture *texture, smTextureInfo *info);

void
smTextureDestroy(smTexture *texture);

void
smTextureBind(smTexture *texture, u32 slot);