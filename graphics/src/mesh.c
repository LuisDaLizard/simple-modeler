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

    mesh->vertexCount = info->vertexDataSize / info->layout.stride;
    mesh->layout = info->layout;

    glGenVertexArrays(1, &mesh->vao);
    glGenBuffers(1, &mesh->vbo);

    glBindVertexArray(mesh->vao);
    glBindBuffer(GL_ARRAY_BUFFER, mesh->vbo);
    glBufferData(GL_ARRAY_BUFFER, info->vertexDataSize, info->vertices, GL_STATIC_DRAW);

    u64 offset = 0;
    for (i32 i = 0; i < info->layout.count; i++)
    {
        smAttribute attrib = ((smAttribute *)mesh->layout.attributes.ptr)[i];
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

}

void
smMeshDraw(smMesh *mesh)
{
    glBindVertexArray(mesh->vao);

    glDrawArrays(GL_TRIANGLES, 0, mesh->vertexCount);

    glBindVertexArray(0);
}