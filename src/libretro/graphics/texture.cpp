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

namespace retro::graphics
{

#pragma region Constructors

	texture::texture(const image::bitmap& bitmap, bool smooth, bool repeated) noexcept
	{
		glGenTextures(1, &m_id);
		glBindTexture(GL_TEXTURE_2D, m_id);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, smooth ? GL_LINEAR : GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, smooth ? GL_LINEAR : GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, repeated ? GL_REPEAT : GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, repeated ? GL_REPEAT : GL_CLAMP);

		glTexImage2D(GL_TEXTURE_2D, 
					 0, 
					 GL_RGBA8, 
					 static_cast<GLsizei>(bitmap.width()), 
					 static_cast<GLsizei>(bitmap.height()),
					 0, 
					 GL_RGBA, 
					 GL_UNSIGNED_BYTE, 
					 bitmap.data().data());

		glBindTexture(GL_TEXTURE_2D, 0);
	}

	texture::~texture()
	{
		if (m_id)
		{
			glDeleteTextures(1, &m_id);
			m_id = 0;
		}
	}

#pragma endregion
#pragma region Operations

	void texture::active(std::uint32_t slot) const noexcept
	{
		glActiveTexture(GL_TEXTURE0 + slot);
	}

#pragma endregion
#pragma region Overridables

	void texture::bind() const noexcept
	{
		glBindTexture(GL_TEXTURE_2D, m_id);
	}

	void texture::unbind() const noexcept
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

#pragma endregion

}