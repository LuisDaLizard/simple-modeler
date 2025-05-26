#include "mesh.h"

#include <glad/glad.h>

b32
smMeshCreate(smMesh *mesh, smMeshInfo *info)
{
    assert(mesh);
    assert(info);
    assert(info->vertexDataSize);
    assert(info->layout.stride);
    assert(info->vertexDataSize % info->layout.stride == 0);

    mesh->vertexCount = (i32)(info->vertexDataSize / info->layout.stride);
    mesh->layout = info->layout;
    mesh->indexCount = info->indexCount;

    glGenVertexArrays(1, &mesh->vao);
    glGenBuffers(1, &mesh->vbo);

    glBindVertexArray(mesh->vao);
    glBindBuffer(GL_ARRAY_BUFFER, mesh->vbo);
    glBufferData(GL_ARRAY_BUFFER, info->vertexDataSize, info->vertices, info->streamVertex ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);

    if (info->indexCount > 0)
    {
        glGenBuffers(1, &mesh->ebo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, info->indexCount * sizeof(u32), info->indices, info->streamIndex ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
    }

    u64 offset = 0;
    for (i32 i = 0; i < info->layout.count; i++)
    {
        smAttribute attrib = ((smAttribute *)mesh->layout.attributes)[i];
        u32 components = attrib.size / sizeof(f32);

        glVertexAttribPointer(attrib.location, (i32)components, GL_FLOAT, GL_FALSE, mesh->layout.stride, (void *)offset);
        glEnableVertexAttribArray(attrib.location);

        offset += components * sizeof(f32);
    }

    glBindVertexArray(0);

    return TRUE;
}

void
smMeshDestroy(smMesh *mesh)
{
    if (mesh->indexCount > 0) glDeleteBuffers(1, &mesh->ebo);
    glDeleteBuffers(1, &mesh->vbo);
    glDeleteVertexArrays(1, &mesh->vao);
}

void
smMeshDraw(smMesh *mesh)
{
    glBindVertexArray(mesh->vao);

    if (mesh->indexCount > 0)
        glDrawElements(GL_TRIANGLES, mesh->indexCount, GL_UNSIGNED_INT, 0);
    else
        glDrawArrays(GL_TRIANGLES, 0, mesh->vertexCount);

    glBindVertexArray(0);
}

void *
smMeshMapVertexBuffer(smMesh *mesh)
{
    glBindVertexArray(mesh->vao);
    void *handle = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
    return handle;
}

void
smMeshUnmapVertexBuffer(smMesh *mesh)
{
    glBindVertexArray(mesh->vao);
    glUnmapBuffer(GL_ARRAY_BUFFER);
}

void *
smMeshMapIndexBuffer(smMesh *mesh)
{
    glBindVertexArray(mesh->vao);
    void *handle = glMapBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_WRITE_ONLY);
    return handle;
}

void
smMeshUnmapIndexBuffer(smMesh *mesh)
{
    glBindVertexArray(mesh->vao);
    glUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER);
}