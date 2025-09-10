#include <boost/test/unit_test.hpp>
#include <libretro/math.h>

BOOST_AUTO_TEST_SUITE(LineTests)

BOOST_AUTO_TEST_CASE(DefaultConstructor)
{
	retro::math::floatline l;

    BOOST_TEST(l.start.x == 0.0f);
    BOOST_TEST(l.start.y == 0.0f);
    BOOST_TEST(l.end.x == 0.0f);
    BOOST_TEST(l.end.y == 0.0f);
}

BOOST_AUTO_TEST_CASE(CenterTest)
{
    retro::math::floatline l({ 2.0f, 4.0f }, { 6.0f, 8.0f });

    const auto c = l.center();

    BOOST_TEST(c.x == 4.0f);
    BOOST_TEST(c.y == 6.0f);
}

BOOST_AUTO_TEST_CASE(AngleTest, *boost::unit_test::tolerance(0.0001))
{
    retro::math::floatline l({ 0.0f, 0.0f }, { 0.0f, 1.0f });

    const retro::math::anglef angle = l.angle();

    BOOST_TEST(angle.rad() == std::numbers::pi_v<std::float_t> / 2.0f);
}

BOOST_AUTO_TEST_SUITE_END()