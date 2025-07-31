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
	tmx::property parse<tmx::property>(const boost::property_tree::ptree& pt)
	{
		return
		{
			._name = pt.get<std::string>("<xmlattr>.name", ""),
			._type = pt.get<std::string>("<xmlattr>.type", ""),
			._value = pt.get<std::string>("<xmlattr>.value", "")
		};
	}

	std::vector<tmx::property> parse_properties(const boost::property_tree::ptree& pt)
	{
		std::vector<tmx::property> properties;

		if (auto props = pt.get_child_optional("properties"))
		{
			for (const auto& [tag, child] : *props)
			{
				if (tag == "property")
				{
					properties.emplace_back(parse<tmx::property>(child));
				}
			}
		}

		return properties;
	}

	template<>
	tmx::layer parse<tmx::layer>(const boost::property_tree::ptree& pt)
	{
		return
		{
			._id = pt.get<std::int32_t>("<xmlattr>.id", 0),
			._name = pt.get<std::string>("<xmlattr>.name", ""),
			._class = pt.get<std::string>("<xmlattr>.class", ""),
			._width = pt.get<std::int32_t>("<xmlattr>.width", 0),
			._height = pt.get<std::int32_t>("<xmlattr>.height", 0),
			//._data = parse<tmx::data>(pt.get_child("data")),
			._properties = parse_properties(pt)
		};
	}

	template<>
	tmx::tileset parse<tmx::tileset>(const boost::property_tree::ptree& pt)
	{
		return
		{
			._firstgid = pt.get<std::int32_t>("<xmlattr>.firstgid", 0),
			._source = pt.get<std::string>("<xmlattr>.source", "")
		};
	}

	template<>
	tmx::object parse<tmx::object>(const boost::property_tree::ptree& pt)
	{
		tmx::object obj;

		obj._id = pt.get<std::int32_t>("<xmlattr>.id", 0);
		obj._name = pt.get<std::string>("<xmlattr>.name", "");
		obj._type = pt.get<std::string>("<xmlattr>.type", "");

#if 0
		if (pt.get_child_optional("point"))
		{
			obj._shape.emplace<tmx::point>(
				tmx::point{
					._x = pt.get<std::int32_t>("<xmlattr>.x", 0),
					._y = pt.get<std::int32_t>("<xmlattr>.y", 0)
				}
			);
		}
		else if (pt.get_child_optional("polygon"))
		{
			std::vector<std::int32_t> points;
			for (const auto& [tag, child] : pt.get_child("polygon"))
			{
				if (tag == "<xmlattr>")
				{
					std::string points_str = child.get<std::string>("points", "");
					std::istringstream iss(points_str);
					std::string point;
					while (std::getline(iss, point, ','))
					{
						points.push_back(std::stoi(point));
					}
				}
			}
			obj._shape.emplace<tmx::polygon>(tmx::polygon{ ._points = std::move(points) });
		}
		else if (pt.get_child_optional("ellipse"))
		{
			obj._shape.emplace<tmx::ellipse>(
				tmx::ellipse{
					._x = pt.get<std::int32_t>("<xmlattr>.x", 0),
					._y = pt.get<std::int32_t>("<xmlattr>.y", 0),
					._width = pt.get<std::int32_t>("<xmlattr>.width", 0),
					._height = pt.get<std::int32_t>("<xmlattr>.height", 0)
				}
			);
		}
		else
		{
			obj._shape.emplace<tmx::rectangle>(
				tmx::rectangle{
					._x = pt.get<std::int32_t>("<xmlattr>.x", 0),
					._y = pt.get<std::int32_t>("<xmlattr>.y", 0),
					._width = pt.get<std::int32_t>("<xmlattr>.width", 0),
					._height = pt.get<std::int32_t>("<xmlattr>.height", 0)
				}
			);
		}
#endif

		obj._properties = parse_properties(pt);

		return obj;
	}

	template<>
	tmx::object_group parse<tmx::object_group>(const boost::property_tree::ptree& pt)
	{
		std::vector<tmx::object> objects;

		for (const auto& [tag, child] : pt)
		{
			if (tag == "object")
			{
				objects.emplace_back(parse<tmx::object>(child));
			}
		}

		return
		{
			._id = pt.get<std::int32_t>("<xmlattr>.id", 0),
			._name = pt.get<std::string>("<xmlattr>.name", ""),
			._class = pt.get<std::string>("<xmlattr>.class", ""),
			._objects = std::move(objects),
			._properties = parse_properties(pt)
		};
	}

	template<>
	tmx::map parse<tmx::map>(const boost::property_tree::ptree& pt)
	{
		std::vector<tmx::tileset> tilesets;
		std::vector<tmx::layer> layers;
		std::vector<tmx::object_group> object_groups;

		for (const auto& [tag, child] : pt)
		{
			if (tag == "tileset")
			{
				tilesets.emplace_back(parse<tmx::tileset>(child));
			}
			else if (tag == "layer")
			{
				layers.emplace_back(parse<tmx::layer>(child));
			}
			else if (tag == "objectgroup")
			{
				object_groups.emplace_back(parse<tmx::object_group>(child));
			}
		}

		return
		{
			._tiledversion = pt.get<std::string>("<xmlattr>.tiledversion", ""),
			._orientation = pt.get<std::string>("<xmlattr>.orientation", ""),
			._renderorder = pt.get<std::string>("<xmlattr>.renderorder", ""),
			._width = pt.get<std::int32_t>("<xmlattr>.width", 0),
			._height = pt.get<std::int32_t>("<xmlattr>.height", 0),
			._tilewidth = pt.get<std::int32_t>("<xmlattr>.tilewidth", 0),
			._tileheight = pt.get<std::int32_t>("<xmlattr>.tileheight", 0),
			._infinite = pt.get<std::int32_t>("<xmlattr>.infinite", 0),
			._nextlayerid = pt.get<std::int32_t>("<xmlattr>.nextlayerid", 0),
			._nextobjectid = pt.get<std::int32_t>("<xmlattr>.nextobjectid", 0),
			._tilesets = std::move(tilesets),
			._layers = std::move(layers),
			._object_groups = std::move(object_groups),
		};
	}

}