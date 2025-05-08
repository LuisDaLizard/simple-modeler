#pragma once

#include "defines.h"

typedef enum
{
    MOUSE_BUTTON_LEFT,
    MOUSE_BUTTON_RIGHT,
    MOUSE_BUTTON_MIDDLE,
    MOUSE_BUTTON_MAX,
} smMouseButton;

typedef struct
{

} smKeyboard;

typedef struct
{
    f32 x, y;
    b8 buttons[MOUSE_BUTTON_MAX];
} smMouse;

typedef struct
{
    smMouse mouseState, prevMouseState;
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