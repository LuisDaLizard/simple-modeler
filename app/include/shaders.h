#pragma once

const char *DEFAULT_VERTEX_SHADER = "#version 410 core\n"
                                    "layout(location=0) in vec3 aPosition;\n"
                                    "layout(location=1) in vec2 aTexCoord;\n"
                                    "out vec2 fTexCoord;\n"
                                    "void main()\n"
                                    "{\n"
                                    "    fTexCoord = aTexCoord;\n"
                                    "    gl_Position = vec4(aPosition, 1);\n"
                                    "}\n\0";

const char *DEFAULT_FRAGMENT_SHADER = "#version 410 core\n"
                                      "out vec4 oColor;\n"
                                      "uniform sampler2D uTexture;\n"
                                      "in vec2 fTexCoord;\n"
                                      "void main()\n"
                                      "{\n"
                                      "    oColor = texture(uTexture, fTexCoord);\n"
                                      "}\n\0";