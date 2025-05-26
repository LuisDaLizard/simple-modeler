#include "font.h"
#include "texture.h"

#define NK_IMPLEMENTATION
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#include <nuklear.h>

b32
smFontCreateDefault(smFont *font)
{
    assert(font);

    font->nkAtlas = smAlloc(sizeof(struct nk_font_atlas), TRUE);
    font->nkTextureNull = smAlloc(sizeof(struct nk_draw_null_texture), TRUE);
    struct nk_font_atlas *atlas = (struct nk_font_atlas *)font->nkAtlas;
    struct nk_draw_null_texture *null = (struct nk_draw_null_texture *)font->nkTextureNull;

    nk_font_atlas_init_default(atlas);
    nk_font_atlas_begin(atlas);
    font->nkFont = nk_font_atlas_add_default(atlas, 16, 0);
    atlas->default_font = font->nkFont;
    i32 width, height;
    const u8 *img = nk_font_atlas_bake(atlas, &width, &height, NK_FONT_ATLAS_RGBA32);

    // Turn the image into a texture
    smTextureInfo textureInfo =
    {
            WRAP_REPEAT, WRAP_REPEAT,
            FILTER_NEAREST, FILTER_NEAREST,
            width, height, 4,
            img,
    };

    smTextureCreate(&font->texture, &textureInfo);
    nk_font_atlas_end(atlas, nk_handle_ptr(&font->texture), null);

    return TRUE;
}

void
smFontDestroy(smFont *font)
{
    assert(font);

    nk_font_atlas_cleanup(font->nkAtlas);
    smTextureDestroy(&font->texture);

    smFree(font->nkAtlas);
    smFree(font->nkTextureNull);
}
