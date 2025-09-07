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

	class renderer
	{
	public:

		renderer() = delete;
		~renderer() = default;
		renderer(const renderer&) = delete;
		renderer& operator=(const renderer&) = delete;
		renderer(renderer&&) noexcept = default;
		renderer& operator=(renderer&&) noexcept = default;

		renderer(const window& window) GL_NOEXCEPT
			: m_window(window)
		{
			gl::load_GL();
		}

		void viewport(const math::intrect& rc) const GL_NOEXCEPT
		{
			gl::viewport(rc);
		}

		void clear(const image::color& clear = image::color::black()) const GL_NOEXCEPT
		{
			gl::clear_color(clear);
			gl::clear();
		}

		void draw(const vertex_buffer& vbo,
				  const vertex_array& vao,
				  const blend_mode& bm,
				  const shader_program& sp,
				  const matrix4x4& model,
				  const matrix4x4& view,
				  const matrix4x4& projection) const GL_NOEXCEPT
		{
			resource_binder bind_vbo(vbo);
			resource_binder bind_vao(vao);
			resource_binder bind_bm(bm);
			resource_binder bind_sp(sp);

			const matrix4x4 mvp = model * view * projection;
			sp.set("MVP", mvp);

			gl::draw_arrays(vao.topology(), vbo.vertex_count());
		}

		void draw(const vertex_buffer& vbo,
				  const vertex_array& vao,
				  const blend_mode& bm,
				  const shader_program& sp,
				  const texture& tex,
				  const matrix4x4& model,
				  const matrix4x4& view,
				  const matrix4x4& projection) const GL_NOEXCEPT
		{
			resource_binder bind_vbo(vbo);
			resource_binder bind_vao(vao);
			resource_binder bind_bm(bm);
			resource_binder bind_sp(sp);
			resource_binder bind_tex(tex);

			const matrix4x4 mvp = model * view * projection;
			sp.set("MVP", mvp);

			gl::draw_arrays(vao.topology(), vbo.vertex_count());
		}

	private:

		std::reference_wrapper<const window> m_window;

	};

}