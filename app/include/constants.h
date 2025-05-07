#pragma once

const char* WINDOW_TITLE = "Simple Modeler";
const i32 WINDOW_WIDTH = 800;
const i32 WINDOW_HEIGHT = 600;
const rgba8 BACKGROUND_COLOR = HEX_TO_RGBA8(0xFF8489db);

f32 VERTICES[] =
{
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
        0.5f,  0.5f, 0.0f, 1.0f, 1.0f,

        0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
        -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
};