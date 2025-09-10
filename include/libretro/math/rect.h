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

#ifndef __LIBRETRO_MATH_H_INCLUDED__
#error "Do not include this file directly, include <libretro/math.h> instead."
#endif

namespace retro::math
{

	template<typename T>
	struct rect
	{
		static_assert(std::is_arithmetic_v<T>, "T must be an arithmetic type");

		constexpr rect() noexcept : point{ 0, 0 }
			, size{ 0, 0 }
		{
		}

		constexpr rect(T x, T y, T width, T height) noexcept
			: point{ x, y }
			, size{ width, height }
		{
		}

		constexpr rect(const vector2<T>& point, const vector2<T>& size) noexcept
			: point(point)
			, size(size)
		{
		}

		template<typename U>
		constexpr explicit rect(const rect<U>& rect) noexcept
			: point{ static_cast<T>(rect.point.x), static_cast<T>(rect.point.y) }
			, size{ static_cast<T>(rect.size.x), static_cast<T>(rect.size.y) }
		{
		}

		~rect() = default;

		[[nodiscard]] constexpr bool empty() const noexcept
		{
			return size.x <= T(0) || size.y <= T(0);
		}

		[[nodiscard]] constexpr bool null() const noexcept
		{
			return point.x == T(0) && point.y == T(0) && size.x == T(0) && size.y == T(0);
		}

		[[nodiscard]] constexpr vector2<T> center() const noexcept
		{
			return { point.x + size.x / T(2), point.y + size.y / T(2) };
		}

		[[nodiscard]] constexpr T area() const noexcept
		{
			return size.x * size.y;
		}

		[[nodiscard]] constexpr const T& left() const noexcept
		{
			return point.x;
		}

		[[nodiscard]] constexpr const T& top() const noexcept
		{
			return point.y;
		}

		[[nodiscard]] constexpr T right() const noexcept
		{
			return point.x + size.x;
		}

		[[nodiscard]] constexpr T bottom() const noexcept
		{
			return point.y + size.y;
		}

		vector2<T> point;
		vector2<T> size;
	};

	using intrect = rect<std::int32_t>;
	using floatrect = rect<std::float_t>;

	template<typename T>
	std::ostream& operator<<(std::ostream& stream, const rect<T>& rect) noexcept
	{
		return stream << "rect(" << rect.point.x << ", " << rect.point.y << ", " << rect.size.x << ", " << rect.size.y << ")";
	}

	template<typename T>
	[[nodiscard]] constexpr bool operator==(const rect<T>& lhs, const rect<T>& rhs) noexcept
	{
		return (lhs.point.x == rhs.point.x) && (lhs.point.y == rhs.point.y) && (lhs.size.x == rhs.size.x) && (lhs.size.y == rhs.size.y);
	}

	template<typename T>
	[[nodiscard]] constexpr bool operator!=(const rect<T>& lhs, const rect<T>& rhs) noexcept
	{
		return !(lhs == rhs);
	}
	
}