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

	struct texture_t
	{
		std::uint32_t id;
	};

	template<>
	class resource<texture_t>
	{
		template<typename T>
		friend class resource_binder;

	public:

		resource() = delete;

		explicit resource(std::span<const std::byte> data, const math::size2s& size, bool repeated, bool smoothed) noexcept
			: m_handler{ 0 }
		{
			//Expects(!data.empty());
			//Expects(size.w > 0 && size.h > 0);
			//Expects(data.size() >= size.w * size.h * sizeof(vertex::color));

			m_handler.id = gl::gen_texture();

			resource_binder binder(*this);
			gl::tex_parameter_min_filter(smoothed);
			gl::tex_parameter_mag_filter(smoothed);
			gl::tex_parameter_wrap_s(repeated);
			gl::tex_parameter_wrap_t(repeated);
			gl::tex_image_2D_from_memory(data, math::size2i(size.w, size.h));
		}

		~resource()
		{
			gl::delete_texture(m_handler.id);
		}

		resource(const resource&) = delete;
		resource& operator=(const resource&) = delete;
		resource(resource&&) noexcept = default;
		resource& operator=(resource&&) noexcept = default;

	private:

		void bind() const noexcept
		{
			gl::bind_texture(m_handler.id);
		}

		void unbind() const noexcept
		{
			gl::bind_texture(0);
		}

		texture_t m_handler;
	};

	using texture = resource<texture_t>;

	inline texture make_vertex_buffer(std::span<const std::byte> data, const math::size2s& size, bool repeated = false, bool smoothed = false)
	{
		texture tex(data, size, repeated, smoothed);

		return tex;
	}

}