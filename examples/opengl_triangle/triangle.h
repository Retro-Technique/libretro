#pragma once

class triangle : public retro::graphics::drawable, public retro::graphics::transformable
{
public:

	triangle(const retro::graphics::shader& shader) noexcept;
	~triangle() = default;

private:

	std::array<retro::graphics::vertex, 3> m_vertices;
	retro::graphics::vertex_array m_vao;
	retro::graphics::vertex_buffer m_vbo;
	const retro::graphics::shader& m_shader;

public:

	std::int32_t bind() const noexcept override;
	void unbind() const noexcept  override;
	retro::graphics::topology topology() const noexcept override;
	retro::graphics::blend_mode blend_mode() const noexcept override;
	std::size_t vertices_count() const noexcept override;

};