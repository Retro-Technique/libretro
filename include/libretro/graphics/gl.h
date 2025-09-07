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

#pragma once

#ifndef __LIBRETRO_GRAPHICS_H_INCLUDED__
#error "Do not include this file directly, include <libretro/graphics.h> instead."
#endif

#ifdef _DEBUG
#define GL_NOEXCEPT
#else
#define GL_NOEXCEPT noexcept
#endif

struct GLFWwindow;

namespace retro::graphics
{

	class LIBRETRO_GRAPHICS_API gl
	{
		template<typename T>
		friend class resource;
		template<shader T>
		friend class shader_source;
		friend class window;
		friend class renderer;

	private:

		static constexpr const std::uint32_t INVALID_ID = 0u;
				
		using window_ptr = std::unique_ptr<GLFWwindow, void(*)(GLFWwindow*)>;
		using factors = std::pair<std::uint32_t, std::uint32_t>;

		gl() = delete;
		~gl() = delete;

		static void initialize();
		static void load_GL();
		static void terminate() noexcept;
		static void glfw_error_callback(int code, const char* description);
		static std::string_view last_glfw_error() noexcept;

		static std::uint32_t gen_buffer() GL_NOEXCEPT;
		static std::uint32_t gen_vertex_array() GL_NOEXCEPT;
		static std::uint32_t gen_texture() GL_NOEXCEPT;
		static std::uint32_t create_shader(shader type) GL_NOEXCEPT;
		static std::uint32_t create_program() GL_NOEXCEPT;
		static std::uint32_t gen_framebuffer() GL_NOEXCEPT;
		
		static void viewport(const math::intrect& rc) GL_NOEXCEPT;
		static void clear_color(const image::color& clear) GL_NOEXCEPT;
		static void clear() GL_NOEXCEPT;

		static void bind_buffer(std::uint32_t id) GL_NOEXCEPT;
		static void bind_vertex_array(std::uint32_t id) GL_NOEXCEPT;
		static void bind_texture(std::uint32_t id) GL_NOEXCEPT;
		static void blend_func(std::uint32_t srcfactor, std::uint32_t dstfactor) GL_NOEXCEPT;
		static void use_program(std::uint32_t id) GL_NOEXCEPT;
		static void bind_framebuffer(std::uint32_t id) GL_NOEXCEPT;

		static void draw_arrays(std::uint32_t topology, std::int32_t vertex_count) GL_NOEXCEPT;

		static void buffer_data(std::span<const vertex> vertices) GL_NOEXCEPT;
		static void enable_vertex_attrib_array(std::uint32_t location) GL_NOEXCEPT;
		static void vertex_attrib_pointer_position(std::uint32_t location) GL_NOEXCEPT;
		static void vertex_attrib_pointer_color(std::uint32_t location) GL_NOEXCEPT;
		static void vertex_attrib_pointer_tex_coord(std::uint32_t location) GL_NOEXCEPT;
		static void tex_image_2D_from_memory(std::span<const std::byte> data, const math::size2i& size) GL_NOEXCEPT;
		static void tex_parameter_min_filter(bool smoothed) GL_NOEXCEPT;
		static void tex_parameter_mag_filter(bool smoothed) GL_NOEXCEPT;
		static void tex_parameter_wrap_s(bool repeated) GL_NOEXCEPT;
		static void tex_parameter_wrap_t(bool repeated) GL_NOEXCEPT;
		static void shader_source(std::uint32_t id, std::string_view src) GL_NOEXCEPT;
		static void compile_shader(std::uint32_t id) GL_NOEXCEPT;
		static void attach_shader(std::uint32_t id, std::uint32_t shader_id) GL_NOEXCEPT;
		static void link_program(std::uint32_t id) GL_NOEXCEPT;
		static void uniform_1i(std::int32_t location, std::int32_t value) GL_NOEXCEPT;
		static void uniform_1u(std::int32_t location, std::uint32_t value) GL_NOEXCEPT;
		static void uniform_1f(std::int32_t location, std::float_t value) GL_NOEXCEPT;
		static void uniform_1d(std::int32_t location, std::double_t value) GL_NOEXCEPT;
		static void uniform_2i(std::int32_t location, const math::vector2i& value) GL_NOEXCEPT;
		static void uniform_2u(std::int32_t location, const math::vector2u& value) GL_NOEXCEPT;
		static void uniform_2f(std::int32_t location, const math::vector2f& value) GL_NOEXCEPT;
		static void uniform_2d(std::int32_t location, const math::vector2d& value) GL_NOEXCEPT;
		static void uniform_matrix(std::int32_t location, const matrix4x4& value) GL_NOEXCEPT;
		static std::int32_t uniform_location(std::uint32_t id, std::string_view name) GL_NOEXCEPT;
		static std::int32_t attribute_location(std::uint32_t id, std::string_view name) GL_NOEXCEPT;
		static void framebuffer_texture2D(std::uint32_t texture_id) GL_NOEXCEPT;
	
		static void delete_buffer(std::uint32_t id) noexcept;
		static void delete_vertex_array(std::uint32_t id) noexcept;
		static void delete_texture(std::uint32_t id) noexcept;
		static void delete_shader(std::uint32_t id) noexcept;
		static void delete_program(std::uint32_t id) noexcept;
		static void delete_framebuffer(std::uint32_t id) noexcept;

		static std::uint32_t native_from(topology topology) noexcept;
		static factors native_from(blend blend) noexcept;
		static std::uint32_t native_from(shader type) noexcept;

		static window_ptr create_window(std::string_view title, math::size2s window_size, bool fullscreen, bool resizable, std::int32_t framerate);
		static void make_context_current(const window_ptr& window) GL_NOEXCEPT;
		static void poll_events() GL_NOEXCEPT;
		static bool should_close(const window_ptr& window) GL_NOEXCEPT;
		static void swap_buffers(const window_ptr& window) GL_NOEXCEPT;

		static inline std::string ms_last_error{};

	};

}