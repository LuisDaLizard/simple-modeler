#include "shader.h"

#include <glad/glad.h>
#include <stdio.h>

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

    // Create Vertex shader
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
        glGetProgramInfoLog(shader->program, 512, NULL, log);

    glGetProgramiv(shader->program, GL_ACTIVE_UNIFORMS, &shader->uniforms.count);

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

    glDeleteProgram(shader->program);
}

void
smShaderBind(smShader *shader)
{
    assert(shader);
    assert(shader->program);

    glUseProgram(shader->program);
}