#include <boost/test/unit_test.hpp>
#include <libretro/math.h>

BOOST_AUTO_TEST_SUITE(RectTests)

BOOST_AUTO_TEST_CASE(DefaultConstructor)
{
    retro::math::intrect r;

    BOOST_TEST(r.point.x == 0);
    BOOST_TEST(r.point.y == 0);
    BOOST_TEST(r.size.x == 0);
    BOOST_TEST(r.size.y == 0);
    BOOST_TEST(r.null());
    BOOST_TEST(r.empty());
}

BOOST_AUTO_TEST_CASE(ParameterizedConstructor)
{
    retro::math::intrect r(10, 20, 30, 40);

    BOOST_TEST(r.left() == 10);
    BOOST_TEST(r.top() == 20);
    BOOST_TEST(r.right() == 40);   // 10 + 30
    BOOST_TEST(r.bottom() == 60);  // 20 + 40
    BOOST_TEST(!r.empty());
    BOOST_TEST(!r.null());
}

BOOST_AUTO_TEST_CASE(AreaAndCenter)
{
    retro::math::intrect r(0, 0, 20, 10);

    BOOST_TEST(r.area() == 200);
    BOOST_TEST(r.center().x == 10);  // 0 + 20/2
    BOOST_TEST(r.center().y == 5);   // 0 + 10/2
}

BOOST_AUTO_TEST_CASE(EmptyRect)
{
    retro::math::intrect r1(0, 0, 0, 10);
    retro::math::intrect r2(0, 0, 10, 0);
    retro::math::intrect r3(0, 0, -5, 10);

    BOOST_TEST(r1.empty());
    BOOST_TEST(r2.empty());
    BOOST_TEST(r3.empty());
}

BOOST_AUTO_TEST_CASE(EqualityOperators)
{
    retro::math::intrect r1(1, 2, 3, 4);
    retro::math::intrect r2(1, 2, 3, 4);
    retro::math::intrect r3(0, 0, 3, 4);

    BOOST_TEST(r1 == r2);
    BOOST_TEST(r1 != r3);
}

BOOST_AUTO_TEST_CASE(ConvertConstructor)
{
    retro::math::intrect ri(10, 20, 30, 40);
    retro::math::floatrect rf(ri);

    BOOST_TEST(rf.point.x == 10.0f);
    BOOST_TEST(rf.point.y == 20.0f);
    BOOST_TEST(rf.size.x == 30.0f);
    BOOST_TEST(rf.size.y == 40.0f);
}

BOOST_AUTO_TEST_SUITE_END()