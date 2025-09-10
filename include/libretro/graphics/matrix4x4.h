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

	struct matrix4x4
	{
		constexpr matrix4x4() noexcept
			: m{ 1.f, 0.f, 0.f, 0.f,
				 0.f, 1.f, 0.f, 0.f,
				 0.f, 0.f, 1.f, 0.f,
				 0.f, 0.f, 0.f, 1.f }
		{
		}

		constexpr std::float_t& operator()(std::size_t col, std::size_t row) noexcept
		{
			return m[col * 4 + row];
		}

		constexpr std::float_t operator()(std::size_t col, std::size_t row) const noexcept
		{
			return m[col * 4 + row];
		}

		constexpr matrix4x4 operator*(const matrix4x4& rhs) const noexcept
		{
			matrix4x4 result{};

			for (std::int32_t c = 0; c < 4; ++c)
			{
				for (std::int32_t r = 0; r < 4; ++r)
				{
					result(c, r) = 0.f;
					for (std::int32_t k = 0; k < 4; ++k)
					{
						result(c, r) += (*this)(k, r) * rhs(c, k);
					}
				}
			}

			return result;
		}

		static constexpr matrix4x4 translation(const math::vector2f& offset) noexcept
		{
			matrix4x4 mat{};

			mat(3, 0) = offset.x;
			mat(3, 1) = offset.y;

			return mat;
		}

		static constexpr matrix4x4 scaling(const math::vector2f& offset) noexcept
		{
			matrix4x4 mat{};

			mat(0, 0) = offset.x;
			mat(1, 1) = offset.y;

			return mat;
		}

		static matrix4x4 rotation(const math::anglef& angle) noexcept
		{
			matrix4x4 mat{};

			const std::float_t c = std::cos(angle.rad());
			const std::float_t s = std::sin(angle.rad());

			mat(0, 0) = c;
			mat(1, 0) = -s;
			mat(0, 1) = s;
			mat(1, 1) = c;

			return mat;
		}

		static constexpr matrix4x4 ortho(std::float_t left, std::float_t right,
										 std::float_t bottom, std::float_t top,
										 std::float_t znear = -1.f, std::float_t zfar = 1.f) noexcept
		{
			matrix4x4 mat{};

			mat(0, 0) = 2.f / (right - left);
			mat(1, 1) = 2.f / (top - bottom);
			mat(2, 2) = -2.f / (zfar - znear);

			mat(3, 0) = -(right + left) / (right - left);
			mat(3, 1) = -(top + bottom) / (top - bottom);
			mat(3, 2) = -(zfar + znear) / (zfar - znear);
			mat(3, 3) = 1.f;

			return mat;
		}

		std::array<std::float_t, 16> m;
	};

}