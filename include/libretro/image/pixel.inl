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

namespace retro::image
{

#pragma region Constructors

	constexpr pixel::pixel() noexcept
		: red(0)
		, green(0)
		, blue(0)
		, alpha(ALPHA_OPAQUE)
	{
	}

	constexpr pixel::pixel(const pixel& other) noexcept
		: red(other.red)
		, green(other.green)
		, blue(other.blue)
		, alpha(other.alpha)
	{
	}

	constexpr pixel::pixel(std::uint32_t value) noexcept
	{
		from_integer(value);
	}

	constexpr pixel::pixel(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha) noexcept
		: red(red)
		, green(green)
		, blue(blue)
		, alpha(alpha)
	{
	}

#pragma endregion
#pragma region Operations

	[[nodiscard]] constexpr bool pixel::is_opaque() const noexcept
	{
		return alpha == ALPHA_OPAQUE;
	}

	[[nodiscard]] constexpr bool pixel::is_transparent() const noexcept
	{
		return alpha == ALPHA_TRANSPARENT;
	}

	[[nodiscard]] constexpr std::uint32_t pixel::to_integer() const noexcept
	{
		return (red << 24) | (green << 16) | (blue << 8) | alpha;
	}

	constexpr void pixel::from_integer(std::uint32_t value) noexcept
	{
		red = static_cast<std::uint8_t>((value & 0xff000000) >> 24);
		green = static_cast<std::uint8_t>((value & 0x00ff0000) >> 16);
		blue = static_cast<std::uint8_t>((value & 0x0000ff00) >> 8);
		alpha = static_cast<std::uint8_t>((value & 0x000000ff) >> 0);
	}

#pragma endregion
#pragma region Overridables

	[[nodiscard]] constexpr pixel pixel::operator+(const pixel& other) noexcept
	{
		return pixel(
			static_cast<std::uint8_t>(std::min(red + other.red, 255)),
			static_cast<std::uint8_t>(std::min(green + other.green, 255)),
			static_cast<std::uint8_t>(std::min(blue + other.blue, 255)),
			static_cast<std::uint8_t>(std::min(alpha + other.alpha, 255))
		);
	}

	[[nodiscard]] constexpr pixel pixel::operator-(const pixel& other) noexcept
	{
		return pixel(
			static_cast<std::uint8_t>(std::max(red - other.red, 0)),
			static_cast<std::uint8_t>(std::max(green - other.green, 0)),
			static_cast<std::uint8_t>(std::max(blue - other.blue, 0)),
			static_cast<std::uint8_t>(std::max(alpha - other.alpha, 0))
		);
	}

	[[nodiscard]] constexpr pixel pixel::operator*(const pixel& other) noexcept
	{
		return pixel(
			static_cast<std::uint8_t>(red * other.red / 255),
			static_cast<std::uint8_t>(green * other.green / 255),
			static_cast<std::uint8_t>(blue * other.blue / 255),
			static_cast<std::uint8_t>(alpha * other.alpha / 255)
		);
	}

	constexpr pixel& pixel::operator+=(const pixel& other) noexcept
	{
		return *this = *this + other;
	}

	constexpr pixel& pixel::operator-=(const pixel& other) noexcept
	{
		return *this = *this - other;
	}

	constexpr pixel& pixel::operator*=(const pixel& other) noexcept
	{
		return *this = *this * other;
	}

	[[nodiscard]] constexpr bool pixel::operator==(const pixel& other) const noexcept
	{
		return red == other.red &&
			green == other.green &&
			blue == other.blue &&
			alpha == other.alpha;
	}

	[[nodiscard]] constexpr bool pixel::operator!=(const pixel& other) const noexcept
	{
		return !(*this == other);
	}

#pragma endregion

	inline std::ostream& operator<<(std::ostream& stream, const pixel& pixel) noexcept
	{
		return stream << "pixel(" 
			<< pixel.red << ", "
			<< pixel.green << ", "
			<< pixel.blue << ", "
			<< pixel.alpha << ")";
	}

}