#pragma once

#include "defines.h"
#include "shader.h"

typedef struct
{
    u32 vertexDataSize;
    f32 *vertices;

    i32 indexCount;
    u32 *indices;

    b8 streamVertex;
    b8 streamIndex;

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

void *
smMeshMapVertexBuffer(smMesh *mesh);

void
smMeshUnmapVertexBuffer(smMesh *mesh);

void *
smMeshMapIndexBuffer(smMesh *mesh);

void
smMeshUnmapIndexBuffer(smMesh *mesh);