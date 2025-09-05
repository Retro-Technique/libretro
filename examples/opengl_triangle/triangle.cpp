#include "pch.h"
#include "triangle.h"

triangle::triangle(const retro::graphics::shader& shader) noexcept
	: m_vertices{ {
		retro::graphics::vertex(retro::math::vector2f(320.f,  40.f), {255, 0, 0, 255}, retro::math::vector2f(0.f, 0.f)),
		retro::graphics::vertex(retro::math::vector2f(40.f, 440.f), {255, 0, 0, 255}, retro::math::vector2f(0.f, 0.f)),
		retro::graphics::vertex(retro::math::vector2f(600.f, 440.f), {255, 0, 0, 255}, retro::math::vector2f(0.f, 0.f))
	} },
	m_vbo(m_vertices),
	m_shader(shader)
{
	m_vao.bind();
	m_vbo.bind();
	m_shader.bind();

	const std::int32_t pos_location = m_shader.attrib_location("vPos");
	const std::int32_t color_location = m_shader.attrib_location("vCol");
	m_vao.set_position(pos_location);
	m_vao.set_color(color_location);

	m_vao.unbind();
	m_vbo.unbind();
	m_shader.unbind();
}

std::int32_t triangle::bind() const noexcept
{
	m_vao.bind();
	m_vbo.bind();
	m_shader.bind();

	//const retro::math::matrix3x3 modelview = matrix();
	//const retro::math::matrix3x3 mvp = projection * modelview;

	const std::int32_t mvp_location = m_shader.uniform_location("MVP");
	return mvp_location;
}

void triangle::unbind() const noexcept
{
	m_vao.unbind();
	m_vbo.unbind();
	m_shader.unbind();
}

retro::graphics::topology triangle::topology() const noexcept
{
	return retro::graphics::topology::triangles;
}

retro::graphics::blend_mode triangle::blend_mode() const noexcept
{
	return retro::graphics::blend_mode::alpha;
}

std::size_t triangle::vertices_count() const noexcept
{
	return m_vertices.size();
}
