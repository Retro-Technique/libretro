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

struct GLFWwindow;

namespace retro::graphics
{

	class LIBRETRO_GRAPHICS_API gl
	{
		template<typename T>
		friend class resource;

	private:

		static constexpr const std::uint32_t INVALID_ID = 0u;
				
		using window_ptr = std::unique_ptr<GLFWwindow, void(*)(GLFWwindow*)>;
		using factors = std::pair<std::uint32_t, std::uint32_t>;

		gl() = delete;
		~gl() = delete;

		static std::uint32_t gen_buffer() noexcept;
		static std::uint32_t gen_vertex_array() noexcept;
		static std::uint32_t gen_texture() noexcept;
		static std::uint32_t create_shader(shader type) noexcept;
		static std::uint32_t create_program() noexcept;

		static void bind_buffer(std::uint32_t id) noexcept;
		static void bind_vertex_array(std::uint32_t id) noexcept;
		static void bind_texture(std::uint32_t id) noexcept;
		static void blend_func(std::uint32_t srcfactor, std::uint32_t dstfactor) noexcept;
		static void use_program(std::uint32_t id) noexcept;

		static void buffer_data(std::span<const vertex> vertices) noexcept;
		static void enable_vertex_attrib_array(std::uint32_t location) noexcept;
		static void vertex_attrib_pointer_position(std::uint32_t location) noexcept;
		static void vertex_attrib_pointer_color(std::uint32_t location) noexcept;
		static void vertex_attrib_pointer_tex_coord(std::uint32_t location) noexcept;
		static void tex_image_2D_from_memory(std::span<const std::byte> data, const math::size2i& size) noexcept;
		static void tex_parameter_min_filter(bool smoothed) noexcept;
		static void tex_parameter_mag_filter(bool smoothed) noexcept;
		static void tex_parameter_wrap_s(bool repeated) noexcept;
		static void tex_parameter_wrap_t(bool repeated) noexcept;
		static void shader_source(std::uint32_t id, std::string_view src) noexcept;
		static void compile_shader(std::uint32_t id) noexcept;
		static void attach_shader(std::uint32_t id, std::uint32_t shader_id) noexcept;
		static void link_program(std::uint32_t id) noexcept;
	
		static void delete_buffer(std::uint32_t id) noexcept;
		static void delete_vertex_array(std::uint32_t id) noexcept;
		static void delete_texture(std::uint32_t id) noexcept;
		static void delete_shader(std::uint32_t id) noexcept;
		static void delete_program(std::uint32_t id) noexcept;

		static std::uint32_t native_from(topology topology) noexcept;
		static factors native_from(blend blend) noexcept;
		static std::uint32_t native_from(shader type) noexcept;

		static window_ptr create_window(std::string_view title, math::size2s window_size, bool fullscreen) noexcept;

	};

}