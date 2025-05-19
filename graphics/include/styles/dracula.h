#pragma once

#include "style.h"

smStyle smStyleDracula()
{
    smStyle style = {};

    rgba8 background = RGBA8(40, 42, 54, 255);
    rgba8 currentline = RGBA8(68, 71, 90, 255);
    rgba8 foreground = RGBA8(248, 248, 242, 255);
    rgba8 comment = RGBA8(98, 114, 164, 255);
    rgba8 pink = RGBA8(255, 121, 198, 255);
    rgba8 purple = RGBA8(189, 147, 249, 255);
    style.colors[STYLE_COLOR_TEXT] = foreground;
    style.colors[STYLE_COLOR_WINDOW] = background;
    style.colors[STYLE_COLOR_HEADER] = currentline;
    style.colors[STYLE_COLOR_BORDER] = currentline;
    style.colors[STYLE_COLOR_BUTTON] = currentline;
    style.colors[STYLE_COLOR_BUTTON_HOVER] = comment;
    style.colors[STYLE_COLOR_BUTTON_ACTIVE] = purple;
    style.colors[STYLE_COLOR_TOGGLE] = currentline;
    style.colors[STYLE_COLOR_TOGGLE_HOVER] = comment;
    style.colors[STYLE_COLOR_TOGGLE_CURSOR] = pink;
    style.colors[STYLE_COLOR_SELECT] = currentline;
    style.colors[STYLE_COLOR_SELECT_ACTIVE] = comment;
    style.colors[STYLE_COLOR_SLIDER] = background;
    style.colors[STYLE_COLOR_SLIDER_CURSOR] = currentline;
    style.colors[STYLE_COLOR_SLIDER_CURSOR_HOVER] = comment;
    style.colors[STYLE_COLOR_SLIDER_CURSOR_ACTIVE] = comment;
    style.colors[STYLE_COLOR_PROPERTY] = currentline;
    style.colors[STYLE_COLOR_EDIT] = currentline;
    style.colors[STYLE_COLOR_EDIT_CURSOR] = foreground;
    style.colors[STYLE_COLOR_COMBO] = currentline;
    style.colors[STYLE_COLOR_CHART] = currentline;
    style.colors[STYLE_COLOR_CHART_COLOR] = comment;
    style.colors[STYLE_COLOR_CHART_COLOR_HIGHLIGHT] = purple;
    style.colors[STYLE_COLOR_SCROLLBAR] = background;
    style.colors[STYLE_COLOR_SCROLLBAR_CURSOR] = currentline;
    style.colors[STYLE_COLOR_SCROLLBAR_CURSOR_HOVER] = comment;
    style.colors[STYLE_COLOR_SCROLLBAR_CURSOR_ACTIVE] = purple;
    style.colors[STYLE_COLOR_TAB_HEADER] = currentline;
    style.colors[STYLE_COLOR_KNOB] = style.colors[STYLE_COLOR_SLIDER];
    style.colors[STYLE_COLOR_KNOB_CURSOR] = style.colors[STYLE_COLOR_SLIDER_CURSOR];
    style.colors[STYLE_COLOR_KNOB_CURSOR_HOVER] = style.colors[STYLE_COLOR_SLIDER_CURSOR_HOVER];
    style.colors[STYLE_COLOR_KNOB_CURSOR_ACTIVE] = style.colors[STYLE_COLOR_SLIDER_CURSOR_ACTIVE];

    return style;
}