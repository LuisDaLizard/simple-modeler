#pragma once

#include "style.h"

smStyle smStyleLight()
{
    smStyle style = {};

    style.colors[STYLE_COLOR_TEXT] = RGBA8(70, 70, 70, 255);
    style.colors[STYLE_COLOR_WINDOW] = RGBA8(210, 210, 210, 255);
    style.colors[STYLE_COLOR_HEADER] = RGBA8(200, 200, 200, 255);
    style.colors[STYLE_COLOR_BORDER] = RGBA8(0, 0, 0, 255);
    style.colors[STYLE_COLOR_BUTTON] = RGBA8(185, 185, 185, 255);
    style.colors[STYLE_COLOR_BUTTON_HOVER] = RGBA8(170, 170, 170, 255);
    style.colors[STYLE_COLOR_BUTTON_ACTIVE] = RGBA8(160, 160, 160, 255);
    style.colors[STYLE_COLOR_TOGGLE] = RGBA8(150, 150, 150, 255);
    style.colors[STYLE_COLOR_TOGGLE_HOVER] = RGBA8(120, 120, 120, 255);
    style.colors[STYLE_COLOR_TOGGLE_CURSOR] = RGBA8(175, 175, 175, 255);
    style.colors[STYLE_COLOR_SELECT] = RGBA8(190, 190, 190, 255);
    style.colors[STYLE_COLOR_SELECT_ACTIVE] = RGBA8(175, 175, 175, 255);
    style.colors[STYLE_COLOR_SLIDER] = RGBA8(190, 190, 190, 255);
    style.colors[STYLE_COLOR_SLIDER_CURSOR] = RGBA8(80, 80, 80, 255);
    style.colors[STYLE_COLOR_SLIDER_CURSOR_HOVER] = RGBA8(70, 70, 70, 255);
    style.colors[STYLE_COLOR_SLIDER_CURSOR_ACTIVE] = RGBA8(60, 60, 60, 255);
    style.colors[STYLE_COLOR_PROPERTY] = RGBA8(175, 175, 175, 255);
    style.colors[STYLE_COLOR_EDIT] = RGBA8(150, 150, 150, 255);
    style.colors[STYLE_COLOR_EDIT_CURSOR] = RGBA8(0, 0, 0, 255);
    style.colors[STYLE_COLOR_COMBO] = RGBA8(175, 175, 175, 255);
    style.colors[STYLE_COLOR_CHART] = RGBA8(160, 160, 160, 255);
    style.colors[STYLE_COLOR_CHART_COLOR] = RGBA8(45, 45, 45, 255);
    style.colors[STYLE_COLOR_CHART_COLOR_HIGHLIGHT] = RGBA8(255, 0, 0, 255);
    style.colors[STYLE_COLOR_SCROLLBAR] = RGBA8(180, 180, 180, 255);
    style.colors[STYLE_COLOR_SCROLLBAR_CURSOR] = RGBA8(140, 140, 140, 255);
    style.colors[STYLE_COLOR_SCROLLBAR_CURSOR_HOVER] = RGBA8(150, 150, 150, 255);
    style.colors[STYLE_COLOR_SCROLLBAR_CURSOR_ACTIVE] = RGBA8(160, 160, 160, 255);
    style.colors[STYLE_COLOR_TAB_HEADER] = RGBA8(180, 180, 180, 255);
    style.colors[STYLE_COLOR_KNOB] = style.colors[STYLE_COLOR_SLIDER];
    style.colors[STYLE_COLOR_KNOB_CURSOR] = style.colors[STYLE_COLOR_SLIDER_CURSOR];
    style.colors[STYLE_COLOR_KNOB_CURSOR_HOVER] = style.colors[STYLE_COLOR_SLIDER_CURSOR_HOVER];
    style.colors[STYLE_COLOR_KNOB_CURSOR_ACTIVE] = style.colors[STYLE_COLOR_SLIDER_CURSOR_ACTIVE];

    return style;
}