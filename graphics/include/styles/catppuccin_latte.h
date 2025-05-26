#pragma once

#include "style.h"

smStyle smStyleCatppuccinLatte()
{
    smStyle style = {};

    rgba8 pink = RGBA8(234, 118, 203, 255);
    rgba8 mauve = RGBA8(136, 57, 239, 255);
    rgba8 yellow = RGBA8(223, 142, 29, 255);
    rgba8 teal = RGBA8(23, 146, 153, 255);
    rgba8 text = RGBA8(76, 79, 105, 255);
    rgba8 overlay2 = RGBA8(124, 127, 147, 55);
    rgba8 overlay0 = RGBA8(156, 160, 176, 255);
    rgba8 surface2 = RGBA8(172, 176, 190, 255);
    rgba8 surface1 = RGBA8(188, 192, 204, 255);
    rgba8 surface0 = RGBA8(204, 208, 218, 255);
    rgba8 base = RGBA8(239, 241, 245, 255);
    rgba8 mantle = RGBA8(230, 233, 239, 255);
    style.colors[STYLE_COLOR_TEXT] = text;
    style.colors[STYLE_COLOR_WINDOW] = base;
    style.colors[STYLE_COLOR_HEADER] = mantle;
    style.colors[STYLE_COLOR_BORDER] = mantle;
    style.colors[STYLE_COLOR_BUTTON] = surface0;
    style.colors[STYLE_COLOR_BUTTON_HOVER] = overlay2;
    style.colors[STYLE_COLOR_BUTTON_ACTIVE] = overlay0;
    style.colors[STYLE_COLOR_TOGGLE] = surface2;
    style.colors[STYLE_COLOR_TOGGLE_HOVER] = overlay2;
    style.colors[STYLE_COLOR_TOGGLE_CURSOR] = yellow;
    style.colors[STYLE_COLOR_SELECT] = surface0;
    style.colors[STYLE_COLOR_SELECT_ACTIVE] = overlay0;
    style.colors[STYLE_COLOR_SLIDER] = surface1;
    style.colors[STYLE_COLOR_SLIDER_CURSOR] = teal;
    style.colors[STYLE_COLOR_SLIDER_CURSOR_HOVER] = teal;
    style.colors[STYLE_COLOR_SLIDER_CURSOR_ACTIVE] = teal;
    style.colors[STYLE_COLOR_PROPERTY] = surface0;
    style.colors[STYLE_COLOR_EDIT] = surface0;
    style.colors[STYLE_COLOR_EDIT_CURSOR] = mauve;
    style.colors[STYLE_COLOR_COMBO] = surface0;
    style.colors[STYLE_COLOR_CHART] = surface0;
    style.colors[STYLE_COLOR_CHART_COLOR] = teal;
    style.colors[STYLE_COLOR_CHART_COLOR_HIGHLIGHT] = mauve;
    style.colors[STYLE_COLOR_SCROLLBAR] = surface0;
    style.colors[STYLE_COLOR_SCROLLBAR_CURSOR] = overlay0;
    style.colors[STYLE_COLOR_SCROLLBAR_CURSOR_HOVER] = mauve;
    style.colors[STYLE_COLOR_SCROLLBAR_CURSOR_ACTIVE] = mauve;
    style.colors[STYLE_COLOR_TAB_HEADER] = surface0;
    style.colors[STYLE_COLOR_KNOB] = style.colors[STYLE_COLOR_SLIDER];
    style.colors[STYLE_COLOR_KNOB_CURSOR] = pink;
    style.colors[STYLE_COLOR_KNOB_CURSOR_HOVER] = pink;
    style.colors[STYLE_COLOR_KNOB_CURSOR_ACTIVE] = pink;

    return style;
}