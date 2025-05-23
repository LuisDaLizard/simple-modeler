#include "input.h"

#include <string.h>

void
smInputNewFrame(smInput *input)
{
    assert(input);
    memcpy(&input->prevMouse, &input->mouse, sizeof(smMouse));
    memcpy(&input->prevKeyboard, &input->keyboard, sizeof(smKeyboard));
    input->mouse.scrollX = 0;
    input->mouse.scrollY = 0;
    input->textLength = 0;
    input->keyboard = (smKeyboard){ 0 };
}

f32
smGetMouseX(smInput input)
{
    return input.mouse.x;
}

f32
smGetMouseY(smInput input)
{
    return input.mouse.y;
}

f32
smGetMouseDeltaX(smInput input)
{
    return input.mouse.x - input.prevMouse.x;
}

f32
smGetMouseDeltaY(smInput input)
{
    return input.mouse.y - input.prevMouse.y;
}

b32
smIsMouseButtonDown(smInput input, smMouseButton button)
{
    assert(button < MOUSE_BUTTON_MAX);
    return input.mouse.buttons[button];
}

b32
smIsMouseButtonUp(smInput input, smMouseButton button)
{
    assert(button < MOUSE_BUTTON_MAX);
    return !input.mouse.buttons[button];
}

b32
smIsMouseButtonPressed(smInput input, smMouseButton button)
{
    assert(button < MOUSE_BUTTON_MAX);
    return input.mouse.buttons[button] && !input.prevMouse.buttons[button];
}

b32
smIsMouseButtonReleased(smInput input, smMouseButton button)
{
    assert(button < MOUSE_BUTTON_MAX);
    return !input.mouse.buttons[button] && input.prevMouse.buttons[button];
}

b32
smIsKeyDown(smInput input, smKey key)
{
    assert(key < KEY_MAX);
    return input.keyboard.keys[key];
}

b32
smIsKeyUp(smInput input, smKey key)
{
    assert(key < KEY_MAX);
    return !input.keyboard.keys[key];
}