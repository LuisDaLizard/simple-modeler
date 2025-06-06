#pragma once

#include "defines.h"

typedef enum
{
    STYLE_COLOR_TEXT,
    STYLE_COLOR_WINDOW,
    STYLE_COLOR_HEADER,
    STYLE_COLOR_BORDER,
    STYLE_COLOR_BUTTON,
    STYLE_COLOR_BUTTON_HOVER,
    STYLE_COLOR_BUTTON_ACTIVE,
    STYLE_COLOR_TOGGLE,
    STYLE_COLOR_TOGGLE_HOVER,
    STYLE_COLOR_TOGGLE_CURSOR,
    STYLE_COLOR_SELECT,
    STYLE_COLOR_SELECT_ACTIVE,
    STYLE_COLOR_SLIDER,
    STYLE_COLOR_SLIDER_CURSOR,
    STYLE_COLOR_SLIDER_CURSOR_HOVER,
    STYLE_COLOR_SLIDER_CURSOR_ACTIVE,
    STYLE_COLOR_PROPERTY,
    STYLE_COLOR_EDIT,
    STYLE_COLOR_EDIT_CURSOR,
    STYLE_COLOR_COMBO,
    STYLE_COLOR_CHART,
    STYLE_COLOR_CHART_COLOR,
    STYLE_COLOR_CHART_COLOR_HIGHLIGHT,
    STYLE_COLOR_SCROLLBAR,
    STYLE_COLOR_SCROLLBAR_CURSOR,
    STYLE_COLOR_SCROLLBAR_CURSOR_HOVER,
    STYLE_COLOR_SCROLLBAR_CURSOR_ACTIVE,
    STYLE_COLOR_TAB_HEADER,
    STYLE_COLOR_KNOB,
    STYLE_COLOR_KNOB_CURSOR,
    STYLE_COLOR_KNOB_CURSOR_HOVER,
    STYLE_COLOR_KNOB_CURSOR_ACTIVE,
    STYLE_COLOR_COUNT
} smStyleColor;

typedef struct
{
    rgba8 colors[STYLE_COLOR_COUNT];
} smStyle;