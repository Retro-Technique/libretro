/**
 *
 * libretro
 *
 * CEA CNRS INRIA LOGICIEL LIBRE
 *
 * Copyright(c) 2014-2025 Retro Technique
 *
 * This software is a computer program whose purpose is to provide
 * minimalist modern C++ functionalities for cross-platform development.
 *
 * This software is governed by the CeCILL license under French law and
 * abiding by the rules of distribution of free software.  You can  use,
 * modify and/ or redistribute the software under the terms of the CeCILL
 * license as circulated by CEA, CNRS and INRIA at the following URL
 * "http://www.cecill.info".
 *
 * As a counterpart to the access to the source code and  rights to copy,
 * modify and redistribute granted by the license, users are provided only
 * with a limited warranty  and the software's author,  the holder of the
 * economic rights,  and the successive licensors  have only  limited
 * liability.
 *
 * In this respect, the user's attention is drawn to the risks associated
 * with loading,  using,  modifying and/or developing or reproducing the
 * software by the user in light of its specific status of free software,
 * that may mean  that it is complicated to manipulate,  and  that  also
 * therefore means  that it is reserved for developers  and  experienced
 * professionals having in-depth computer knowledge. Users are therefore
 * encouraged to load and test the software's suitability as regards their
 * requirements in conditions enabling the security of their systems and/or
 * data to be ensured and,  more generally, to use and operate it in the
 * same conditions as regards security.
 *
 * The fact that you are presently reading this means that you have had
 * knowledge of the CeCILL license and that you accept its terms.
 *
 */

#include "pch.h"

namespace retro::graphics
{

	std::uint32_t gl::gen_buffer() noexcept
	{
		std::uint32_t id = 0;
		glGenBuffers(1, &id);
		return id;
	}

	std::uint32_t gl::gen_vertex_array() noexcept
	{
		std::uint32_t id = 0;
		glGenVertexArrays(1, &id);
		return id;
	}

	std::uint32_t gl::gen_texture() noexcept
	{
		std::uint32_t id = 0;
		glGenTextures(1, &id);
		return id;
	}

	std::uint32_t gl::create_shader(shader type) noexcept
	{
		return glCreateShader(native_from(type));
	}

	std::uint32_t gl::create_program() noexcept
	{
		return glCreateProgram();
	}

	void gl::bind_buffer(std::uint32_t id) noexcept
	{
		//Expects(id >= 0);
		glBindBuffer(GL_ARRAY_BUFFER, id);
	}

	void gl::bind_vertex_array(std::uint32_t id) noexcept
	{
		//Expects(id >= 0);
		glBindVertexArray(id);
	}

	void gl::bind_texture(std::uint32_t id) noexcept
	{
		//Expects(id >= 0);
		glBindTexture(GL_TEXTURE_2D, id);
	}

	void gl::blend_func(std::uint32_t srcfactor, std::uint32_t dstfactor) noexcept
	{
		glBlendFunc(srcfactor, dstfactor);
	}

	void gl::use_program(std::uint32_t id) noexcept
	{
		glUseProgram(id);
	}

	void gl::buffer_data(std::span<const vertex> vertices) noexcept
	{
		//Expects(!vertices.empty());
		glBufferData(GL_ARRAY_BUFFER, vertices.size_bytes(), vertices.data(), GL_STATIC_DRAW);
	}

	void gl::enable_vertex_attrib_array(std::uint32_t location) noexcept
	{
		glEnableVertexAttribArray(location);
	}

	void gl::vertex_attrib_pointer_position(std::uint32_t location) noexcept
	{
		glVertexAttribPointer(location, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, position));
	}

	void gl::vertex_attrib_pointer_color(std::uint32_t location) noexcept
	{
		glVertexAttribPointer(location, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(vertex), (void*)offsetof(vertex, color));
	}

	void gl::vertex_attrib_pointer_tex_coord(std::uint32_t location) noexcept
	{
		glVertexAttribPointer(location, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, tex_coords));
	}

	void gl::tex_image_2D_from_memory(std::span<const std::byte> data, const math::size2i& size) noexcept
	{
		glTexImage2D(GL_TEXTURE_2D,
					 0,
					 GL_RGBA8,
					 size.w,
					 size.h,
					 0,
					 GL_RGBA,
					 GL_UNSIGNED_BYTE,
					 data.data());
	}

	void gl::tex_parameter_min_filter(bool smoothed) noexcept
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, smoothed ? GL_LINEAR : GL_NEAREST);
	}

	void gl::tex_parameter_mag_filter(bool smoothed) noexcept
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, smoothed ? GL_LINEAR : GL_NEAREST);
	}

	void gl::tex_parameter_wrap_s(bool repeated) noexcept
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, repeated ? GL_REPEAT : GL_CLAMP);
	}

	void gl::tex_parameter_wrap_t(bool repeated) noexcept
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, repeated ? GL_REPEAT : GL_CLAMP);
	}

	void gl::shader_source(std::uint32_t id, std::string_view src) noexcept
	{
		const char* data = src.data();
		glShaderSource(id, 1, &data, nullptr);
	}

	void gl::compile_shader(std::uint32_t id) noexcept
	{
		glCompileShader(id);
	}

	void gl::attach_shader(std::uint32_t id, std::uint32_t shader_id) noexcept
	{
		glAttachShader(id, shader_id);
	}

	void gl::link_program(std::uint32_t id) noexcept
	{
		glLinkProgram(id);
	}

	void gl::delete_buffer(std::uint32_t id) noexcept
	{
		//Expects(id != 0);
		glDeleteBuffers(1, &id);
	}

	void gl::delete_vertex_array(std::uint32_t id) noexcept
	{
		//Expects(id != 0);
		glDeleteVertexArrays(1, &id);
	}

	void gl::delete_texture(std::uint32_t id) noexcept
	{
		//Expects(id != 0);
		glDeleteTextures(1, &id);
	}

	void gl::delete_shader(std::uint32_t id) noexcept
	{
		//Expects(id != 0);
		glDeleteShader(id);
	}

	void gl::delete_program(std::uint32_t id) noexcept
	{
		glDeleteProgram(id);
	}

	std::uint32_t gl::native_from(topology topology) noexcept
	{
		static constexpr std::array<std::uint32_t, static_cast<std::size_t>(topology::COUNT)> TOPOLOGIES =
		{
			GL_POINTS,
			GL_LINES,
			GL_LINE_STRIP,
			GL_LINE_LOOP,
			GL_TRIANGLES,
			GL_TRIANGLE_STRIP,
			GL_TRIANGLE_FAN,
			GL_QUADS,
			GL_QUAD_STRIP,
			GL_POLYGON
		};

		const auto index = std::to_underlying(topology);
		return TOPOLOGIES[index];
	}

	gl::factors gl::native_from(blend blend) noexcept
	{
		static constexpr std::array<factors, static_cast<std::size_t>(blend::COUNT)> BLEND_MODES =
		{ {
			{GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA},
			{GL_SRC_ALPHA, GL_ONE},
			{GL_DST_COLOR, GL_ZERO},
			{GL_ONE, GL_ZERO},
		} };

		const auto index = std::to_underlying(blend);
		return BLEND_MODES[index];
	}

	std::uint32_t gl::native_from(shader type) noexcept
	{
		static constexpr std::array<std::uint32_t, static_cast<std::size_t>(shader::COUNT)> SHADERS =
		{
			GL_FRAGMENT_SHADER,
			GL_VERTEX_SHADER
		};
		
		const auto index = std::to_underlying(type);
		return SHADERS[index];
	}

}