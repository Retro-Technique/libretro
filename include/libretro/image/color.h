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

	inline constexpr pixel AliceBlue{ 0xFFF8F0FF };
	inline constexpr pixel AntiqueWhite{ 0xD7EBFAFF };
	inline constexpr pixel Aqua{ 0xFFFF00FF };
	inline constexpr pixel AquaMarine{ 0xD4FF7FFF };
	inline constexpr pixel Azure{ 0xFFFFF0FF };
	inline constexpr pixel Beige{ 0xDCF5F5FF };
	inline constexpr pixel Bisque{ 0xC4E4FFFF };
	inline constexpr pixel Black{ 0x000000FF };
	inline constexpr pixel BlancheDalmond{ 0xCDEBFFFF };
	inline constexpr pixel Blue{ 0xFF0000FF };
	inline constexpr pixel BlueViolet{ 0xE22B8AFF };
	inline constexpr pixel Brown{ 0x2A2AA5FF };
	inline constexpr pixel BurlyWood{ 0x87B8DEFF };
	inline constexpr pixel CadetBlue{ 0xA09E5FFF };
	inline constexpr pixel Chartreuse{ 0x00FF7FFF };
	inline constexpr pixel Chocolate{ 0x1E69D2FF };
	inline constexpr pixel Coral{ 0x507FFFFF };
	inline constexpr pixel CornFlowerBlue{ 0xED9564FF };
	inline constexpr pixel CornSilk{ 0xDCF8FFFF };
	inline constexpr pixel Crimson{ 0x3C14DCFF };
	inline constexpr pixel Cyan{ 0xFFFF00FF };
	inline constexpr pixel DarkBlue{ 0x8B0000FF };
	inline constexpr pixel DarkCyan{ 0x8B8B00FF };
	inline constexpr pixel DarkGoldenRod{ 0x0B86B8FF };
	inline constexpr pixel DarkGray{ 0xA9A9A9FF };
	inline constexpr pixel DarkGreen{ 0x006400FF };
	inline constexpr pixel DarkKhaki{ 0x6BB7BDFF };
	inline constexpr pixel DarkMagenta{ 0x8B008BFF };
	inline constexpr pixel DarkOliveGreen{ 0x2F6B55FF };
	inline constexpr pixel DarkOrange{ 0x008CFFFF };
	inline constexpr pixel DarkOrchid{ 0xCC3299FF };
	inline constexpr pixel DarkRed{ 0x00008BFF };
	inline constexpr pixel DarkSalmon{ 0x7A96E9FF };
	inline constexpr pixel DarkSeaGreen{ 0x8FBC8FFF };
	inline constexpr pixel DarkSlateBlue{ 0x8B3D48FF };
	inline constexpr pixel DarkSlateGray{ 0x4F4F2FFF };
	inline constexpr pixel DarkTurquoise{ 0xD1CE00FF };
	inline constexpr pixel DarkViolet{ 0xD30094FF };
	inline constexpr pixel DeepPink{ 0x9314FFFF };
	inline constexpr pixel DeepSkyBlue{ 0xFFBF00FF };
	inline constexpr pixel DimGray{ 0x696969FF };
	inline constexpr pixel DodgerBlue{ 0xFF901EFF };
	inline constexpr pixel FireBrick{ 0x2222B2FF };
	inline constexpr pixel FloralWhite{ 0xF0FAFFFF };
	inline constexpr pixel ForestGreen{ 0x228B22FF };
	inline constexpr pixel Fuchsia{ 0xFF00FFFF };
	inline constexpr pixel GainsBoro{ 0xDCDCDCFF };
	inline constexpr pixel GhostWhite{ 0xFFF8F8FF };
	inline constexpr pixel Gold{ 0x00D7FFFF };
	inline constexpr pixel GoldenRod{ 0x20A5DAFF };
	inline constexpr pixel Gray{ 0x808080FF };
	inline constexpr pixel Green{ 0x008000FF };
	inline constexpr pixel GreenYellow{ 0x2FFFADFF };
	inline constexpr pixel HoneyDew{ 0xF0FFF0FF };
	inline constexpr pixel HotPink{ 0xB469FFFF };
	inline constexpr pixel IndianRed{ 0x5C5CCDFF };
	inline constexpr pixel Indigo{ 0x82004BFF };
	inline constexpr pixel Ivory{ 0xF0FFFFFF };
	inline constexpr pixel Khaki{ 0x8CE6F0FF };
	inline constexpr pixel Lavender{ 0xFAE6E6FF };
	inline constexpr pixel LavenderBlush{ 0xF5F0FFFF };
	inline constexpr pixel LawnGreen{ 0x00FC7CFF };
	inline constexpr pixel LemonChiffon{ 0xCDFAFFFF };
	inline constexpr pixel LightBlue{ 0xE6D8ADFF };
	inline constexpr pixel LightCoral{ 0x8080F0FF };
	inline constexpr pixel LightCyan{ 0xFFFFE0FF };
	inline constexpr pixel LightGoldenRodYellow{ 0xD2FAFAFF };
	inline constexpr pixel LightGray{ 0xD3D3D3FF };
	inline constexpr pixel LightGreen{ 0x90EE90FF };
	inline constexpr pixel LightPink{ 0xC1B6FFFF };
	inline constexpr pixel LightSalmon{ 0x7AA0FFFF };
	inline constexpr pixel LightSeaGreen{ 0xAAB220FF };
	inline constexpr pixel LightSkyBlue{ 0xFACE87FF };
	inline constexpr pixel LightSlateGray{ 0x998877FF };
	inline constexpr pixel LightSteelBlue{ 0xDEC4B0FF };
	inline constexpr pixel LightYellow{ 0xE0FFFFFF };
	inline constexpr pixel Lime{ 0x00FF00FF };
	inline constexpr pixel LimeGreen{ 0x32CD32FF };
	inline constexpr pixel Linen{ 0xE6F0FAFF };
	inline constexpr pixel Magenta{ 0xFF00FFFF };
	inline constexpr pixel Maroon{ 0x000080FF };
	inline constexpr pixel MediumAquaMarine{ 0xAACD66FF };
	inline constexpr pixel MediumBlue{ 0xCD0000FF };
	inline constexpr pixel MediumOrchid{ 0xD355BAFF };
	inline constexpr pixel MediumPurple{ 0xDB7093FF };
	inline constexpr pixel MediumSeaGreen{ 0x71B33CFF };
	inline constexpr pixel MediumSlateBlue{ 0xEE687BFF };
	inline constexpr pixel MediumSpringGreen{ 0x9AFA00FF };
	inline constexpr pixel MediumTurquoise{ 0xCCD148FF };
	inline constexpr pixel MediumVioletRed{ 0x8515C7FF };
	inline constexpr pixel MidnightBlue{ 0x701919FF };
	inline constexpr pixel MintCream{ 0xFAFFF5FF };
	inline constexpr pixel MistyRose{ 0xE1E4FFFF };
	inline constexpr pixel Moccasin{ 0xB5E4FFFF };
	inline constexpr pixel NavajoWhite{ 0xADDEFFFF };
	inline constexpr pixel Navy{ 0x800000FF };
	inline constexpr pixel OldLace{ 0xE6F5FDFF };
	inline constexpr pixel Olive{ 0x008080FF };
	inline constexpr pixel OliveDrab{ 0x238E6BFF };
	inline constexpr pixel Orange{ 0x00A5FFFF };
	inline constexpr pixel OrangeRed{ 0x0045FFFF };
	inline constexpr pixel Orchid{ 0xD670DAFF };
	inline constexpr pixel PaleGoldenRod{ 0xAAE8EEFF };
	inline constexpr pixel PaleGreen{ 0x98FB98FF };
	inline constexpr pixel PaleTurquoise{ 0xEEEEAFFF };
	inline constexpr pixel PaleVioletRed{ 0x9370DBFF };
	inline constexpr pixel PapayaWhip{ 0xD5EFFFFF };
	inline constexpr pixel PeachPuff{ 0xB9DAFFFF };
	inline constexpr pixel Peru{ 0x3F85CDFF };
	inline constexpr pixel Pink{ 0xCBC0FFFF };
	inline constexpr pixel Plum{ 0xDDA0DDFF };
	inline constexpr pixel PowderBlue{ 0xE6E0B0FF };
	inline constexpr pixel Purple{ 0x800080FF };
	inline constexpr pixel RebeccaPurple{ 0x993366FF };
	inline constexpr pixel Red{ 0x0000FFFF };
	inline constexpr pixel RosyBrown{ 0x8F8FBCFF };
	inline constexpr pixel RoyalBlue{ 0xE16941FF };
	inline constexpr pixel SaddleBrown{ 0x13458BFF };
	inline constexpr pixel Salmon{ 0x7280FAFF };
	inline constexpr pixel SandyBrown{ 0x60A4F4FF };
	inline constexpr pixel SeaGreen{ 0x578B2EFF };
	inline constexpr pixel SeaShell{ 0xEEF5FFFF };
	inline constexpr pixel Sienna{ 0x2D52A0FF };
	inline constexpr pixel Silver{ 0xC0C0C0FF };
	inline constexpr pixel SkyBlue{ 0xEBCE87FF };
	inline constexpr pixel SlateBlue{ 0xCD5A6AFF };
	inline constexpr pixel SlateGray{ 0x908070FF };
	inline constexpr pixel Snow{ 0xFAFAFFFF };
	inline constexpr pixel SpringGreen{ 0x7FFF00FF };
	inline constexpr pixel SteelBlue{ 0xB48246FF };
	inline constexpr pixel Tan{ 0x8CB4D2FF };
	inline constexpr pixel Teal{ 0x808000FF };
	inline constexpr pixel Thistle{ 0xD8BFD8FF };
	inline constexpr pixel Tomato{ 0x4763FFFF };
	inline constexpr pixel Transparent{ 0x00000000 };
	inline constexpr pixel Turquoise{ 0xD0E040FF };
	inline constexpr pixel Violet{ 0xEE82EEFF };
	inline constexpr pixel Wheat{ 0xB3DEF5FF };
	inline constexpr pixel White{ 0xFFFFFFFF };
	inline constexpr pixel WhiteSmoke{ 0xF5F5F5FF };
	inline constexpr pixel Yellow{ 0x00FFFFFF };
	inline constexpr pixel YellowGreen{ 0x32CD9AFF };

}