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

	struct shader_program_t
	{
		std::uint32_t id;
	};

	template<>
	class resource<shader_program_t>
	{
		template<typename T>
		friend class resource_binder;

	public:

		resource() = delete;
		resource(const resource&) = delete;
		resource& operator=(const resource&) = delete;
		resource(resource&&) noexcept = default;
		resource& operator=(resource&&) noexcept = default;

		explicit resource(const fragment_shader_source& fs, const vertex_shader_source& vs) GL_NOEXCEPT
			: m_handler{ 0 }
		{
			m_handler.id = gl::create_program();
			gl::attach_shader(m_handler.id, fs());
			gl::attach_shader(m_handler.id, vs());
			gl::link_program(m_handler.id);
		}

		~resource()
		{
			gl::delete_program(m_handler.id);
		}

		void set(std::string_view name, std::int32_t value) const GL_NOEXCEPT
		{
			const std::int32_t location = gl::uniform_location(m_handler.id, name.data());
			gl::uniform_1i(location, value);
		}

		void set(std::string_view name, std::uint32_t value) const GL_NOEXCEPT
		{
			const std::int32_t location = gl::uniform_location(m_handler.id, name.data());
			gl::uniform_1u(location, value);
		}

		void set(std::string_view name, std::float_t value) const GL_NOEXCEPT
		{
			const std::int32_t location = gl::uniform_location(m_handler.id, name.data());
			gl::uniform_1f(location, value);
		}

		void set(std::string_view name, std::double_t value) const GL_NOEXCEPT
		{
			const std::int32_t location = gl::uniform_location(m_handler.id, name.data());
			gl::uniform_1d(location, value);
		}

		void set(std::string_view name, const math::vector2i& value) const GL_NOEXCEPT
		{
			const std::int32_t location = gl::uniform_location(m_handler.id, name.data());
			gl::uniform_2i(location, value);
		}

		void set(std::string_view name, const math::vector2u& value) const GL_NOEXCEPT
		{
			const std::int32_t location = gl::uniform_location(m_handler.id, name.data());
			gl::uniform_2u(location, value);
		}

		void set(std::string_view name, const math::vector2f& value) const GL_NOEXCEPT
		{
			const std::int32_t location = gl::uniform_location(m_handler.id, name.data());
			gl::uniform_2f(location, value);
		}

		void set(std::string_view name, const math::vector2d& value) const GL_NOEXCEPT
		{
			const std::int32_t location = gl::uniform_location(m_handler.id, name.data());
			gl::uniform_2d(location, value);
		}

		void set(std::string_view name, const matrix4x4& value) const GL_NOEXCEPT
		{
			const std::int32_t location = gl::uniform_location(m_handler.id, name.data());
			gl::uniform_matrix(location, value);
		}

		[[nodiscard]] std::int32_t attribute_location(std::string_view name) const noexcept
		{
			return gl::attribute_location(m_handler.id, name);
		}

	private:

		void bind() const GL_NOEXCEPT
		{
			gl::use_program(m_handler.id);
		}

		void unbind() const GL_NOEXCEPT
		{
			gl::use_program(gl::INVALID_ID);
		}

		shader_program_t m_handler;

	};

	using shader_program = resource<shader_program_t>;

}