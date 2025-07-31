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

	inline constexpr color AliceBlue{ 0xFFF8F0FF };
	inline constexpr color AntiqueWhite{ 0xD7EBFAFF };
	inline constexpr color Aqua{ 0xFFFF00FF };
	inline constexpr color AquaMarine{ 0xD4FF7FFF };
	inline constexpr color Azure{ 0xFFFFF0FF };
	inline constexpr color Beige{ 0xDCF5F5FF };
	inline constexpr color Bisque{ 0xC4E4FFFF };
	inline constexpr color Black{ 0x000000FF };
	inline constexpr color BlancheDalmond{ 0xCDEBFFFF };
	inline constexpr color Blue{ 0xFF0000FF };
	inline constexpr color BlueViolet{ 0xE22B8AFF };
	inline constexpr color Brown{ 0x2A2AA5FF };
	inline constexpr color BurlyWood{ 0x87B8DEFF };
	inline constexpr color CadetBlue{ 0xA09E5FFF };
	inline constexpr color Chartreuse{ 0x00FF7FFF };
	inline constexpr color Chocolate{ 0x1E69D2FF };
	inline constexpr color Coral{ 0x507FFFFF };
	inline constexpr color CornFlowerBlue{ 0xED9564FF };
	inline constexpr color CornSilk{ 0xDCF8FFFF };
	inline constexpr color Crimson{ 0x3C14DCFF };
	inline constexpr color Cyan{ 0xFFFF00FF };
	inline constexpr color DarkBlue{ 0x8B0000FF };
	inline constexpr color DarkCyan{ 0x8B8B00FF };
	inline constexpr color DarkGoldenRod{ 0x0B86B8FF };
	inline constexpr color DarkGray{ 0xA9A9A9FF };
	inline constexpr color DarkGreen{ 0x006400FF };
	inline constexpr color DarkKhaki{ 0x6BB7BDFF };
	inline constexpr color DarkMagenta{ 0x8B008BFF };
	inline constexpr color DarkOliveGreen{ 0x2F6B55FF };
	inline constexpr color DarkOrange{ 0x008CFFFF };
	inline constexpr color DarkOrchid{ 0xCC3299FF };
	inline constexpr color DarkRed{ 0x00008BFF };
	inline constexpr color DarkSalmon{ 0x7A96E9FF };
	inline constexpr color DarkSeaGreen{ 0x8FBC8FFF };
	inline constexpr color DarkSlateBlue{ 0x8B3D48FF };
	inline constexpr color DarkSlateGray{ 0x4F4F2FFF };
	inline constexpr color DarkTurquoise{ 0xD1CE00FF };
	inline constexpr color DarkViolet{ 0xD30094FF };
	inline constexpr color DeepPink{ 0x9314FFFF };
	inline constexpr color DeepSkyBlue{ 0xFFBF00FF };
	inline constexpr color DimGray{ 0x696969FF };
	inline constexpr color DodgerBlue{ 0xFF901EFF };
	inline constexpr color FireBrick{ 0x2222B2FF };
	inline constexpr color FloralWhite{ 0xF0FAFFFF };
	inline constexpr color ForestGreen{ 0x228B22FF };
	inline constexpr color Fuchsia{ 0xFF00FFFF };
	inline constexpr color GainsBoro{ 0xDCDCDCFF };
	inline constexpr color GhostWhite{ 0xFFF8F8FF };
	inline constexpr color Gold{ 0x00D7FFFF };
	inline constexpr color GoldenRod{ 0x20A5DAFF };
	inline constexpr color Gray{ 0x808080FF };
	inline constexpr color Green{ 0x008000FF };
	inline constexpr color GreenYellow{ 0x2FFFADFF };
	inline constexpr color HoneyDew{ 0xF0FFF0FF };
	inline constexpr color HotPink{ 0xB469FFFF };
	inline constexpr color IndianRed{ 0x5C5CCDFF };
	inline constexpr color Indigo{ 0x82004BFF };
	inline constexpr color Ivory{ 0xF0FFFFFF };
	inline constexpr color Khaki{ 0x8CE6F0FF };
	inline constexpr color Lavender{ 0xFAE6E6FF };
	inline constexpr color LavenderBlush{ 0xF5F0FFFF };
	inline constexpr color LawnGreen{ 0x00FC7CFF };
	inline constexpr color LemonChiffon{ 0xCDFAFFFF };
	inline constexpr color LightBlue{ 0xE6D8ADFF };
	inline constexpr color LightCoral{ 0x8080F0FF };
	inline constexpr color LightCyan{ 0xFFFFE0FF };
	inline constexpr color LightGoldenRodYellow{ 0xD2FAFAFF };
	inline constexpr color LightGray{ 0xD3D3D3FF };
	inline constexpr color LightGreen{ 0x90EE90FF };
	inline constexpr color LightPink{ 0xC1B6FFFF };
	inline constexpr color LightSalmon{ 0x7AA0FFFF };
	inline constexpr color LightSeaGreen{ 0xAAB220FF };
	inline constexpr color LightSkyBlue{ 0xFACE87FF };
	inline constexpr color LightSlateGray{ 0x998877FF };
	inline constexpr color LightSteelBlue{ 0xDEC4B0FF };
	inline constexpr color LightYellow{ 0xE0FFFFFF };
	inline constexpr color Lime{ 0x00FF00FF };
	inline constexpr color LimeGreen{ 0x32CD32FF };
	inline constexpr color Linen{ 0xE6F0FAFF };
	inline constexpr color Magenta{ 0xFF00FFFF };
	inline constexpr color Maroon{ 0x000080FF };
	inline constexpr color MediumAquaMarine{ 0xAACD66FF };
	inline constexpr color MediumBlue{ 0xCD0000FF };
	inline constexpr color MediumOrchid{ 0xD355BAFF };
	inline constexpr color MediumPurple{ 0xDB7093FF };
	inline constexpr color MediumSeaGreen{ 0x71B33CFF };
	inline constexpr color MediumSlateBlue{ 0xEE687BFF };
	inline constexpr color MediumSpringGreen{ 0x9AFA00FF };
	inline constexpr color MediumTurquoise{ 0xCCD148FF };
	inline constexpr color MediumVioletRed{ 0x8515C7FF };
	inline constexpr color MidnightBlue{ 0x701919FF };
	inline constexpr color MintCream{ 0xFAFFF5FF };
	inline constexpr color MistyRose{ 0xE1E4FFFF };
	inline constexpr color Moccasin{ 0xB5E4FFFF };
	inline constexpr color NavajoWhite{ 0xADDEFFFF };
	inline constexpr color Navy{ 0x800000FF };
	inline constexpr color OldLace{ 0xE6F5FDFF };
	inline constexpr color Olive{ 0x008080FF };
	inline constexpr color OliveDrab{ 0x238E6BFF };
	inline constexpr color Orange{ 0x00A5FFFF };
	inline constexpr color OrangeRed{ 0x0045FFFF };
	inline constexpr color Orchid{ 0xD670DAFF };
	inline constexpr color PaleGoldenRod{ 0xAAE8EEFF };
	inline constexpr color PaleGreen{ 0x98FB98FF };
	inline constexpr color PaleTurquoise{ 0xEEEEAFFF };
	inline constexpr color PaleVioletRed{ 0x9370DBFF };
	inline constexpr color PapayaWhip{ 0xD5EFFFFF };
	inline constexpr color PeachPuff{ 0xB9DAFFFF };
	inline constexpr color Peru{ 0x3F85CDFF };
	inline constexpr color Pink{ 0xCBC0FFFF };
	inline constexpr color Plum{ 0xDDA0DDFF };
	inline constexpr color PowderBlue{ 0xE6E0B0FF };
	inline constexpr color Purple{ 0x800080FF };
	inline constexpr color RebeccaPurple{ 0x993366FF };
	inline constexpr color Red{ 0x0000FFFF };
	inline constexpr color RosyBrown{ 0x8F8FBCFF };
	inline constexpr color RoyalBlue{ 0xE16941FF };
	inline constexpr color SaddleBrown{ 0x13458BFF };
	inline constexpr color Salmon{ 0x7280FAFF };
	inline constexpr color SandyBrown{ 0x60A4F4FF };
	inline constexpr color SeaGreen{ 0x578B2EFF };
	inline constexpr color SeaShell{ 0xEEF5FFFF };
	inline constexpr color Sienna{ 0x2D52A0FF };
	inline constexpr color Silver{ 0xC0C0C0FF };
	inline constexpr color SkyBlue{ 0xEBCE87FF };
	inline constexpr color SlateBlue{ 0xCD5A6AFF };
	inline constexpr color SlateGray{ 0x908070FF };
	inline constexpr color Snow{ 0xFAFAFFFF };
	inline constexpr color SpringGreen{ 0x7FFF00FF };
	inline constexpr color SteelBlue{ 0xB48246FF };
	inline constexpr color Tan{ 0x8CB4D2FF };
	inline constexpr color Teal{ 0x808000FF };
	inline constexpr color Thistle{ 0xD8BFD8FF };
	inline constexpr color Tomato{ 0x4763FFFF };
	inline constexpr color Transparent{ 0x00000000 };
	inline constexpr color Turquoise{ 0xD0E040FF };
	inline constexpr color Violet{ 0xEE82EEFF };
	inline constexpr color Wheat{ 0xB3DEF5FF };
	inline constexpr color White{ 0xFFFFFFFF };
	inline constexpr color WhiteSmoke{ 0xF5F5F5FF };
	inline constexpr color Yellow{ 0x00FFFFFF };
	inline constexpr color YellowGreen{ 0x32CD9AFF };

}