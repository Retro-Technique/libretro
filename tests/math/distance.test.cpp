#include <boost/test/unit_test.hpp>
#include <libretro/math.h>

BOOST_AUTO_TEST_SUITE(DistanceTests)

BOOST_AUTO_TEST_CASE(EuclidianDistance_Vector2)
{
    using v2f = retro::math::vector2f;
    
    BOOST_CHECK_CLOSE(retro::math::euclidian_distance(v2f{ 0, 0 }, v2f{ 3, 4 }), 5.f, 0.0001f);
    BOOST_CHECK_SMALL(retro::math::euclidian_distance(v2f{ 1, 1 }, v2f{ 1, 1 }), 0.0001f);
}

BOOST_AUTO_TEST_CASE(EuclidianDistance_Scalars)
{
    BOOST_CHECK_CLOSE(retro::math::euclidian_distance(0.0, 0.0, 3.0, 4.0), 5.0, 0.0001);
    BOOST_CHECK_SMALL(retro::math::euclidian_distance(1.0, 1.0, 1.0, 1.0), 0.0001);
}

BOOST_AUTO_TEST_CASE(ManhattanDistance_Vector2)
{
    using v2i = retro::math::vector2i;

    BOOST_CHECK_EQUAL(retro::math::manhattan_distance(v2i{ 0, 0 }, v2i{ 3, 4 }), 7);
    BOOST_CHECK_EQUAL(retro::math::manhattan_distance(v2i{ 1, 1 }, v2i{ 1, 1 }), 0);
}

BOOST_AUTO_TEST_CASE(ManhattanDistance_Scalars)
{
    BOOST_CHECK_EQUAL(retro::math::manhattan_distance(0, 0, 3, 4), 7);
    BOOST_CHECK_EQUAL(retro::math::manhattan_distance(1, 1, 1, 1), 0);
    BOOST_CHECK_EQUAL(retro::math::manhattan_distance(-1, -2, 3, 4), 10);
}

BOOST_AUTO_TEST_CASE(EdgeCases)
{
    BOOST_CHECK_CLOSE(retro::math::euclidian_distance(0.f, 0.f, 0.f, 0.f), 0.f, 0.0001f);
    BOOST_CHECK_EQUAL(retro::math::manhattan_distance(0, 0, 0, 0), 0);
}

BOOST_AUTO_TEST_SUITE_END()