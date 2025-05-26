#pragma once

#include "defines.h"
#include "input.h"
#include "memory.h"
#include "font.h"
#include "mesh.h"
#include "styles/style.h"

typedef struct
{
    smFont font;
    void *nkContext;
    void *nkCmds;
    smShader shader;
    smMesh mesh;
    u32 width, height;
    f32 scaleX, scaleY;
} smUI;

typedef enum
{
    UI_WINDOW_BORDER            = FLAG(0),
    UI_WINDOW_MOVABLE           = FLAG(1),
    UI_WINDOW_SCALABLE          = FLAG(2),
    UI_WINDOW_CLOSABLE          = FLAG(3),
    UI_WINDOW_MINIMIZABLE       = FLAG(4),
    UI_WINDOW_NO_SCROLLBAR      = FLAG(5),
    UI_WINDOW_TITLE             = FLAG(6),
    UI_WINDOW_SCROLL_AUTO_HIDE  = FLAG(7),
    UI_WINDOW_BACKGROUND        = FLAG(8),
    UI_WINDOW_SCALE_LEFT        = FLAG(9),
    UI_WINDOW_NO_INPUT          = FLAG(10)
} smUIWindowFlags;

typedef enum
{
    UI_TEXT_ALIGN_LEFT          = FLAG(0),
    UI_TEXT_ALIGN_CENTER        = FLAG(1),
    UI_TEXT_ALIGN_RIGHT         = FLAG(2),
    UI_TEXT_ALIGN_TOP           = FLAG(3),
    UI_TEXT_ALIGN_MIDDLE        = FLAG(4),
    UI_TEXT_ALIGN_BOTTOM        = FLAG(5)
} smUITextAlignmentFlags;

b32 smUICreate(smUI *ui);

void smUIDestroy(smUI *ui);

void smUIHandleInput(smUI *ui, smInput input);

void smUIRender(smUI *ui);

void smUISetStyle(smUI *ui, smStyle style);

b32 smUIBegin(smUI *ui, const char *title, vec2s position, vec2s size, smUIWindowFlags flags);

void smUIEnd(smUI *ui);

f32 smUIWidgetWidth(smUI *ui);

f32 smUIWidgetHeight(smUI *ui);

void smUILayoutRowStatic(smUI *ui, f32 height, i32 itemWidth, i32 columns);

void smUILayoutRowDynamic(smUI *ui, f32 height, i32 columns);

b32 smUIButtonLabel(smUI *ui, const char *title);

void smUILabel(smUI *ui, const char *title, smUITextAlignmentFlags alignment);

b32 smUIComboBeginColor(smUI *ui, rgba8 color, vec2s size);

void smUIComboEnd(smUI *ui);

rgba8 smUIColorPicker(smUI *ui, rgba8 color);

b32 smUIOptionLabel(smUI *ui, const char *title, b32 selected);

int smUITest(smUI *ui);