#include <boost/test/unit_test.hpp>
#include <libretro/math.h>

BOOST_AUTO_TEST_SUITE(Vector2Tests)

BOOST_AUTO_TEST_CASE(DefaultConstructor)
{
    retro::math::vector2f v;

	BOOST_TEST(0.f == v.x);
	BOOST_TEST(0.f == v.y);
}

BOOST_AUTO_TEST_CASE(ParameterizedConstructor)
{
    retro::math::vector2i v(3, 4);

    BOOST_TEST(v.x == 3);
    BOOST_TEST(v.y == 4);
}

BOOST_AUTO_TEST_CASE(CopyConversionConstructor)
{
    retro::math::vector2i vi(10, 20);
    retro::math::vector2f vf(vi);

    BOOST_TEST(vf.x == 10.0f);
    BOOST_TEST(vf.y == 20.0f);
}

BOOST_AUTO_TEST_CASE(UnaryMinus)
{
    retro::math::vector2i v(1, -2);
    auto neg = -v;

    BOOST_TEST(neg.x == -1);
    BOOST_TEST(neg.y == 2);
}

BOOST_AUTO_TEST_CASE(AdditionAndSubtraction)
{
    retro::math::vector2i a(1, 2);
    retro::math::vector2i b(3, 4);

    auto c = a + b;
    BOOST_TEST(c.x == 4);
    BOOST_TEST(c.y == 6);

    c = b - a;
    BOOST_TEST(c.x == 2);
    BOOST_TEST(c.y == 2);
}

BOOST_AUTO_TEST_CASE(MultiplicationAndDivision, *boost::unit_test::tolerance(0.0001))
{
    retro::math::vector2f v(2.0f, 4.0f);

    auto m = v * 2.0f;
    BOOST_TEST(m.x == 4.0f);
    BOOST_TEST(m.y == 8.0f);

    auto d = v / 2.0f;
    BOOST_TEST(d.x == 1.0f);
    BOOST_TEST(d.y == 2.0f);

    auto n = 3.0f * v;
    BOOST_TEST(n.x == 6.0f);
    BOOST_TEST(n.y, 12.0f);
}

BOOST_AUTO_TEST_CASE(CompoundAssignments)
{
    retro::math::vector2i v(5, 10);
    v += retro::math::vector2i(2, 3);
    BOOST_TEST(v.x == 7);
    BOOST_TEST(v.y == 13);

    v -= retro::math::vector2i(1, 1);
    BOOST_TEST(v.x == 6);
    BOOST_TEST(v.y == 12);

    v *= 2;
    BOOST_TEST(v.x == 12);
    BOOST_TEST(v.y == 24);

    v /= 3;
    BOOST_TEST(v.x == 4);
    BOOST_TEST(v.y == 8);
}

BOOST_AUTO_TEST_CASE(EqualityOperators)
{
    retro::math::vector2i a(1, 1);
    retro::math::vector2i b(1, 1);
    retro::math::vector2i c(2, 3);

    BOOST_TEST(a == b);
    BOOST_TEST(!(a != b));
    BOOST_TEST(a != c);
}

BOOST_AUTO_TEST_SUITE_END()