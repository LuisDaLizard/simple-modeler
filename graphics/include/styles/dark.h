#pragma once

#include "style.h"

smStyle smStyleDark()
{
    smStyle style = {};

    style.colors[STYLE_COLOR_TEXT] = RGBA8(210, 210, 210, 255);
    style.colors[STYLE_COLOR_WINDOW] = RGBA8(57, 67, 71, 215);
    style.colors[STYLE_COLOR_HEADER] = RGBA8(51, 51, 56, 220);
    style.colors[STYLE_COLOR_BORDER] = RGBA8(46, 46, 46, 255);
    style.colors[STYLE_COLOR_BUTTON] = RGBA8(48, 83, 111, 255);
    style.colors[STYLE_COLOR_BUTTON_HOVER] = RGBA8(58, 93, 121, 255);
    style.colors[STYLE_COLOR_BUTTON_ACTIVE] = RGBA8(63, 98, 126, 255);
    style.colors[STYLE_COLOR_TOGGLE] = RGBA8(50, 58, 61, 255);
    style.colors[STYLE_COLOR_TOGGLE_HOVER] = RGBA8(45, 53, 56, 255);
    style.colors[STYLE_COLOR_TOGGLE_CURSOR] = RGBA8(48, 83, 111, 255);
    style.colors[STYLE_COLOR_SELECT] = RGBA8(57, 67, 61, 255);
    style.colors[STYLE_COLOR_SELECT_ACTIVE] = RGBA8(48, 83, 111, 255);
    style.colors[STYLE_COLOR_SLIDER] = RGBA8(50, 58, 61, 255);
    style.colors[STYLE_COLOR_SLIDER_CURSOR] = RGBA8(48, 83, 111, 245);
    style.colors[STYLE_COLOR_SLIDER_CURSOR_HOVER] = RGBA8(53, 88, 116, 255);
    style.colors[STYLE_COLOR_SLIDER_CURSOR_ACTIVE] = RGBA8(58, 93, 121, 255);
    style.colors[STYLE_COLOR_PROPERTY] = RGBA8(50, 58, 61, 255);
    style.colors[STYLE_COLOR_EDIT] = RGBA8(50, 58, 61, 225);
    style.colors[STYLE_COLOR_EDIT_CURSOR] = RGBA8(210, 210, 210, 255);
    style.colors[STYLE_COLOR_COMBO] = RGBA8(50, 58, 61, 255);
    style.colors[STYLE_COLOR_CHART] = RGBA8(50, 58, 61, 255);
    style.colors[STYLE_COLOR_CHART_COLOR] = RGBA8(48, 83, 111, 255);
    style.colors[STYLE_COLOR_CHART_COLOR_HIGHLIGHT] = RGBA8(255, 0, 0, 255);
    style.colors[STYLE_COLOR_SCROLLBAR] = RGBA8(50, 58, 61, 255);
    style.colors[STYLE_COLOR_SCROLLBAR_CURSOR] = RGBA8(48, 83, 111, 255);
    style.colors[STYLE_COLOR_SCROLLBAR_CURSOR_HOVER] = RGBA8(53, 88, 116, 255);
    style.colors[STYLE_COLOR_SCROLLBAR_CURSOR_ACTIVE] = RGBA8(58, 93, 121, 255);
    style.colors[STYLE_COLOR_TAB_HEADER] = RGBA8(48, 83, 111, 255);
    style.colors[STYLE_COLOR_KNOB] = style.colors[STYLE_COLOR_SLIDER];
    style.colors[STYLE_COLOR_KNOB_CURSOR] = style.colors[STYLE_COLOR_SLIDER_CURSOR];
    style.colors[STYLE_COLOR_KNOB_CURSOR_HOVER] = style.colors[STYLE_COLOR_SLIDER_CURSOR_HOVER];
    style.colors[STYLE_COLOR_KNOB_CURSOR_ACTIVE] = style.colors[STYLE_COLOR_SLIDER_CURSOR_ACTIVE];

    return style;
}