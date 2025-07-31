#include <boost/test/unit_test.hpp>
#include <libretro/math.h>

BOOST_AUTO_TEST_SUITE(CollideTests)

BOOST_AUTO_TEST_CASE(Collide_Vector2_Vector2)
{
    retro::math::vector2f a{1.0f, 2.0f};
    retro::math::vector2f b{1.0f, 2.0f};
    retro::math::vector2f c{2.0f, 3.0f};

    BOOST_CHECK(retro::math::collide(a, b));
    BOOST_CHECK(!retro::math::collide(a, c));
}

BOOST_AUTO_TEST_CASE(Collide_Vector2_Line)
{
    retro::math::vector2f p{1.0f, 1.0f};
    retro::math::floatline l{{0.0f, 1.0f}, {2.0f, 1.0f}};

    BOOST_CHECK(retro::math::collide(p, l));

    retro::math::vector2f q{3.0f, 1.0f};

    BOOST_CHECK(!retro::math::collide(q, l));
}

BOOST_AUTO_TEST_CASE(Collide_Line_Vector2)
{
    retro::math::floatline l{{0.0f, 1.0f}, {2.0f, 1.0f}};
    retro::math::vector2f p{1.0f, 1.0f};

    BOOST_CHECK(retro::math::collide(l, p));
}

BOOST_AUTO_TEST_CASE(Collide_Line_Line)
{
    retro::math::floatline l1{{0.0f, 0.0f}, {2.0f, 2.0f}};
    retro::math::floatline l2{{0.0f, 2.0f}, {2.0f, 0.0f}};
    retro::math::floatline l3{{0.0f, 1.0f}, {2.0f, 1.0f}};
    retro::math::floatline l4{{3.0f, 3.0f}, {4.0f, 4.0f}};

    BOOST_CHECK(retro::math::collide(l1, l2));
    BOOST_CHECK(!retro::math::collide(l1, l4));
    BOOST_CHECK(retro::math::collide(l1, l3)); 
}

BOOST_AUTO_TEST_CASE(Collide_Vector2_Rect)
{
    retro::math::floatrect r{0.0f, 0.0f, 2.0f, 2.0f};
    retro::math::vector2f p{1.0f, 1.0f};
    retro::math::vector2f q{3.0f, 3.0f};

    BOOST_CHECK(retro::math::collide(p, r));
    BOOST_CHECK(!retro::math::collide(q, r));
}

BOOST_AUTO_TEST_CASE(Collide_Rect_Vector2)
{
    retro::math::floatrect r{0.0f, 0.0f, 2.0f, 2.0f};
    retro::math::vector2f p{1.0f, 1.0f};

    BOOST_CHECK(retro::math::collide(r, p));
}

BOOST_AUTO_TEST_CASE(Collide_Line_Rect)
{
    retro::math::floatrect r{0.0f, 0.0f, 2.0f, 2.0f};
    retro::math::floatline l1{{-1.0f, 1.0f}, {3.0f, 1.0f}};
    retro::math::floatline l2{{3.0f, 3.0f}, {4.0f, 4.0f}};

    BOOST_CHECK(retro::math::collide(l1, r));
    BOOST_CHECK(!retro::math::collide(l2, r));
}

BOOST_AUTO_TEST_CASE(Collide_Rect_Line)
{
    retro::math::floatrect r{0.0f, 0.0f, 2.0f, 2.0f};
    retro::math::floatline l{{-1.0f, 1.0f}, {3.0f, 1.0f}};

    BOOST_CHECK(retro::math::collide(r, l));
}

BOOST_AUTO_TEST_CASE(Collide_Rect_Rect)
{
    retro::math::floatrect r1{0.0f, 0.0f, 2.0f, 2.0f};
    retro::math::floatrect r2{1.0f, 1.0f, 3.0f, 3.0f};
    retro::math::floatrect r3{3.0f, 3.0f, 4.0f, 4.0f};

    BOOST_CHECK(retro::math::collide(r1, r2));
    BOOST_CHECK(!retro::math::collide(r1, r3));
}

BOOST_AUTO_TEST_CASE(Collide_Circle_Vector2)
{
    retro::math::floatcircle c{{1.0f, 1.0f}, 1.0f};
    retro::math::vector2f p{1.0f, 2.0f};
    retro::math::vector2f q{3.0f, 3.0f};

    BOOST_CHECK(retro::math::collide(c, p));
    BOOST_CHECK(!retro::math::collide(c, q));
}

BOOST_AUTO_TEST_CASE(Collide_Vector2_Circle)
{
    retro::math::vector2f p{1.0f, 2.0f};
    retro::math::floatcircle c{{1.0f, 1.0f}, 1.0f};

    BOOST_CHECK(retro::math::collide(p, c));
}

BOOST_AUTO_TEST_CASE(Collide_Line_Circle)
{
    retro::math::floatline l{{0.0f, 1.0f}, {2.0f, 1.0f}};
    retro::math::floatcircle c{{1.0f, 1.0f}, 0.5f};
    retro::math::floatcircle d{{3.0f, 3.0f}, 0.5f};

    BOOST_CHECK(retro::math::collide(l, c));
    BOOST_CHECK(!retro::math::collide(l, d));
}

BOOST_AUTO_TEST_CASE(Collide_Circle_Line)
{
    retro::math::floatcircle c{{1.0f, 1.0f}, 0.5f};
    retro::math::floatline l{{0.0f, 1.0f}, {2.0f, 1.0f}};

    BOOST_CHECK(retro::math::collide(c, l));
}

BOOST_AUTO_TEST_CASE(Collide_Circle_Rect)
{
    retro::math::floatcircle c{{1.0f, 1.0f}, 1.0f};
    retro::math::floatrect r{0.0f, 0.0f, 2.0f, 2.0f};
    retro::math::floatrect s{3.0f, 3.0f, 4.0f, 4.0f};

    BOOST_CHECK(retro::math::collide(c, r));
    BOOST_CHECK(!retro::math::collide(c, s));
}

BOOST_AUTO_TEST_CASE(Collide_Rect_Circle)
{
    retro::math::floatrect r{0.0f, 0.0f, 2.0f, 2.0f};
    retro::math::floatcircle c{{1.0f, 1.0f}, 1.0f};

    BOOST_CHECK(retro::math::collide(r, c));
}

BOOST_AUTO_TEST_CASE(Collide_Circle_Circle)
{
    retro::math::floatcircle c1{{1.0f, 1.0f}, 1.0f};
    retro::math::floatcircle c2{{2.0f, 1.0f}, 1.0f};
    retro::math::floatcircle c3{{4.0f, 4.0f}, 1.0f};

    BOOST_CHECK(retro::math::collide(c1, c2));
    BOOST_CHECK(!retro::math::collide(c1, c3));
}

BOOST_AUTO_TEST_SUITE_END()