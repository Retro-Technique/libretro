#pragma once

#include <libretro/graphics.h>
#include <boost/log/trivial.hpp>

static constexpr auto VERTEX_SHADER =
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

static constexpr auto FRAGMENT_SHADER =
"#version 330 core\n"

"in vec4 color;\n"
"out vec4 fragColor;\n"

"void main()\n"
"{\n"
"    fragColor = color;\n"
"}\n";

namespace rg = retro::graphics;
namespace rm = retro::math;

static constexpr rg::vertex VERTICES[] =
{
    { { 320.f,  40.f }, { 255, 0, 0, 255 }, { 0.f, 0.f } },
    { {  40.f, 440.f }, { 255, 0, 0, 255 }, { 0.f, 0.f } },
    { { 600.f, 440.f }, { 255, 0, 0, 255 }, { 0.f, 0.f } }
};