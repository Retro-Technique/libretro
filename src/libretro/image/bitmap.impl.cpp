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

#include "pch.h"
#include "bitmap.impl.h"

namespace retro::image
{

	bitmap::impl::impl(const math::size2s& size)
		: m_image(size.w, size.h)
	{
	}

	bitmap::impl::impl(const std::filesystem::path& path)
	{
		if (".png" == path.extension())
		{
			boost::gil::read_and_convert_image(path.string(), m_image, boost::gil::png_tag{});
		}
		else if (".jpg" == path.extension() || ".jpeg" == path.extension())
		{
			boost::gil::read_and_convert_image(path.string(), m_image, boost::gil::jpeg_tag{});
		}
		else if (".bmp" == path.extension())
		{
			boost::gil::read_and_convert_image(path.string(), m_image, boost::gil::bmp_tag{});
		}
		else
		{
			throw std::runtime_error(std::format("\"{}\" extension not supported", path.extension().string()));
		}
	}

	math::size2s bitmap::impl::size() const noexcept
	{
		return math::size2s(m_image.width(), m_image.height());
	}

	std::size_t bitmap::impl::size_bytes() const noexcept
	{
		return size().w * size().h * sizeof(boost::gil::rgba8_pixel_t);
	}

	std::span<const std::byte> bitmap::impl::data() const
	{
		const auto* ptr = reinterpret_cast<const std::byte*>(
			boost::gil::interleaved_view_get_raw_data(boost::gil::const_view(m_image)));

		return { ptr, size_bytes() };
	}

	void bitmap::impl::flip_vertically()
	{
		const auto flipped = boost::gil::flipped_up_down_view(boost::gil::const_view(m_image));
		boost::gil::copy_pixels(flipped, boost::gil::view(m_image));
	}

	void bitmap::impl::flip_horizontally()
	{
		const auto flipped = boost::gil::flipped_left_right_view(boost::gil::const_view(m_image));
		boost::gil::copy_pixels(flipped, boost::gil::view(m_image));
	}

}