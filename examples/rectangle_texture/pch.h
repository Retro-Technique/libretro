#pragma once

#include <libretro/graphics.h>
#include <boost/log/trivial.hpp>

static constexpr auto VERTEX_SHADER =
"#version 330 core\n"

"layout(location = 0) in vec2 vPos;\n"
"layout(location = 1) in vec4 vCol;\n"
"layout(location = 2) in vec2 vTexCoord;\n"

"uniform mat4 MVP;\n"
"out vec4 color;\n"
"out vec2 texCoord;\n"

"void main()\n"
"{\n"
"    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
"    color = vCol;\n"
"    texCoord = vTexCoord;\n"
"}\n";

static constexpr auto FRAGMENT_SHADER =
"#version 330 core\n"

"in vec4 color;\n"
"in vec2 texCoord;\n"
"out vec4 fragColor;\n"
"uniform sampler2D tex;\n"

"void main()\n"
"{\n"
"    fragColor = texture(tex, texCoord) * color;\n"
"}\n";

namespace rg = retro::graphics;
namespace rm = retro::math;
namespace ri = retro::image;

static constexpr rg::vertex VERTICES[] =
{
    { { 0.f,   0.f   }, { 255, 255, 255, 255 }, { 0.f, 0.f } },
    { { 640.f, 0.f   }, { 255, 255, 255, 255 }, { 1.f, 0.f } },
    { { 0.f,   480.f }, { 255, 255, 255, 255 }, { 0.f, 1.f } },
    { { 640.f, 480.f }, { 255, 255, 255, 255 }, { 1.f, 1.f } }
};