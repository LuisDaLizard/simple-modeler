#include "shader.h"

#include <glad/glad.h>
#include <stdio.h>

static smShaderType
smShaderGLShaderType(u32 glType);

static i32
smShaderGLShaderTypeSize(u32 glType);

static void
smShaderUniformLayout(smShader *shader);

static void
smShaderAttributeLayout(smShader *shader);

b32
smShaderCreate(smShader *shader, smShaderInfo *info)
{
    assert(shader);
    assert(shader->program == 0);
    assert(info);
    assert(info->vertSource);
    assert(info->fragSource);

    u32 vertex = 0, fragment = 0;
    i32 success = TRUE;
    char log[512];

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &info->vertSource, NULL);
    glCompileShader(vertex);
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(vertex, 512, NULL, log);
        goto end;
    }

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &info->fragSource, NULL);
    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(fragment, 512, NULL, log);
        goto end;
    }

    shader->program = glCreateProgram();
    glAttachShader(shader->program, vertex);
    glAttachShader(shader->program, fragment);
    glLinkProgram(shader->program);
    glGetProgramiv(shader->program, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(shader->program, 512, NULL, log);
        goto end;
    }

    smShaderUniformLayout(shader);
    smShaderAttributeLayout(shader);

end:
    glDeleteShader(vertex);
    glDeleteShader(fragment);

    if (!success)
    {
        glDeleteProgram(shader->program);
        printf("Shader creation failed: %s\n", log); // TODO: Temporary
    }

    return success;
}

void
smShaderDestroy(smShader *shader)
{
    assert(shader);
    assert(shader->program);

    smRelease(&shader->uniformLayout.uniforms);
    glDeleteProgram(shader->program);
}

void
smShaderBind(smShader *shader)
{
    assert(shader);
    assert(shader->program);

    glUseProgram(shader->program);
}

smUniformLayout
smShaderGetUniformLayout(const smShader *shader)
{
    return shader->uniformLayout;
}

smAttributeLayout
smShaderGetAttributeLayout(const smShader *shader)
{
    return shader->attributeLayout;
}

static smShaderType
smShaderGLShaderType(u32 glType)
{
    switch (glType)
    {
        case GL_FLOAT:
            return SHADER_TYPE_FLOAT;
        case GL_FLOAT_VEC2:
            return SHADER_TYPE_VEC2;
        case GL_FLOAT_VEC3:
            return SHADER_TYPE_VEC3;
        case GL_FLOAT_VEC4:
            return SHADER_TYPE_VEC4;
        case GL_FLOAT_MAT2:
            return SHADER_TYPE_MAT2;
        case GL_FLOAT_MAT3:
            return SHADER_TYPE_MAT3;
        case GL_FLOAT_MAT4:
            return SHADER_TYPE_MAT4;

        default:
            return SHADER_TYPE_INVALID;
    }
}

static i32
smShaderGLShaderTypeSize(u32 glType)
{
    switch (glType)
    {
        case GL_FLOAT:
            return 4;
        case GL_FLOAT_VEC2:
            return 8;
        case GL_FLOAT_VEC3:
            return 12;
        case GL_FLOAT_VEC4:
        case GL_FLOAT_MAT2:
            return 16;
        case GL_FLOAT_MAT3:
            return 36;
        case GL_FLOAT_MAT4:
            return 64;

        default:
            return -1;
    }
}

static void
smShaderUniformLayout(smShader *shader)
{
    smMem temp = { 0 };
    i32 bufferSize;

    glGetProgramiv(shader->program, GL_ACTIVE_UNIFORMS, &shader->uniformLayout.count);

    if (shader->uniformLayout.count == 0) return;

    smAllocate(&shader->uniformLayout.uniforms, shader->uniformLayout.count * sizeof(smUniform), FALSE);
    glGetProgramiv(shader->program, GL_ACTIVE_UNIFORM_MAX_LENGTH, &bufferSize);
    smAllocate(&temp, bufferSize, TRUE);

    smUniform *uniforms = shader->uniformLayout.uniforms.ptr;

    for (i32 i = 0; i < shader->uniformLayout.count; i++)
    {
        i32 length;
        u32 type;

        glGetActiveUniform(shader->program, i, bufferSize, &length, &uniforms[i].count, &type, temp.ptr);
        uniforms[i].type = smShaderGLShaderType(type);
        uniforms[i].size = smShaderGLShaderTypeSize(type);
    }

    smRelease(&temp);
}

static void
smShaderAttributeLayout(smShader *shader)
{
    smMem name = { 0 };
    i32 bufferSize;

    shader->attributeLayout.stride = 0;
    glGetProgramiv(shader->program, GL_ACTIVE_ATTRIBUTES, &shader->attributeLayout.count);

    if (shader->attributeLayout.count == 0) return;

    smAllocate(&shader->attributeLayout.attributes, shader->attributeLayout.count * sizeof(smAttribute), FALSE);
    glGetProgramiv(shader->program, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &bufferSize);
    smAllocate(&name, bufferSize, TRUE);

    smAttribute *attributes = shader->attributeLayout.attributes.ptr;

    for (i32 i = 0; i < shader->attributeLayout.count; i++)
    {
        i32 length;
        u32 type;
        i32 count;

        glGetActiveAttrib(shader->program, i, bufferSize, &length, &count, &type, name.ptr);
        ((char *)name.ptr)[length] = '\0';

        i32 location = glGetAttribLocation(shader->program, name.ptr);

        attributes[location].location = location;
        attributes[location].count = count;
        attributes[location].type = smShaderGLShaderType(type);
        attributes[location].size = smShaderGLShaderTypeSize(type);

        shader->attributeLayout.stride += attributes[location].count * attributes[location].size;
    }

    smRelease(&name);
}