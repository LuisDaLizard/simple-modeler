#pragma once

const char *DEFAULT_UI_VERTEX_SHADER =
        "#version 410 core\n"

        "layout (location = 0) in vec2 aPos;\n"
        "layout (location = 1) in vec2 aTexCoords;\n"
        "layout (location = 2) in vec4 aColor;\n"

        "uniform mat4 uProjection;\n"

        "out vec2 fTexCoords;\n"
        "out vec4 fColor;\n"

        "void main()\n"
        "{\n"
        "    fTexCoords = aTexCoords;\n"
        "    fColor = aColor;\n"
        "    gl_Position = uProjection * vec4(aPos, 0, 1);\n"
        "}\n";

const char *DEFAULT_UI_FRAGMENT_SHADER =
        "#version 410 core\n"

        "in vec2 fTexCoords;\n"
        "in vec4 fColor;\n"

        "uniform sampler2D uTexture;\n"
        "uniform vec2 uScreenSize;\n"

        "out vec4 oColor;\n"

        "void main()\n"
        "{\n"
        "    float gradX = mix(1, 0.7, gl_FragCoord.x / uScreenSize.x);\n"
        "    float gradY = mix(1, 0.7, gl_FragCoord.y / uScreenSize.y);\n"
        "    vec4 gradient = vec4(vec3(gradX + gradY / 2), 1);\n"
        "    vec4 color = fColor * gradient;\n"
        "    oColor = color * vec4(texture(uTexture, fTexCoords).rgba);\n"
        "}\n";