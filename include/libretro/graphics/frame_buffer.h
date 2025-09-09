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

	struct frame_buffer_t
	{
		std::uint32_t	id;
	};
	static_assert(std::is_trivial_v<frame_buffer_t>, "frame_buffer_t is not trivial");
	static_assert(std::is_standard_layout_v<frame_buffer_t>, "frame_buffer_t is not standard layout");

	template<>
	class resource<frame_buffer_t>
	{
		template<typename T>
		friend class resource_binder;

	public:

		resource() = delete;
		resource(const resource&) = delete;
		resource& operator=(const resource&) = delete;
		resource(resource&&) noexcept = default;
		resource& operator=(resource&&) noexcept = default;

		explicit resource(const texture& texture) GL_NOEXCEPT
			: m_handler{ 0 }
		{
			m_handler.id = gl::gen_framebuffer();

			resource_binder bind_this(*this);
			resource_binder bind_tex(texture);
			gl::tex_parameter_min_filter(false);
			gl::tex_parameter_mag_filter(false);
			gl::framebuffer_texture2D(texture.m_handler.id);
		}

		~resource()
		{
			gl::delete_framebuffer(m_handler.id);
		}

	private:

		void bind() const GL_NOEXCEPT
		{
			gl::bind_framebuffer(m_handler.id);
		}

		void unbind() const GL_NOEXCEPT
		{
			gl::bind_framebuffer(gl::INVALID_ID);
		}

		frame_buffer_t m_handler;
	};

	using frame_buffer = resource<frame_buffer_t>;

}