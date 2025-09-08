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

inline constexpr std::size_t TILE_SIZE = 16;
inline constexpr std::size_t TILESET_WIDTH = 272;
inline constexpr std::size_t TILESET_HEIGHT = 128;
inline constexpr std::size_t TILESET_COLS = TILESET_WIDTH / TILE_SIZE;
inline constexpr std::size_t MAP_W = 20;
inline constexpr std::size_t MAP_H = 15;
inline constexpr std::int32_t MAP[MAP_W * MAP_H] =
{
	92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,
	92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,92,83,92,92,92,
	92,92,92,92,92,92,92,92,92,92,92,60,42,43,43,43,43,42,43,44,
	92,92,92,92,92,92,92,92,92,92,92,62,29,29,29,29,29,29,29,29,
	92,92,49,50,51,92,92,92,92,92,92,62,29,59,29,29,29,29,29,29,
	92,92,11,12,13,92,92,92,92,92,92,62,29,29,29,29,29,29,29,29,
	92,92,28,29,30,92,92,92,92,92,92,62,29,29,29,29,29,59,29,29,
	92,92,28,29,30,92,92,92,92,92,92,62,29,29,29,29,29,29,29,29,
	17,92,28,29,30,119,92,92,92,77,92,62,29,29,59,29,29,59,29,29,
	81,81,81,81,81,81,81,81,81,81,81,81,81,81,81,81,81,81,81,81,
	98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,
	98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,
	98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,
	98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,
	98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98
};

static void add_tile(std::vector<rg::vertex>& vertices, std::int32_t tile_id, std::int32_t cx, std::int32_t cy)
{
	const std::int32_t idx = tile_id - 1;
	const std::int32_t tx = idx % TILESET_COLS;
	const std::int32_t ty = idx / TILESET_COLS;

	const std::float_t u0 = (tx * TILE_SIZE) / std::float_t(TILESET_WIDTH);
	const std::float_t v0 = (ty * TILE_SIZE) / std::float_t(TILESET_HEIGHT);
	const std::float_t u1 = ((tx + 1) * TILE_SIZE) / std::float_t(TILESET_WIDTH);
	const std::float_t v1 = ((ty + 1) * TILE_SIZE) / std::float_t(TILESET_HEIGHT);

	const std::float_t x0 = cx * TILE_SIZE;
	const std::float_t y0 = cy * TILE_SIZE;
	const std::float_t x1 = x0 + TILE_SIZE;
	const std::float_t y1 = y0 + TILE_SIZE;

	vertices.push_back({ { x0, y0 }, ri::color::white(), { u0, v0 } });
	vertices.push_back({ { x1, y0 }, ri::color::white(), { u1, v0 } });
	vertices.push_back({ { x0, y1 }, ri::color::white(), { u0, v1 } });

	vertices.push_back({ { x1, y0 }, ri::color::white(), { u1, v0 } });
	vertices.push_back({ { x1, y1 }, ri::color::white(), { u1, v1 } });
	vertices.push_back({ { x0, y1 }, ri::color::white(), { u0, v1 } });
}

static std::vector<rg::vertex> build_vertices(const std::int32_t* map, std::size_t width, std::size_t height)
{
	std::vector<rg::vertex> vertices;
	vertices.reserve(width * height * 6);

	for (std::size_t y = 0; y < height; ++y)
	{
		for (std::size_t x = 0; x < width; ++x)
		{
			const std::int32_t tile_id = map[y * width + x];
			add_tile(vertices, tile_id, x, y);
		}
	}

	return vertices;
}