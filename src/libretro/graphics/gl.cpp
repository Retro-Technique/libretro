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

	void gl::initialize()
	{
		glfwSetErrorCallback(gl::glfw_error_callback);

		if (!glfwInit())
		{
			throw std::runtime_error(std::format("[GLFW] {}", gl::last_glfw_error()));
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	void gl::load_GL()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			throw std::runtime_error("[GLAD] Unable to load OpenGL procedures");
		}

		glCheck(glDisable(GL_CULL_FACE));
		glCheck(glDisable(GL_DEPTH_TEST));
		glCheck(glEnable(GL_BLEND));
	}

	void gl::terminate() noexcept
	{
		glfwTerminate();
	}

	void gl::glfw_error_callback(int, const char* description)
	{
		ms_last_error = description;
	}

	std::string_view gl::last_glfw_error() noexcept
	{
		return ms_last_error;
	}

	std::uint32_t gl::gen_buffer() GL_NOEXCEPT
	{
		std::uint32_t id = 0;
		glCheck(glGenBuffers(1, &id));
		return id;
	}

	std::uint32_t gl::gen_vertex_array() GL_NOEXCEPT
	{
		std::uint32_t id = 0;
		glCheck(glGenVertexArrays(1, &id));
		return id;
	}

	std::uint32_t gl::gen_texture() GL_NOEXCEPT
	{
		std::uint32_t id = 0;
		glCheck(glGenTextures(1, &id));
		return id;
	}

	std::uint32_t gl::create_shader(shader type) GL_NOEXCEPT
	{
		return glCreateShader(native_from(type));
	}

	std::uint32_t gl::create_program() GL_NOEXCEPT
	{
		return glCreateProgram();
	}

	std::uint32_t gl::gen_framebuffer() GL_NOEXCEPT
	{
		std::uint32_t id = 0;
		glCheck(glGenFramebuffers(1, &id));
		return id;
	}

	void gl::viewport(const math::intrect& rc) GL_NOEXCEPT
	{
		glCheck(glViewport(rc.point.x, rc.point.y, rc.size.w, rc.size.h));
	}

	void gl::clear_color(const image::color& clear) GL_NOEXCEPT
	{
		static constexpr const auto NORMALIZE = [](std::uint8_t c) -> std::float_t
			{
				return static_cast<std::float_t>(c) / 255.f;
			};

		glCheck(glClearColor(
			NORMALIZE(clear.r),
			NORMALIZE(clear.g),
			NORMALIZE(clear.b),
			NORMALIZE(clear.a)
		));
	}

	void gl::clear() GL_NOEXCEPT
	{
		glCheck(glClear(GL_COLOR_BUFFER_BIT));
	}

	void gl::bind_buffer(std::uint32_t id) GL_NOEXCEPT
	{
		Expects(id >= 0);
		glCheck(glBindBuffer(GL_ARRAY_BUFFER, id));
	}

	void gl::bind_vertex_array(std::uint32_t id) GL_NOEXCEPT
	{
		Expects(id >= 0);
		glCheck(glBindVertexArray(id));
	}

	void gl::bind_texture(std::uint32_t id) GL_NOEXCEPT
	{
		Expects(id >= 0);
		glCheck(glBindTexture(GL_TEXTURE_2D, id));
	}

	void gl::blend_func(std::uint32_t srcfactor, std::uint32_t dstfactor) GL_NOEXCEPT
	{
		glCheck(glBlendFunc(srcfactor, dstfactor));
	}

	void gl::use_program(std::uint32_t id) GL_NOEXCEPT
	{
		Expects(id >= 0);
		glCheck(glUseProgram(id));
	}

	void gl::bind_framebuffer(std::uint32_t id) GL_NOEXCEPT
	{
		Expects(id >= 0);
		glCheck(glBindFramebuffer(GL_FRAMEBUFFER, id));
	}

	void gl::draw_arrays(std::uint32_t topology, std::int32_t vertex_count) GL_NOEXCEPT
	{
		glCheck(glDrawArrays(topology, 0, vertex_count));
	}

	void gl::buffer_data(std::span<const vertex> vertices) GL_NOEXCEPT
	{
		Expects(!vertices.empty());
		glCheck(glBufferData(GL_ARRAY_BUFFER, vertices.size_bytes(), vertices.data(), GL_STATIC_DRAW));
	}

	void gl::enable_vertex_attrib_array(std::uint32_t location) GL_NOEXCEPT
	{
		glCheck(glEnableVertexAttribArray(location));
	}

	void gl::vertex_attrib_pointer_position(std::uint32_t location) GL_NOEXCEPT
	{
		glCheck(glVertexAttribPointer(location, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, position)));
	}

	void gl::vertex_attrib_pointer_color(std::uint32_t location) GL_NOEXCEPT
	{
		glCheck(glVertexAttribPointer(location, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(vertex), (void*)offsetof(vertex, color)));
	}

	void gl::vertex_attrib_pointer_tex_coord(std::uint32_t location) GL_NOEXCEPT
	{
		glCheck(glVertexAttribPointer(location, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, tex_coords)));
	}

	void gl::tex_image_2D_from_memory(std::span<const std::byte> data, const math::size2i& size) GL_NOEXCEPT
	{
		Expects(!data.empty());
		Expects(size.w > 0 && size.h > 0);
		Expects(data.size() >= size.w * size.h * sizeof(vertex::color));

		glCheck(glTexImage2D(GL_TEXTURE_2D,
					 0,
					 GL_RGBA8,
					 size.w,
					 size.h,
					 0,
					 GL_RGBA,
					 GL_UNSIGNED_BYTE,
					 data.data()));
	}

	void gl::tex_parameter_min_filter(bool smoothed) GL_NOEXCEPT
	{
		glCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, smoothed ? GL_LINEAR : GL_NEAREST));
	}

	void gl::tex_parameter_mag_filter(bool smoothed) GL_NOEXCEPT
	{
		glCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, smoothed ? GL_LINEAR : GL_NEAREST));
	}

	void gl::tex_parameter_wrap_s(bool repeated) GL_NOEXCEPT
	{
		glCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, repeated ? GL_REPEAT : GL_CLAMP_TO_EDGE));
	}

	void gl::tex_parameter_wrap_t(bool repeated) GL_NOEXCEPT
	{
		glCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, repeated ? GL_REPEAT : GL_CLAMP_TO_EDGE));
	}

	void gl::shader_source(std::uint32_t id, std::string_view src) GL_NOEXCEPT
	{
		const char* data = src.data();
		glCheck(glShaderSource(id, 1, &data, nullptr));
	}

	void gl::compile_shader(std::uint32_t id) GL_NOEXCEPT
	{
		glCheck(glCompileShader(id));
	}

	void gl::attach_shader(std::uint32_t id, std::uint32_t shader_id) GL_NOEXCEPT
	{
		glCheck(glAttachShader(id, shader_id));
	}

	void gl::link_program(std::uint32_t id) GL_NOEXCEPT
	{
		glCheck(glLinkProgram(id));
	}

	void gl::uniform_1i(std::int32_t location, std::int32_t value) GL_NOEXCEPT
	{
		glCheck(glUniform1i(location, value));
	}

	void gl::uniform_1u(std::int32_t location, std::uint32_t value) GL_NOEXCEPT
	{
		glCheck(glUniform1ui(location, value));
	}

	void gl::uniform_1f(std::int32_t location, std::float_t value) GL_NOEXCEPT
	{
		glCheck(glUniform1f(location, value));
	}

	void gl::uniform_1d(std::int32_t location, std::double_t value) GL_NOEXCEPT
	{
		glCheck(glUniform1d(location, value));
	}

	void gl::uniform_2i(std::int32_t location, const math::vector2i& value) GL_NOEXCEPT
	{
		glCheck(glUniform2i(location, value.x, value.y));
	}

	void gl::uniform_2u(std::int32_t location, const math::vector2u& value) GL_NOEXCEPT
	{
		glCheck(glUniform2ui(location, value.x, value.y));
	}

	void gl::uniform_2f(std::int32_t location, const math::vector2f& value) GL_NOEXCEPT
	{
		glCheck(glUniform2f(location, value.x, value.y));
	}

	void gl::uniform_2d(std::int32_t location, const math::vector2d& value) GL_NOEXCEPT
	{
		glCheck(glUniform2d(location, value.x, value.y));
	}

	void gl::uniform_matrix(std::int32_t location, const matrix4x4& value) GL_NOEXCEPT
	{
		glCheck(glUniformMatrix4fv(location, 1, GL_FALSE, value.m.data()));
	}

	std::int32_t gl::uniform_location(std::uint32_t id, std::string_view name) GL_NOEXCEPT
	{
		Expects(!name.empty());

		return glGetUniformLocation(id, name.data());
	}

	std::int32_t gl::attribute_location(std::uint32_t id, std::string_view name) GL_NOEXCEPT
	{
		Expects(!name.empty());

		return glGetAttribLocation(id, name.data());
	}

	void gl::framebuffer_texture2D(std::uint32_t texture_id) GL_NOEXCEPT
	{
		glCheck(glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture_id, 0));
	}

	void gl::delete_buffer(std::uint32_t id) noexcept
	{
		Expects(id != 0);
		glDeleteBuffers(1, &id);
	}

	void gl::delete_vertex_array(std::uint32_t id) noexcept
	{
		Expects(id != 0);
		glDeleteVertexArrays(1, &id);
	}

	void gl::delete_texture(std::uint32_t id) noexcept
	{
		Expects(id != 0);
		glDeleteTextures(1, &id);
	}

	void gl::delete_shader(std::uint32_t id) noexcept
	{
		Expects(id != 0);
		glDeleteShader(id);
	}

	void gl::delete_program(std::uint32_t id) noexcept
	{
		Expects(id != 0);
		glDeleteProgram(id);
	}

	void gl::delete_framebuffer(std::uint32_t id) noexcept
	{
		Expects(id != 0);
		glDeleteFramebuffers(1, &id);
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
			GL_TRIANGLE_FAN
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

	gl::window_ptr gl::create_window(std::string_view title, math::size2s window_size, bool fullscreen, bool resizable, std::int32_t framerate)
	{
		glfwWindowHint(GLFW_RESIZABLE, resizable);
		glfwWindowHint(GLFW_REFRESH_RATE, framerate == 0 ? GLFW_DONT_CARE : framerate);

		GLFWwindow* ptr = glfwCreateWindow(static_cast<std::int32_t>(window_size.w),
										   static_cast<std::int32_t>(window_size.h),
										   title.data(),
										   fullscreen ? glfwGetPrimaryMonitor() : nullptr,
										   nullptr);
		if (!ptr)
		{
			throw std::runtime_error(std::format("[GLFW] {}", gl::last_glfw_error()));
		}

		return window_ptr(ptr, glfwDestroyWindow);
	}

	void gl::make_context_current(const window_ptr& window) GL_NOEXCEPT
	{
		glfwMakeContextCurrent(window.get());
	}

	void gl::poll_events() GL_NOEXCEPT
	{
		glfwPollEvents();
	}

	bool gl::should_close(const window_ptr& window) GL_NOEXCEPT
	{
		return glfwWindowShouldClose(window.get()) == GLFW_TRUE;
	}

	void gl::swap_buffers(const window_ptr& window) GL_NOEXCEPT
	{
		glfwSwapBuffers(window.get());
	}

}