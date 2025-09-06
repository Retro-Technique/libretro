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

static inline const char* GLErrorToString(GLenum err)
{
    switch (err)
    {
        case GL_INVALID_ENUM: return "An unacceptable value is specified for an enumerated argument. The offending function is ignored, having no side effect other than to set the error flag.";
        case GL_INVALID_VALUE: return "A numeric argument is out of range. The offending function is ignored, having no side effect other than to set the error flag.";
        case GL_INVALID_OPERATION: return "The specified operation is not allowed in the current state. The offending function is ignored, having no side effect other than to set the error flag.";
        case GL_STACK_OVERFLOW: return "This function would cause a stack overflow. The offending function is ignored, having no side effect other than to set the error flag.";
        case GL_STACK_UNDERFLOW: return "This function would cause a stack underflow. The offending function is ignored, having no side effect other than to set the error flag.";
        case GL_OUT_OF_MEMORY: return "There is not enough memory left to execute the function. The state of OpenGL is undefined, except for the state of the error flags, after this error is recorded.";
        case GL_NO_ERROR: [[fallthrough]];
        default: return "UNKNOWN_ERROR";
    }
}



static std::string s_error;

static void glfwErrorCallback(int, const char* description)
{
    s_error = description;
}

static const char* glfwGetLastError()
{
    return s_error.c_str();
}

#define glCheckError(funcname) \
{ \
    const GLenum glret = glGetError(); \
    if (glret != GL_NO_ERROR) \
    { \
        throw std::runtime_error(std::format("[OpenGL] {} : {}", funcname, GLErrorToString(glret))); \
    } \
}

#ifdef _DEBUG
#define glCheck(glfunction) glfunction;glCheckError(#glfunction);
#else
#define glCheck(glfunction) glfunction;
#endif