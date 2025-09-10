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
	struct angle
	{
		static_assert(std::is_arithmetic_v<T>, "T must be an arithmetic type");	

		constexpr angle() noexcept
			: radians(0)
		{
		}

		constexpr angle(T r) noexcept
			: radians(r)
		{
		}

		~angle() = default;

		static [[no_discard]] constexpr angle<T> from_degrees(T value)
		{
			return { value * static_cast<T>(std::numbers::pi / 180.0) };
		}

		static [[no_discard]] constexpr angle<T> from_radians(T value)
		{
			return { value };
		}

		[[no_discard]] constexpr T deg() const noexcept
		{
			return radians * static_cast<T>(180.0 / std::numbers::pi);
		}

		[[no_discard]] constexpr T rad() const noexcept
		{
			return radians;
		}

		[[nodiscard]] constexpr angle<T> normalize() const noexcept
		{
			const T two_pi = static_cast<T>(2 * std::numbers::pi);
			T r = std::fmod(radians, two_pi);
			if (r < 0)
			{
				r += two_pi;
			}

			return angle<T>::from_radians(r);
		}

		T radians;
	};

	using anglef = angle<std::float_t>;
	using angled = angle<std::double_t>;

	template<typename T>
	std::ostream& operator<<(std::ostream& stream, const angle<T>& angle) noexcept
	{
		return stream << "angle(" << angle.deg() << "�)";
	}

	template<typename T>
	[[nodiscard]] constexpr bool operator==(const angle<T>& lhs, const angle<T>& rhs) noexcept
	{
		return lhs.rad() == rhs.rad();
	}

	template<typename T>
	[[nodiscard]] constexpr bool operator!=(const angle<T>& lhs, const angle<T>& rhs) noexcept
	{
		return !(lhs == rhs);
	}

}