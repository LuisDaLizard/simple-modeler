#pragma once

#include "defines.h"
#include "shader.h"

typedef struct
{
    u32 vertexDataSize;
    f32 *vertices;

    i32 indexCount;
    u32 *indices;

    b8 dynamicVertex;
    b8 dynamicIndex;

    smAttributeLayout layout;
} smMeshInfo;

typedef struct
{
    u32 vao;
    u32 vbo;
    u32 ebo;

    i32 vertexCount;
    i32 indexCount;

    smAttributeLayout layout;
} smMesh;

b32
smMeshCreate(smMesh *mesh, smMeshInfo *info);

void
smMeshDestroy(smMesh *mesh);

void
smMeshDraw(smMesh *mesh);

void
smMeshSetVertexData(smMesh *mesh, f32 *data, u32 size, u32 offset);

void
smMeshSetIndexData(smMesh *mesh, u32 *data, u32 size, u32 offset);