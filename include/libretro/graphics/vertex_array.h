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

namespace retro::graphics
{

	struct vertex_array_t
	{
		std::uint32_t id;
		std::uint32_t topology;
	};
	static_assert(std::is_trivial_v<vertex_array_t>, "vertex_array_t is not trivial");
	static_assert(std::is_standard_layout_v<vertex_array_t>, "vertex_array_t is not standard layout");

	template<>
	class resource<vertex_array_t>
	{
		template<typename T>
		friend class resource_binder;

	public:

		resource() = delete;
		resource(const resource&) = delete;
		resource& operator=(const resource&) = delete;
		resource(resource&&) noexcept = default;
		resource& operator=(resource&&) noexcept = default;

		explicit resource(topology topology) GL_NOEXCEPT
			: m_handler{ 0 }
		{
			m_handler.id = gl::gen_vertex_array();
			m_handler.topology = gl::native_from(topology);
		}

		explicit resource(topology topology, const vertex_buffer& vbo, const shader_program& sp, std::string_view position, std::string_view color) GL_NOEXCEPT
			: resource(topology)
		{
			resource_binder bind_vao(*this);
			resource_binder bind_vbo(vbo);

			const std::int32_t pos_location = sp.attribute_location(position);
			const std::int32_t color_location = sp.attribute_location(color);

			gl::enable_vertex_attrib_array(pos_location);
			gl::vertex_attrib_pointer_position(pos_location);
			gl::enable_vertex_attrib_array(color_location);
			gl::vertex_attrib_pointer_color(color_location);
		}

		explicit resource(topology topology, const vertex_buffer& vbo, const shader_program& sp, std::string_view position, std::string_view color, const texture& tex, std::string_view texture) GL_NOEXCEPT
			: resource(topology, vbo, sp, position, color)
		{
			resource_binder bind_vao(*this);
			resource_binder bind_vbo(vbo);
			resource_binder bind_tex(tex);

			const std::int32_t tex_location = sp.attribute_location(texture);

			gl::enable_vertex_attrib_array(tex_location);
			gl::vertex_attrib_pointer_tex_coord(tex_location);
		}

		~resource()
		{
			gl::delete_vertex_array(m_handler.id);
		}

		[[no_discard]] std::uint32_t topology() const noexcept
		{
			return m_handler.topology;
		}

	private:

		void bind() const GL_NOEXCEPT
		{
			gl::bind_vertex_array(m_handler.id);
		}

		void unbind() const GL_NOEXCEPT
		{
			gl::bind_vertex_array(gl::INVALID_ID);
		}

		vertex_array_t m_handler;

	};

	using vertex_array = resource<vertex_array_t>;

}