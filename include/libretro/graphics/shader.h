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

	class LIBRETRO_GRAPHICS_API shader : public resource
	{
#pragma region Constructors

	public:

		shader(std::string_view vertex_src, std::string_view fragment_src);
		~shader();
		shader(const shader&) = delete;
		shader& operator=(const shader&) = delete;

#pragma endregion
#pragma region Operations

	public:

		std::int32_t uniform_location(std::string_view name) const noexcept;

#pragma endregion
#pragma region Overridables

	public:

		void bind() const noexcept override;
		void unbind() const noexcept override;

#pragma endregion
#pragma region Implementations

	private:

		std::uint32_t create_shader(std::string_view src, std::uint32_t type, std::string_view label) const;
		void check_compile(std::uint32_t shader, std::string_view label) const;
		void create_program(std::uint32_t vertex_shader, std::uint32_t fragment_shader);
		void check_link() const;

#pragma endregion
	};

}