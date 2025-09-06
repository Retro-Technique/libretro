#include <boost/test/unit_test.hpp>
#include <libretro/image.h>

BOOST_AUTO_TEST_SUITE(PixelTests)

BOOST_AUTO_TEST_CASE(DefaultConstructor)
{
    retro::image::pixel c;

    BOOST_TEST(c.r == 0);
    BOOST_TEST(c.g == 0);
    BOOST_TEST(c.b == 0);
    BOOST_TEST(c.a == retro::image::pixel::ALPHA_OPAQUE);
}

BOOST_AUTO_TEST_CASE(CopyConstructor)
{
    retro::image::pixel c1(10, 20, 30, 40);
    retro::image::pixel c2(c1);

    BOOST_TEST(c2.r == 10);
    BOOST_TEST(c2.g == 20);
    BOOST_TEST(c2.b == 30);
    BOOST_TEST(c2.a == 40);
}

BOOST_AUTO_TEST_CASE(Uint32ConstructorAndToInteger)
{
    retro::image::pixel c(0x11223344);

    BOOST_TEST(c.r == 0x11);
    BOOST_TEST(c.g == 0x22);
    BOOST_TEST(c.b == 0x33);
    BOOST_TEST(c.a == 0x44);
    BOOST_TEST(c.to_integer() == 0x11223344);
}

BOOST_AUTO_TEST_CASE(RgbaConstructor)
{
    retro::image::pixel c(1, 2, 3, 4);

    BOOST_TEST(c.r == 1);
    BOOST_TEST(c.g == 2);
    BOOST_TEST(c.b == 3);
    BOOST_TEST(c.a == 4);
}

BOOST_AUTO_TEST_CASE(IsOpaqueAndIsTransparent)
{
    retro::image::pixel opaque(1, 2, 3, retro::image::pixel::ALPHA_OPAQUE);
    retro::image::pixel transparent(1, 2, 3, retro::image::pixel::ALPHA_TRANSPARENT);

    BOOST_TEST(opaque.is_opaque());
    BOOST_TEST(!opaque.is_transparent());
    BOOST_TEST(!transparent.is_opaque());
    BOOST_TEST(transparent.is_transparent());
}

BOOST_AUTO_TEST_CASE(FromInteger)
{
    retro::image::pixel c;

    c.from_integer(0xAABBCCDD);

    BOOST_TEST(c.r == 0xAA);
    BOOST_TEST(c.g == 0xBB);
    BOOST_TEST(c.b == 0xCC);
    BOOST_TEST(c.a == 0xDD);
}

BOOST_AUTO_TEST_CASE(OperatorPlus)
{
    retro::image::pixel c1(10, 20, 30, 40);
    retro::image::pixel c2(250, 250, 250, 250);

    retro::image::pixel c3 = c1 + c2;

    BOOST_TEST(c3.r == 255);
    BOOST_TEST(c3.g == 255);
    BOOST_TEST(c3.b == 255);
    BOOST_TEST(c3.a == 255);
}

BOOST_AUTO_TEST_CASE(OperatorMinus)
{
    retro::image::pixel c1(10, 20, 30, 40);
    retro::image::pixel c2(5, 25, 15, 50);

    retro::image::pixel c3 = c1 - c2;

    BOOST_TEST(c3.r == 5);
    BOOST_TEST(c3.g == 0);
    BOOST_TEST(c3.b == 15);
    BOOST_TEST(c3.a == 0);
}

BOOST_AUTO_TEST_CASE(OperatorMultiply)
{
    retro::image::pixel c1(255, 128, 64, 32);
    retro::image::pixel c2(255, 128, 64, 32);

    retro::image::pixel c3 = c1 * c2;

    BOOST_TEST(c3.r == 255);
    BOOST_TEST(c3.g == 64);
    BOOST_TEST(c3.b == 16);
    BOOST_TEST(c3.a == 4);
}

BOOST_AUTO_TEST_CASE(OperatorPlusAssign)
{
    retro::image::pixel c1(10, 20, 30, 40);
    retro::image::pixel c2(5, 5, 5, 5);

    c1 += c2;

    BOOST_TEST(c1.r == 15);
    BOOST_TEST(c1.g == 25);
    BOOST_TEST(c1.b == 35);
    BOOST_TEST(c1.a == 45);
}

BOOST_AUTO_TEST_CASE(OperatorMinusAssign)
{
    retro::image::pixel c1(10, 20, 30, 40);
    retro::image::pixel c2(5, 25, 15, 50);

    c1 -= c2;

    BOOST_TEST(c1.r == 5);
    BOOST_TEST(c1.g == 0);
    BOOST_TEST(c1.b == 15);
    BOOST_TEST(c1.a == 0);
}

BOOST_AUTO_TEST_CASE(OperatorMultiplyAssign)
{
    retro::image::pixel c1(255, 128, 64, 32);
    retro::image::pixel c2(255, 128, 64, 32);

    c1 *= c2;

    BOOST_TEST(c1.r == 255);
    BOOST_TEST(c1.g == 64);
    BOOST_TEST(c1.b == 16);
    BOOST_TEST(c1.a == 4);
}

BOOST_AUTO_TEST_CASE(OperatorEqualAndNotEqual)
{
    retro::image::pixel c1(1, 2, 3, 4);
    retro::image::pixel c2(1, 2, 3, 4);
    retro::image::pixel c3(4, 3, 2, 1);

    BOOST_TEST(c1 == c2);
    BOOST_TEST(!(c1 != c2));
    BOOST_TEST(c1 != c3);
    BOOST_TEST(!(c1 == c3));
}

BOOST_AUTO_TEST_SUITE_END()