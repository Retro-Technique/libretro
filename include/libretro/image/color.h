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

	struct color
	{
		static constexpr std::uint8_t ALPHA_OPAQUE = 255u;
		static constexpr std::uint8_t ALPHA_TRANSPARENT = 0u;

		std::uint8_t r;
		std::uint8_t g;
		std::uint8_t b;
		std::uint8_t a;

		static [[no_discard]] constexpr std::uint32_t to_integer(const color& color) noexcept
		{
			return (color.r << 24) | (color.g << 16) | (color.b << 8) | color.a;
		}

		static [[no_discard]] constexpr color from_integer(std::uint32_t value) noexcept
		{
			return
			{
				static_cast<std::uint8_t>((value & 0xff000000) >> 24),
				static_cast<std::uint8_t>((value & 0x00ff0000) >> 16),
				static_cast<std::uint8_t>((value & 0x0000ff00) >> 8),
				static_cast<std::uint8_t>((value & 0x000000ff) >> 0)
			};
		}

		static [[no_discard]] consteval color make(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha = ALPHA_OPAQUE)
		{
			return color{ red, green, blue, alpha };
		}

		static consteval color black() { return make(0, 0, 0); }
		static consteval color white() { return make(255, 255, 255); }
		static consteval color red() { return make(255, 0, 0); }
		static consteval color green() { return make(0, 255, 0); }
		static consteval color blue() { return make(0, 0, 255); }
		static consteval color yellow() { return make(255, 255, 0); }
		static consteval color magenta() { return make(255, 0, 255); }
		static consteval color cyan() { return make(0, 255, 255); }
		static consteval color transparent() { return make(0, 0, 0, ALPHA_TRANSPARENT); }

	};

	static_assert(std::is_trivial_v<color>, "color is not trivial");
	static_assert(std::is_standard_layout_v<color>, "color is not standard layout");
		
	using pixel = color;

	[[nodiscard]] constexpr color operator+(const color& lhs, const color& rhs) noexcept
	{
		return color(
			static_cast<std::uint8_t>(std::min(lhs.r + rhs.r, 255)),
			static_cast<std::uint8_t>(std::min(lhs.g + rhs.g, 255)),
			static_cast<std::uint8_t>(std::min(lhs.b + rhs.b, 255)),
			static_cast<std::uint8_t>(std::min(lhs.a + rhs.a, 255))
		);
	}

	[[nodiscard]] constexpr color operator-(const color& lhs, const color& rhs) noexcept
	{
		return color(
			static_cast<std::uint8_t>(std::max(lhs.r - rhs.r, 0)),
			static_cast<std::uint8_t>(std::max(lhs.g - rhs.g, 0)),
			static_cast<std::uint8_t>(std::max(lhs.b - rhs.b, 0)),
			static_cast<std::uint8_t>(std::max(lhs.a - rhs.a, 0))
		);
	}

	[[nodiscard]] constexpr color operator*(const color& lhs, const color& rhs) noexcept
	{
		return color(
			static_cast<std::uint8_t>(lhs.r * rhs.r / 255),
			static_cast<std::uint8_t>(lhs.g * rhs.g / 255),
			static_cast<std::uint8_t>(lhs.b * rhs.b / 255),
			static_cast<std::uint8_t>(lhs.a * rhs.a / 255)
		);
	}

	[[nodiscard]] constexpr color& operator+=(color& lhs, const color& rhs) noexcept
	{
		lhs = lhs + rhs;
		return lhs;
	}

	[[nodiscard]] constexpr color& operator-=(color& lhs, const color& rhs) noexcept
	{
		lhs = lhs - rhs;
		return lhs;
	}

	[[nodiscard]] constexpr color& operator*=(color& lhs, const color& rhs) noexcept
	{
		lhs = lhs * rhs;
		return lhs;
	}
 
	[[nodiscard]] constexpr bool operator==(const color& lhs, const color& rhs) noexcept
	{
		return lhs.r == rhs.r &&
			lhs.g == rhs.g &&
			lhs.b == rhs.b &&
			lhs.a == rhs.a;
	}

	[[nodiscard]] constexpr bool operator!=(const color& lhs, const color& rhs) noexcept
	{
		return !(lhs == rhs);
	}

	inline std::ostream& operator<<(std::ostream& stream, const color& color) noexcept
	{
		return stream << "color("
			<< color.r << ", "
			<< color.g << ", "
			<< color.b << ", "
			<< color.a << ")";
	}

}