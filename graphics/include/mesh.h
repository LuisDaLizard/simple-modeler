#pragma once

#include "defines.h"
#include "shader.h"

typedef struct
{
    u32 vertexDataSize;
    f32 *vertices;

    smAttributeLayout layout;
} smMeshInfo;

typedef struct
{
    u32 vao;
    u32 vbo;

    i32 vertexCount;

    smAttributeLayout layout;
} smMesh;

b32
smMeshCreate(smMesh *mesh, smMeshInfo *info);

void
smMeshDestroy(smMesh *mesh);

void
smMeshDraw(smMesh *mesh);