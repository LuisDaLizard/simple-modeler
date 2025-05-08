#include "font.h"
#include "texture.h"

#define NK_IMPLEMENTATION
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#include <nuklear.h>

b32
smFontCreate(smFont *font)
{
    assert(font);

    smAllocate(&font->nkAtlas, sizeof(struct nk_font_atlas), TRUE);
    struct nk_font_atlas *atlas = (struct nk_font_atlas *)font->nkAtlas.ptr;

    nk_font_atlas_init_default(atlas);
    nk_font_atlas_begin(atlas);
    font->nkFont = nk_font_atlas_add_default(atlas, 24, 0);
    i32 width, height;
    const u8 *img = nk_font_atlas_bake(atlas, &width, &height, NK_FONT_ATLAS_ALPHA8);

    // Flip the image TODO: find a more efficient way
    smMem flippedImg = {};
    smAllocate(&flippedImg, width * height, FALSE);

    for (i32 i = 0; i < height; i++)
    {
        for (i32 j = 0; j < width; j++)
        {
            i32 index = i * width + j;
            i32 flippedIndex = (height - i - 1) * width + j;

            ((u8 *)flippedImg.ptr)[flippedIndex] = img[index];
        }
    }

    // Turn the image into a texture
    smTextureInfo textureInfo =
    {
            WRAP_REPEAT, WRAP_REPEAT,
            FILTER_NEAREST, FILTER_NEAREST,
            width, height, 1,
            flippedImg.ptr,
    };

    smTextureCreate(&font->texture, &textureInfo);
    nk_font_atlas_end(atlas, nk_handle_ptr(&font->texture), NULL);
    smRelease(&flippedImg);

    return TRUE;
}

void
smFontDestroy(smFont *font)
{
    assert(font);

    nk_font_atlas_cleanup((struct nk_font_atlas *)&font->nkAtlas.ptr);
    smTextureDestroy(&font->texture);

    smRelease(&font->nkAtlas);
}
