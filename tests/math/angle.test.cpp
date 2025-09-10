#include <boost/test/unit_test.hpp>
#include <libretro/math.h>

BOOST_AUTO_TEST_SUITE(AngleTests)

BOOST_AUTO_TEST_CASE(ConstructorAndGetters)
{
    retro::math::anglef a1;
    BOOST_TEST(a1.rad() == 0.0f);

    retro::math::anglef a2 = retro::math::anglef::from_radians(std::numbers::pi_v<std::float_t>);
    BOOST_TEST(a2.rad() == std::numbers::pi_v<std::float_t>);
    BOOST_TEST(a2.deg() == 180.0f);

    retro::math::anglef a3 = retro::math::anglef::from_degrees(90.0f);
    BOOST_TEST(a3.rad() == std::numbers::pi_v<std::float_t> / 2.0f, boost::test_tools::tolerance(1e-6f));
    BOOST_TEST(a3.deg() == 90.0f);
}

BOOST_AUTO_TEST_CASE(Normalization)
{
    retro::math::anglef a = retro::math::anglef::from_degrees(450.0f); 
    auto n = a.normalize();
    BOOST_TEST(n.deg() == 90.0f, boost::test_tools::tolerance(1e-6f));

    retro::math::anglef b = retro::math::anglef::from_degrees(-90.0f); 
    auto m = b.normalize();
    BOOST_TEST(m.deg() == 270.0f, boost::test_tools::tolerance(1e-6f));
}
//
//BOOST_AUTO_TEST_CASE(Arithmetic)
//{
//    retro::math::anglef a = retro::math::anglef::from_degrees(30.0f);
//    retro::math::anglef b = retro::math::anglef::from_degrees(45.0f);
//
//    auto sum = a + b;
//    BOOST_TEST(sum.deg() == 75.0f, boost::test_tools::tolerance(1e-6f));
//
//    auto diff = b - a;
//    BOOST_TEST(diff.deg() == 15.0f, boost::test_tools::tolerance(1e-6f));
//}

BOOST_AUTO_TEST_CASE(Equality)
{
    retro::math::anglef a = retro::math::anglef::from_degrees(180.0f);
    retro::math::anglef b = retro::math::anglef::from_radians(std::numbers::pi_v<std::float_t>);

    BOOST_TEST(a == b);
    BOOST_TEST(!(a != b));

    retro::math::anglef c = retro::math::anglef::from_degrees(180.00001f);
    BOOST_TEST(a != c);
}

BOOST_AUTO_TEST_SUITE_END()