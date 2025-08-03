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

	shader::shader(std::string_view vertex_src, std::string_view fragment_src)
	{
		const std::uint32_t vertex_shader = create_shader(vertex_src, GL_VERTEX_SHADER, "VERTEX");
		const std::uint32_t fragment_shader = create_shader(fragment_src, GL_FRAGMENT_SHADER, "FRAGMENT");
		create_program(vertex_shader, fragment_shader);
	}

	shader::~shader()
	{
		glDeleteProgram(m_id);
	}

#pragma endregion
#pragma region Operations

	std::int32_t shader::uniform_location(std::string_view name) const noexcept
	{
		return glGetUniformLocation(m_id, name.data());
	}

#pragma endregion
#pragma region Overridables

	void shader::bind() const noexcept
	{
		glUseProgram(m_id);
	}

	void shader::unbind() const noexcept
	{
		glUseProgram(0);
	}

#pragma endregion
#pragma region Implementations

	std::uint32_t shader::create_shader(std::string_view src, std::uint32_t type, std::string_view label) const
	{
		GLuint shader = glCreateShader(type);
		const char* data = src.data();
		glShaderSource(shader, 1, &data, nullptr);
		glCompileShader(shader);

		check_compile(shader, label);

		return shader;
	}

	void shader::check_compile(std::uint32_t shader, std::string_view label) const
	{
		GLint succeeded = 0;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &succeeded);
		if (!succeeded)
		{
			char log[1024]{ 0 };
			glGetShaderInfoLog(shader, sizeof(log), nullptr, log);
			std::string error("[Shader Compile Error] (");
			error += label;
			error += "): ";
			error += log;
			throw std::runtime_error(error.c_str());
		}
	}

	void shader::create_program(std::uint32_t vertex_shader, std::uint32_t fragment_shader)
	{
		m_id = glCreateProgram();
		if (m_id)
		{
			glAttachShader(m_id, vertex_shader);
			glAttachShader(m_id, fragment_shader);
			glLinkProgram(m_id);

			check_link();

			glDeleteShader(vertex_shader);
			glDeleteShader(fragment_shader);
		}
	}

	void shader::check_link() const
	{
		GLint succeeded = 0;
		glGetProgramiv(m_id, GL_LINK_STATUS, &succeeded);
		if (!succeeded)
		{
			char log[1024]{ 0 };
			glGetProgramInfoLog(m_id, sizeof(log), nullptr, log);
			std::string error("[Shader Compile Error] :");
			error += log;
			throw std::runtime_error(error.c_str());
		}
	}

#pragma endregion

}