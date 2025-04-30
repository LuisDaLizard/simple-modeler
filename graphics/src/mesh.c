#include "mesh.h"

b32
smMeshCreate(smMesh *mesh, smMeshInfo *info)
{
    assert(mesh);
    assert(info);
    assert(info->vertexCount);
    assert(info->shader);

    i32 size = info->vertexCount * 4;
    mesh->shader = info->shader;
    mesh->attributes = smShaderGetAttributeLayout(info->shader);

    assert(size % mesh->attributes.stride == 0); // Ensure vertex size matches stride size





    return TRUE;
}

void
smMeshDestroy(smMesh *mesh)
{

}