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

	class matrix3x3
	{
	public:

#pragma region Constructors

		constexpr matrix3x3() noexcept;
		constexpr matrix3x3(std::float_t m00, std::float_t m01, std::float_t m02,
						   std::float_t m10, std::float_t m11, std::float_t m12,
							std::float_t m20, std::float_t m21, std::float_t m22) noexcept;
		~matrix3x3() = default;

#pragma endregion
#pragma region Attributes

	private:

		std::array<std::float_t, 16> m_matrix;

#pragma endregion
#pragma region Operations

	public:

		static constexpr matrix3x3 identity() noexcept { return {}; }

		[[nodiscard]] constexpr std::span<const std::float_t> data() const noexcept;
		[[nodiscard]] constexpr matrix3x3 inverse() const noexcept;
		[[nodiscard]] constexpr vector2f transform(std::float_t x, std::float_t y) const noexcept;
		[[nodiscard]] constexpr vector2f transform(const vector2f& v) const noexcept;
		[[nodiscard]] constexpr floatrect transform(const floatrect& rect) const noexcept;
		constexpr matrix3x3& combine(const matrix3x3& other) noexcept;
		constexpr matrix3x3& translate(std::float_t x, std::float_t y) noexcept;
		constexpr matrix3x3& translate(const vector2f& v) noexcept;
		matrix3x3& rotate(std::float_t angle) noexcept;
		matrix3x3& rotate(std::float_t angle, std::float_t x, std::float_t y) noexcept;
		matrix3x3& rotate(std::float_t angle, const vector2f& v) noexcept;
		constexpr matrix3x3& scale(std::float_t x, std::float_t y) noexcept;
		constexpr matrix3x3& scale(std::float_t factor) noexcept;
		constexpr matrix3x3& scale(std::float_t factor, const vector2f& center) noexcept;
		constexpr matrix3x3& scale(std::float_t x, std::float_t y, std::float_t center_x, std::float_t center_y) noexcept;
		constexpr matrix3x3& scale(std::float_t x, std::float_t y, const vector2f& center) noexcept;
		constexpr matrix3x3& scale(const vector2f& factors) noexcept;
		constexpr matrix3x3& scale(const vector2f& factors, const vector2f& center) noexcept;

#pragma endregion

	};

	std::ostream& operator<<(std::ostream& stream, const matrix3x3& matrix) noexcept;
	[[nodiscard]] constexpr matrix3x3 operator*(const matrix3x3& lhs, const matrix3x3& rhs) noexcept;
	[[nodiscard]] constexpr vector2f operator*(const matrix3x3& lhs, const vector2f& rhs) noexcept;
	constexpr matrix3x3& operator*=(matrix3x3& lhs, const matrix3x3& rhs) noexcept;
	[[nodiscard]] constexpr bool operator==(const matrix3x3& lhs, const matrix3x3& rhs) noexcept;
	[[nodiscard]] constexpr bool operator!=(const matrix3x3& lhs, const matrix3x3& rhs) noexcept;

}

#include "matrix3x3.inl"