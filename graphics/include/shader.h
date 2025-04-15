#pragma once

#include <defines.h>

typedef struct
{
    const char *vertSource;
    const char *fragSource;
} smShaderInfo;

typedef enum
{

} smUniformType;

typedef struct
{
    i32 count;
    u32 *sizes;
    char *names;
    smUniformType *types;
} smUniformLayout;

typedef struct
{
    u32 program;
    smUniformLayout uniforms;
} smShader;

b32
smShaderCreate(smShader *shader, smShaderInfo *info);

void
smShaderDestroy(smShader *shader);

void
smShaderBind(smShader *shader);

