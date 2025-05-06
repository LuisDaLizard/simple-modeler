#pragma once

const char *DEFAULT_VERTEX_SHADER = "#version 410 core\n"
                                    "layout(location=0) in vec3 aPosition;\n"
                                    "void main()\n"
                                    "{\n"
                                    "    gl_Position = vec4(aPosition, 1);\n"
                                    "}\n\0";

const char *DEFAULT_FRAGMENT_SHADER = "#version 410 core\n"
                                      "out vec4 oColor;\n"
                                      "void main()\n"
                                      "{\n"
                                      "    oColor = vec4(1, 1, 1, 1);\n"
                                      "}\n\0";