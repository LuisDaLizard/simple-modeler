#pragma once

#include "defines.h"
#include "allocator.h"
#include <cglm/struct.h>

typedef struct
{
    const char *vertSource;
    const char *fragSource;
} smShaderInfo;

typedef enum
{
    SHADER_TYPE_INVALID = 0,
    SHADER_TYPE_FLOAT,
    SHADER_TYPE_VEC2,
    SHADER_TYPE_VEC3,
    SHADER_TYPE_VEC4,
    SHADER_TYPE_MAT2,
    SHADER_TYPE_MAT3,
    SHADER_TYPE_MAT4,
} smShaderType;

typedef struct
{
    // char *name;
    i32 count, size;
    smShaderType type;
} smUniform;

typedef struct
{
    i32 count, size, location;
    smShaderType type;
} smAttribute;

typedef struct
{
    i32 count;
    void *uniforms;
} smUniformLayout;

typedef struct
{
    i32 count;
    i32 stride;
    void *attributes;
} smAttributeLayout;

typedef struct
{
    u32 program;
    smUniformLayout uniformLayout;
    smAttributeLayout attributeLayout;
} smShader;

b32
smShaderCreate(smShader *shader, smShaderInfo *info);

void
smShaderDestroy(smShader *shader);

void
smShaderBind(smShader *shader);

void
smShaderSetUniform1i(smShader *shader, const char *name, i32 value);

void
smShaderSetUniform1f(smShader *shader, const char *name, f32 value);

void
smShaderSetUniform2f(smShader *shader, const char *name, vec2s value);

void
smShaderSetUniform3f(smShader *shader, const char *name, vec3s value);

void
smShaderSetUniform4f(smShader *shader, const char *name, vec4s value);

void
smShaderSetUniformMat4(smShader *shader, const char *name, mat4s value);