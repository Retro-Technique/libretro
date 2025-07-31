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

#ifndef __LIBRETRO_IMAGE_H_INCLUDED__
#error "Do not include this file directly, include <libretro/image.h> instead."
#endif

namespace retro::image
{
	
	class LIBRETRO_IMAGE_API bitmap
	{
#pragma region Constructors

	public:

		bitmap() noexcept;		
		~bitmap() = default;
		bitmap(const bitmap&) = delete;
		bitmap& operator=(const bitmap&) = delete;

#pragma endregion
#pragma region Attributes

	private:

		std::vector<std::uint8_t> m_pixels;
		std::size_t m_width;
		std::size_t m_height;

	public:

		[[nodiscard]] constexpr std::size_t width() const noexcept { return m_width; }
		[[nodiscard]] constexpr std::size_t height() const noexcept { return m_height; }
		[[nodiscard]] constexpr std::size_t size() const noexcept { return m_width * m_height; }
		[[nodiscard]] constexpr std::size_t size_bytes() const noexcept { return m_pixels.size(); }
		[[nodiscard]] constexpr bool empty() const noexcept { return m_pixels.empty(); }
		[[nodiscard]] constexpr std::span<const std::uint8_t> data() const noexcept { return std::span<const std::uint8_t>(m_pixels.data(), size()); }
		
#pragma endregion
#pragma region Operations

	public:

		void create(std::size_t width, std::size_t height);
		void load_from_file(const std::filesystem::path& path);
		void load_from_memory(const std::uint8_t* buffer, std::size_t size_bytes);
		void save_to_file(const std::filesystem::path& path) const;
		void clear() noexcept;
		void mask_from_color(const retro::image::color& color, std::uint8_t alpha = retro::image::color::ALPHA_TRANSPARENT) noexcept;
		void flip_vertical() noexcept;
		void flip_horizontal() noexcept;

#pragma endregion
	};

}