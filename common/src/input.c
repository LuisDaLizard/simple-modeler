#include "input.h"

#include <string.h>

void
smInputNewFrame(smInput *input)
{
    assert(input);
    memcpy(&input->prevMouseState, &input->mouseState, sizeof(smMouse));
    input->mouseState = (smMouse){ 0 };
}

f32
smGetMouseX(smInput input)
{
    return input.mouseState.x;
}

f32
smGetMouseY(smInput input)
{
    return input.mouseState.y;
}

f32
smGetMouseDeltaX(smInput input)
{
    return input.mouseState.x - input.prevMouseState.x;
}

f32
smGetMouseDeltaY(smInput input)
{
    return input.mouseState.y - input.prevMouseState.y;
}

b32
smIsMouseButtonDown(smInput input, smMouseButton button)
{
    assert(button < MOUSE_BUTTON_MAX);
    return input.mouseState.buttons[button];
}

b32
smIsMouseButtonUp(smInput input, smMouseButton button)
{
    assert(button < MOUSE_BUTTON_MAX);
    return !input.mouseState.buttons[button];
}

b32
smIsMouseButtonPressed(smInput input, smMouseButton button)
{
    assert(button < MOUSE_BUTTON_MAX);
    return input.mouseState.buttons[button] && !input.prevMouseState.buttons[button];
}

b32
smIsMouseButtonReleased(smInput input, smMouseButton button)
{
    assert(button < MOUSE_BUTTON_MAX);
    return !input.mouseState.buttons[button] && input.prevMouseState.buttons[button];
}
