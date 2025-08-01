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
#include "tsx_parser.h"
#include "tmx_parser.h"

namespace retro::tiled
{

	template<>
	tmx::map load_from_file<tmx::map>(const std::filesystem::path& file_path)
	{
		boost::property_tree::ptree pt;
		boost::property_tree::read_xml(file_path.string(), pt);

		return parse<tmx::map>(pt.get_child("map"));
	}

	template<>
	tsx::tileset load_from_file<tsx::tileset>(const std::filesystem::path& file_path)
	{
		boost::property_tree::ptree pt;
		boost::property_tree::read_xml(file_path.string(), pt);

		return parse<tsx::tileset>(pt.get_child("tileset"));
	}

	template LIBRETRO_TILED_API tmx::map load_from_file<tmx::map>(const std::filesystem::path& path);
	template LIBRETRO_TILED_API tsx::tileset load_from_file<tsx::tileset>(const std::filesystem::path& path);

}