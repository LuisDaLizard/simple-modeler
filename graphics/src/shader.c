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

static i32
smShaderGetUniformLocation(smShader *shader, const char *name);

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

    smFree(shader->uniformLayout.uniforms);
    glDeleteProgram(shader->program);
}

void
smShaderBind(smShader *shader)
{
    assert(shader);
    assert(shader->program);

    glUseProgram(shader->program);
}

void
smShaderSetUniform1i(smShader *shader, const char *name, i32 value)
{
    i32 location = smShaderGetUniformLocation(shader, name);
    if (location < 0) return;

    smShaderBind(shader);
    glUniform1i(location, value);
}

void
smShaderSetUniform1f(smShader *shader, const char *name, f32 value)
{
    i32 location = smShaderGetUniformLocation(shader, name);
    if (location < 0) return;

    smShaderBind(shader);
    glUniform1f(location, value);
}

void
smShaderSetUniform2f(smShader *shader, const char *name, vec2s value)
{
    i32 location = smShaderGetUniformLocation(shader, name);
    if (location < 0) return;

    smShaderBind(shader);
    glUniform2f(location, value.x, value.y);
}

void
smShaderSetUniform3f(smShader *shader, const char *name, vec3s value)
{
    i32 location = smShaderGetUniformLocation(shader, name);
    if (location < 0) return;

    smShaderBind(shader);
    glUniform3f(location, value.x, value.y, value.z);
}

void
smShaderSetUniform4f(smShader *shader, const char *name, vec4s value)
{
    i32 location = smShaderGetUniformLocation(shader, name);
    if (location < 0) return;

    smShaderBind(shader);
    glUniform4f(location, value.x, value.y, value.z, value.w);
}

void
smShaderSetUniformMat4(smShader *shader, const char *name, mat4s value)
{
    i32 location = smShaderGetUniformLocation(shader, name);
    if (location < 0) return;

    smShaderBind(shader);
    glUniformMatrix4fv(location, 1, GL_FALSE, (f32 *)&value);
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
    void *temp;
    i32 bufferSize;

    glGetProgramiv(shader->program, GL_ACTIVE_UNIFORMS, &shader->uniformLayout.count);

    if (shader->uniformLayout.count == 0) return;

    shader->uniformLayout.uniforms = smAlloc(shader->uniformLayout.count * sizeof(smUniform), FALSE);
    glGetProgramiv(shader->program, GL_ACTIVE_UNIFORM_MAX_LENGTH, &bufferSize);
    temp = smAlloc(bufferSize, TRUE);

    smUniform *uniforms = shader->uniformLayout.uniforms;

    for (i32 i = 0; i < shader->uniformLayout.count; i++)
    {
        i32 length;
        u32 type;

        glGetActiveUniform(shader->program, i, bufferSize, &length, &uniforms[i].count, &type, temp);
        uniforms[i].type = smShaderGLShaderType(type);
        uniforms[i].size = smShaderGLShaderTypeSize(type);
    }

    smFree(temp);
}

static void
smShaderAttributeLayout(smShader *shader)
{
    void *name;
    i32 bufferSize;

    shader->attributeLayout.stride = 0;
    glGetProgramiv(shader->program, GL_ACTIVE_ATTRIBUTES, &shader->attributeLayout.count);

    if (shader->attributeLayout.count == 0) return;

    shader->attributeLayout.attributes = smAlloc(shader->attributeLayout.count * sizeof(smAttribute), FALSE);
    glGetProgramiv(shader->program, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &bufferSize);
    name = smAlloc(bufferSize, TRUE);

    smAttribute *attributes = shader->attributeLayout.attributes;

    for (i32 i = 0; i < shader->attributeLayout.count; i++)
    {
        i32 length;
        u32 type;
        i32 count;

        glGetActiveAttrib(shader->program, i, bufferSize, &length, &count, &type, name);
        ((char *)name)[length] = '\0';

        i32 location = glGetAttribLocation(shader->program, name);

        attributes[location].location = location;
        attributes[location].count = count;
        attributes[location].type = smShaderGLShaderType(type);
        attributes[location].size = smShaderGLShaderTypeSize(type);

        shader->attributeLayout.stride += attributes[location].count * attributes[location].size;
    }

    smFree(name);
}

static i32
smShaderGetUniformLocation(smShader *shader, const char *name)
{
    return glGetUniformLocation(shader->program, name);
}