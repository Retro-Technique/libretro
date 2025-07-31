#include <boost/test/unit_test.hpp>
#include <libretro/math.h>

BOOST_AUTO_TEST_SUITE(CircleTests)

BOOST_AUTO_TEST_CASE(ConstructorTests)
{
    retro::math::floatcircle c1;
    BOOST_TEST(c1.center.x == 0.0f);
    BOOST_TEST(c1.center.y == 0.0f);
    BOOST_TEST(c1.radius == 0.0f);

    retro::math::floatcircle c2(1.0f, 2.0f, 5.0f);
    BOOST_TEST(c2.center == retro::math::vector2f(1.0f, 2.0f));
    BOOST_TEST(c2.radius == 5.0f);

    retro::math::vector2f center{ 3.0f, 4.0f };
    retro::math::floatcircle c3(center, 2.5f);
    BOOST_TEST(c3.center == center);
    BOOST_TEST(c3.radius == 2.5f);
}

BOOST_AUTO_TEST_CASE(EqualityTests)
{
    retro::math::intcircle a(1, 2, 5);
    retro::math::intcircle b(1, 2, 5);
    retro::math::intcircle c(2, 2, 5);
    retro::math::intcircle d(1, 2, 6);

    BOOST_TEST(a == b);
    BOOST_TEST(!(a == c));
    BOOST_TEST(a != c);
    BOOST_TEST(a != d);
}

BOOST_AUTO_TEST_CASE(DiameterAreaTests, *boost::unit_test::tolerance(0.0001))
{
    retro::math::floatcircle c({ 0.0f, 0.0f }, 3.0f);

    BOOST_TEST(c.diameter() == 6.0f);

    const float expected_area = std::numbers::pi_v<float> * 9.0f;
    BOOST_TEST(expected_area == c.area());
}

BOOST_AUTO_TEST_CASE(EmptyNullTests)
{
    retro::math::intcircle c1(0, 0, 0);
    retro::math::intcircle c2(1, 1, 0);
    retro::math::intcircle c3(0, 0, 2);

    BOOST_TEST(c1.null());
    BOOST_TEST(c1.empty());

    BOOST_TEST(!c2.null());
    BOOST_TEST(c2.empty());

    BOOST_TEST(!c3.null());
    BOOST_TEST(!c3.empty());
}

BOOST_AUTO_TEST_SUITE_END()