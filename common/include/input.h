#pragma once

#include "defines.h"

#ifndef TEXT_MAX_LENGTH
#define TEXT_MAX_LENGTH 256
#endif

typedef enum
{
    MOUSE_BUTTON_LEFT,
    MOUSE_BUTTON_RIGHT,
    MOUSE_BUTTON_MIDDLE,
    MOUSE_BUTTON_MAX,
} smMouseButton;

typedef enum
{
    KEY_SPACE = 32,
    KEY_APOSTROPHE = 39,
    KEY_COMMA = 44,
    KEY_MINUS,
    KEY_PERIOD,
    KEY_SLASH,
    KEY_0,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,
    KEY_SEMICOLON = 59,
    KEY_EQUAL = 61,
    KEY_A = 65,
    KEY_B,
    KEY_C,
    KEY_D,
    KEY_E,
    KEY_F,
    KEY_G,
    KEY_H,
    KEY_I,
    KEY_J,
    KEY_K,
    KEY_L,
    KEY_M,
    KEY_N,
    KEY_O,
    KEY_P,
    KEY_Q,
    KEY_R,
    KEY_S,
    KEY_T,
    KEY_U,
    KEY_V,
    KEY_W,
    KEY_X,
    KEY_Y,
    KEY_Z,
    KEY_LEFT_BRACKET,
    KEY_BACKSLASH,
    KEY_RIGHT_BRACKET,
    KEY_GRAVE_ACCENT = 96,
    KEY_WORLD_1 = 161,
    KEY_WORLD_2,
    KEY_ESCAPE = 256,
    KEY_ENTER,
    KEY_TAB,
    KEY_BACKSPACE,
    KEY_INSERT,
    KEY_DELETE,
    KEY_RIGHT,
    KEY_LEFT,
    KEY_DOWN,
    KEY_UP,
    KEY_PAGE_UP,
    KEY_PAGE_DOWN,
    KEY_HOME,
    KEY_END,
    KEY_MENU = 348,
    KEY_MAX,
} smKey;

typedef struct
{
    b8 keys[KEY_MAX];
} smKeyboard;

typedef struct
{
    f32 x, y;
    f32 scrollX, scrollY;
    b8 buttons[MOUSE_BUTTON_MAX];
} smMouse;

typedef struct
{
    smMouse mouse, prevMouse;
    smKeyboard keyboard, prevKeyboard;
    u32 width, height;
    u32 framebufferWidth, framebufferHeight;
    u32 text[TEXT_MAX_LENGTH];
    u32 textLength;
} smInput;

void
smInputNewFrame(smInput *input);

f32
smGetMouseX(smInput input);

f32
smGetMouseY(smInput input);

f32
smGetMouseDeltaX(smInput input);

f32
smGetMouseDeltaY(smInput input);

b32
smIsMouseButtonDown(smInput input, smMouseButton button);

b32
smIsMouseButtonUp(smInput input, smMouseButton button);

b32
smIsMouseButtonPressed(smInput input, smMouseButton button);

b32
smIsMouseButtonReleased(smInput input, smMouseButton button);

b32
smIsKeyDown(smInput input, smKey key);

b32
smIsKeyUp(smInput input, smKey key);