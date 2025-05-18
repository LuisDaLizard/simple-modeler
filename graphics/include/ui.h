#pragma once

#include "defines.h"
#include "input.h"
#include "memory.h"
#include "font.h"
#include "mesh.h"

typedef struct
{
    smFont font;
    smMem context;
    smMem cmds;
    smShader shader;
    smMesh mesh;
    u32 width, height;
} smUI;

b32 smUICreate(smUI *ui);

void smUIDestroy(smUI *ui);

void smUIHandleInput(smUI *ui, smInput input);

void smUIRender(smUI *ui);