#include "texture.h"

#include <glad/glad.h>

b32
smTextureCreate(smTexture *texture, smTextureInfo *info)
{
    assert(texture);
    assert(info);
    assert(info->data);
    assert(info->width > 0);
    assert(info->height > 0);
    assert(info->channels > 0);

    texture->width = info->width;
    texture->height = info->height;

    i32 sizedFormat, format;

    switch(info->channels)
    {
        case 1:
            sizedFormat = GL_R8;
            format = GL_RED;
            break;
        case 3:
            sizedFormat = GL_RGB8;
            format = GL_RGB;
            break;
        case 4:
            sizedFormat = GL_RGBA8;
            format = GL_RGBA;
            break;
        default:
            return FALSE;
    }

    texture->channels = info->channels;

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glGenTextures(1, &texture->id);
    glBindTexture(GL_TEXTURE_2D, texture->id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, sizedFormat, info->width, info->height, 0, format, GL_UNSIGNED_BYTE, info->data);

    glBindTexture(GL_TEXTURE_2D, 0);
    return TRUE;
}


void
smTextureDestroy(smTexture *texture)
{
    assert(texture);
    assert(texture->id);

    glDeleteTextures(1, &texture->id);

    texture->id = 0;
    texture->width = 0;
    texture->height = 0;
    texture->channels = 0;
}

void
smTextureBind(smTexture *texture, u32 slot)
{
    assert(texture);
    assert(texture->id);
    assert(slot < 32);

    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, texture->id);
}
