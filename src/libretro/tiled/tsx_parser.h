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

#include "parser.h"

namespace retro::tiled
{

	template<>
	tsx::image parse<tsx::image>(const boost::property_tree::ptree& pt)
	{
		return
		{
			._source = pt.get<std::string>("<xmlattr>.source", ""),
			._trans = pt.get<std::string>("<xmlattr>.trans", ""),
			._width = pt.get<std::int32_t>("<xmlattr>.width", 0),
			._height = pt.get<std::int32_t>("<xmlattr>.height", 0)
		};
	}

	template<>
	tsx::tileset parse<tsx::tileset>(const boost::property_tree::ptree& pt)
	{
		return
		{
			._tiledversion = pt.get<std::string>("<xmlattr>.tiledversion", ""),
			._name = pt.get<std::string>("<xmlattr>.name", ""),
			._tilewidth = pt.get<std::int32_t>("<xmlattr>.tilewidth", 0),
			._tileheight = pt.get<std::int32_t>("<xmlattr>.tileheight", 0),
			._spacing = pt.get<std::int32_t>("<xmlattr>.spacing", 0),
			._margin = pt.get<std::int32_t>("<xmlattr>.margin", 0),
			._tilecount = pt.get<std::int32_t>("<xmlattr>.tilecount", 0),
			._columns = pt.get<std::int32_t>("<xmlattr>.columns", 0),
			._image = pt.get_child_optional("image")
				? parse<tsx::image>(pt.get_child("image"))
				: tsx::image{}
		};
	}

}