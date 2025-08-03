#include <boost/test/unit_test.hpp>
#include <libretro/graphics.h>

BOOST_AUTO_TEST_SUITE(WindowTests)

BOOST_AUTO_TEST_CASE(DefaultConstructor)
{
	retro::graphics::window window;
}

BOOST_AUTO_TEST_SUITE_END()