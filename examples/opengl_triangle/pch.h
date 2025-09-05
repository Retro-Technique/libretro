#pragma once

#include <libretro/graphics.h>
#include <boost/log/trivial.hpp>

static constexpr const auto VERTEX_SHADER =
"#version 330 core\n"

"layout(location = 0) in vec2 vPos;\n"
"layout(location = 1) in vec4 vCol;\n"

"uniform mat4 MVP;\n"
"out vec4 color;\n"

"void main()\n"
"{\n"
"    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
"    color = vCol;\n"
"}\n";

static constexpr const auto FRAGMENT_SHADER =
"#version 330 core\n"

"in vec4 color;\n"
"out vec4 fragColor;\n"

"void main()\n"
"{\n"
"    fragColor = color;\n"
"}\n";