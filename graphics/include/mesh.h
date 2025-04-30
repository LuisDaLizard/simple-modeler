#pragma once

#include "defines.h"
#include "shader.h"

typedef struct
{
    i32 vertexCount;
    i32 indexCount;

    f32 *vertices;
    u32 *indices;

    smShader *shader;
} smMeshInfo;

typedef struct
{
    u32 vbo, ebo;
    u32 vao;

    i32 vertexCount;
    i32 indexCount;

    smShader *shader;
    smAttributeLayout attributes;
    smUniformLayout uniforms;
} smMesh;

b32
smMeshCreate(smMesh *mesh, smMeshInfo *info);

void
smMeshDestroy(smMesh *mesh);