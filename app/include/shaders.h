#pragma once

const char *DEFAULT_VERTEX_SHADER = "#version 410 core\nlayout(location=0) in vec3 aPosition;\nvoid main() { gl_Position = vec4(aPosition, 0); }";
const char *DEFAULT_FRAGMENT_SHADER = "#version 410 core\nout vec4 oColor;\nvoid main() { oColor = vec4(1, 0, 0, 1); }";