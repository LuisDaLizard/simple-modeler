#pragma once

const char* WINDOW_TITLE = "Simple Modeler";
const i32 WINDOW_WIDTH = 800;
const i32 WINDOW_HEIGHT = 600;
const rgba8 BACKGROUND_COLOR = HEX_TO_RGBA8(0xFF8489db);

f32 VERTICES[] = {
        // First Triangle:
        -0.5f,  0.5f, 0.0f,  0.0f, 1.0f, // Top-left     (X, Y, Z, S, T)
        -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, // Bottom-left  (X, Y, Z, S, T)
        0.5f, -0.5f, 0.0f,  1.0f, 0.0f, // Bottom-right (X, Y, Z, S, T)

        // Second Triangle:
        0.5f, -0.5f, 0.0f,  1.0f, 0.0f, // Bottom-right (X, Y, Z, S, T) - *Duplicate vertex to complete the triangle fan*
        0.5f,  0.5f, 0.0f,  1.0f, 1.0f, // Top-right    (X, Y, Z, S, T)
        -0.5f,  0.5f, 0.0f,  0.0f, 1.0f  // Top-left     (X, Y, Z, S, T) - *Closing the square*
};