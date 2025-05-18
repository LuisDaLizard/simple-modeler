#include "ui.h"
#include "memory.h"

#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#include <nuklear.h>

#include "shaders/ui.h"
#include "cglm/struct.h"
#include "mesh.h"
#include "glad/glad.h"
#include "graphics.h"
#include <GLFW/glfw3.h>

#define MAX_VERTEX_BUFFER_SIZE (512 * 1024)
#define MAX_ELEMENT_BUFFER_SIZE (128 * 1024)

static int value = 0;
static struct nk_colorf bg;
static b8 closed = FALSE;

b32 smUICreate(smUI *ui)
{
    assert(ui);

    smAllocate(&ui->context, sizeof(struct nk_context), TRUE);
    smAllocate(&ui->cmds, sizeof(struct nk_buffer), TRUE);
    struct nk_context *ctx = (struct nk_context *)ui->context.ptr;
    nk_buffer_init_default(ui->cmds.ptr);

    // TODO: provide a font
    nk_init_default(ctx, 0);

    smFontCreateDefault(&ui->font);

    struct nk_font_atlas *atlas = ui->font.nkAtlas.ptr;
    nk_style_set_font(ctx, &atlas->default_font->handle);

    smShaderInfo shaderInfo =
            {
            DEFAULT_UI_VERTEX_SHADER,
            DEFAULT_UI_FRAGMENT_SHADER,
            };

    smShaderCreate(&ui->shader, &shaderInfo);

    smMeshInfo meshInfo =
            {
            MAX_VERTEX_BUFFER_SIZE,
            NULL,
            MAX_ELEMENT_BUFFER_SIZE / sizeof(u16),
            NULL,
            TRUE,
            TRUE,
            ui->shader.attributeLayout,
            };

    smMeshCreate(&ui->mesh, &meshInfo);

    bg.r = 0.10f, bg.g = 0.18f, bg.b = 0.24f, bg.a = 1.0f;

    return TRUE;
}

void smUIDestroy(smUI *ui)
{
    assert(ui);

    nk_buffer_free(ui->cmds.ptr);
    nk_free(ui->context.ptr);

    smShaderDestroy(&ui->shader);
    smRelease(&ui->cmds);
    smRelease(&ui->context);
}

void smUIHandleInput(smUI *ui, smInput input)
{
    assert(ui);

    struct nk_context *ctx = ui->context.ptr;
    i32 x = (i32)input.mouseState.x;
    i32 y = (i32)input.mouseState.y;

    ui->width = input.width;
    ui->height = input.height;

    nk_input_begin(ctx);

    nk_input_motion(ctx, x, y);
    nk_input_button(ctx, NK_BUTTON_LEFT, x, y, input.mouseState.buttons[MOUSE_BUTTON_LEFT]);
    nk_input_button(ctx, NK_BUTTON_RIGHT, x, y, input.mouseState.buttons[MOUSE_BUTTON_RIGHT]);
    nk_input_button(ctx, NK_BUTTON_MIDDLE, x, y, input.mouseState.buttons[MOUSE_BUTTON_MIDDLE]);

    nk_input_end(ctx);

    // TODO: Test ui code
    if (!closed)
    {
        if (nk_begin(ctx, "Show", nk_rect(0, 0, 230, 250),
                     NK_WINDOW_BORDER|NK_WINDOW_SCALABLE|
                     NK_WINDOW_TITLE | NK_WINDOW_BACKGROUND))
        {
            nk_layout_row_static(ctx, 30, 80, 1);
            if (nk_button_label(ctx, "button"))
                smClearColorF(*(rgba32f*)&bg);

            nk_layout_row_dynamic(ctx, 20, 1);
            nk_label(ctx, "background:", NK_TEXT_LEFT);
            nk_layout_row_dynamic(ctx, 25, 1);
            if (nk_combo_begin_color(ctx, nk_rgb_cf(bg), nk_vec2(nk_widget_width(ctx),400))) {
                nk_layout_row_dynamic(ctx, 120, 1);
                bg = nk_color_picker(ctx, bg, NK_RGBA);
                nk_layout_row_dynamic(ctx, 25, 1);
                bg.r = nk_propertyf(ctx, "#R:", 0, bg.r, 1.0f, 0.01f,0.005f);
                bg.g = nk_propertyf(ctx, "#G:", 0, bg.g, 1.0f, 0.01f,0.005f);
                bg.b = nk_propertyf(ctx, "#B:", 0, bg.b, 1.0f, 0.01f,0.005f);
                bg.a = nk_propertyf(ctx, "#A:", 0, bg.a, 1.0f, 0.01f,0.005f);
                nk_combo_end(ctx);
            }
        }
        else
            closed = TRUE;

        nk_end(ctx);
    }
}

typedef struct
{
    vec2s position;
    vec2s uv;
    vec4s color;
} smUIVertex;

void smUIRender(smUI *ui)
{
    assert(ui);

    const struct nk_draw_command *cmd;
    struct nk_buffer vbuffer, ebuffer;

    void *vertices = smMeshMapVertexBuffer(&ui->mesh);
    void *indices = smMeshMapIndexBuffer(&ui->mesh);

    struct nk_convert_config config = {};
    static const struct nk_draw_vertex_layout_element vertex_layout[] =
            {
                    {NK_VERTEX_POSITION, NK_FORMAT_FLOAT, NK_OFFSETOF(smUIVertex, position)},
                    {NK_VERTEX_TEXCOORD, NK_FORMAT_FLOAT, NK_OFFSETOF(smUIVertex, uv)},
                    {NK_VERTEX_COLOR, NK_FORMAT_R32G32B32A32_FLOAT, NK_OFFSETOF(smUIVertex, color)},
                    {NK_VERTEX_LAYOUT_END}
            };

    config.vertex_layout = vertex_layout;
    config.vertex_size = sizeof(smUIVertex);
    config.vertex_alignment = NK_ALIGNOF(smUIVertex);
    config.tex_null = *(struct nk_draw_null_texture *)ui->font.nkTextureNull.ptr;
    config.circle_segment_count = 22;
    config.curve_segment_count = 22;
    config.arc_segment_count = 22;
    config.global_alpha = 1.0f;
    config.shape_AA = NK_ANTI_ALIASING_ON;
    config.line_AA = NK_ANTI_ALIASING_ON;

    nk_buffer_init_fixed(&vbuffer, vertices, MAX_VERTEX_BUFFER_SIZE);
    nk_buffer_init_fixed(&ebuffer, indices, MAX_ELEMENT_BUFFER_SIZE);
    nk_convert(ui->context.ptr, ui->cmds.ptr, &vbuffer, &ebuffer, &config);

    smMeshUnmapVertexBuffer(&ui->mesh);
    smMeshUnmapIndexBuffer(&ui->mesh);

    mat4s projection = glms_ortho(0, (f32)ui->width, (f32)ui->height, 0, -1, 1);

    smShaderSetUniformMat4(&ui->shader, "uProjection", projection);
    smShaderBind(&ui->shader);

    u32 offset = 0;
    nk_draw_foreach(cmd, ui->context.ptr, ui->cmds.ptr)
    {
        if (!cmd->elem_count) continue;

        smTexture *texture = cmd->texture.ptr;
        smTextureBind(texture, 0);

        glDrawElements(GL_TRIANGLES, cmd->elem_count, GL_UNSIGNED_SHORT, (const void *) offset);

        offset += cmd->elem_count * sizeof(nk_draw_index);
    }


    nk_clear(ui->context.ptr);
    nk_buffer_clear(ui->cmds.ptr);
}