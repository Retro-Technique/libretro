#include <boost/test/unit_test.hpp>
#include <libretro/image.h>

BOOST_AUTO_TEST_SUITE(ColorTests)

BOOST_AUTO_TEST_CASE(DefaultConstructor)
{
    retro::image::color c;

    BOOST_TEST(c.red == 0);
    BOOST_TEST(c.green == 0);
    BOOST_TEST(c.blue == 0);
    BOOST_TEST(c.alpha == retro::image::color::ALPHA_OPAQUE);
}

BOOST_AUTO_TEST_CASE(CopyConstructor)
{
    retro::image::color c1(10, 20, 30, 40);
    retro::image::color c2(c1);

    BOOST_TEST(c2.red == 10);
    BOOST_TEST(c2.green == 20);
    BOOST_TEST(c2.blue == 30);
    BOOST_TEST(c2.alpha == 40);
}

BOOST_AUTO_TEST_CASE(Uint32ConstructorAndToInteger)
{
    retro::image::color c(0x11223344);

    BOOST_TEST(c.red == 0x11);
    BOOST_TEST(c.green == 0x22);
    BOOST_TEST(c.blue == 0x33);
    BOOST_TEST(c.alpha == 0x44);
    BOOST_TEST(c.to_integer() == 0x11223344);
}

BOOST_AUTO_TEST_CASE(RgbaConstructor)
{
    retro::image::color c(1, 2, 3, 4);

    BOOST_TEST(c.red == 1);
    BOOST_TEST(c.green == 2);
    BOOST_TEST(c.blue == 3);
    BOOST_TEST(c.alpha == 4);
}

BOOST_AUTO_TEST_CASE(IsOpaqueAndIsTransparent)
{
    retro::image::color opaque(1, 2, 3, retro::image::color::ALPHA_OPAQUE);
    retro::image::color transparent(1, 2, 3, retro::image::color::ALPHA_TRANSPARENT);

    BOOST_TEST(opaque.is_opaque());
    BOOST_TEST(!opaque.is_transparent());
    BOOST_TEST(!transparent.is_opaque());
    BOOST_TEST(transparent.is_transparent());
}

BOOST_AUTO_TEST_CASE(FromInteger)
{
    retro::image::color c;

    c.from_integer(0xAABBCCDD);

    BOOST_TEST(c.red == 0xAA);
    BOOST_TEST(c.green == 0xBB);
    BOOST_TEST(c.blue == 0xCC);
    BOOST_TEST(c.alpha == 0xDD);
}

BOOST_AUTO_TEST_CASE(OperatorPlus)
{
    retro::image::color c1(10, 20, 30, 40);
    retro::image::color c2(250, 250, 250, 250);

    retro::image::color c3 = c1 + c2;

    BOOST_TEST(c3.red == 255);
    BOOST_TEST(c3.green == 255);
    BOOST_TEST(c3.blue == 255);
    BOOST_TEST(c3.alpha == 255);
}

BOOST_AUTO_TEST_CASE(OperatorMinus)
{
    retro::image::color c1(10, 20, 30, 40);
    retro::image::color c2(5, 25, 15, 50);

    retro::image::color c3 = c1 - c2;

    BOOST_TEST(c3.red == 5);
    BOOST_TEST(c3.green == 0);
    BOOST_TEST(c3.blue == 15);
    BOOST_TEST(c3.alpha == 0);
}

BOOST_AUTO_TEST_CASE(OperatorMultiply)
{
    retro::image::color c1(255, 128, 64, 32);
    retro::image::color c2(255, 128, 64, 32);

    retro::image::color c3 = c1 * c2;

    BOOST_TEST(c3.red == 255);
    BOOST_TEST(c3.green == 64);
    BOOST_TEST(c3.blue == 16);
    BOOST_TEST(c3.alpha == 4);
}

BOOST_AUTO_TEST_CASE(OperatorPlusAssign)
{
    retro::image::color c1(10, 20, 30, 40);
    retro::image::color c2(5, 5, 5, 5);

    c1 += c2;

    BOOST_TEST(c1.red == 15);
    BOOST_TEST(c1.green == 25);
    BOOST_TEST(c1.blue == 35);
    BOOST_TEST(c1.alpha == 45);
}

BOOST_AUTO_TEST_CASE(OperatorMinusAssign)
{
    retro::image::color c1(10, 20, 30, 40);
    retro::image::color c2(5, 25, 15, 50);

    c1 -= c2;

    BOOST_TEST(c1.red == 5);
    BOOST_TEST(c1.green == 0);
    BOOST_TEST(c1.blue == 15);
    BOOST_TEST(c1.alpha == 0);
}

BOOST_AUTO_TEST_CASE(OperatorMultiplyAssign)
{
    retro::image::color c1(255, 128, 64, 32);
    retro::image::color c2(255, 128, 64, 32);

    c1 *= c2;

    BOOST_TEST(c1.red == 255);
    BOOST_TEST(c1.green == 64);
    BOOST_TEST(c1.blue == 16);
    BOOST_TEST(c1.alpha == 4);
}

BOOST_AUTO_TEST_CASE(OperatorEqualAndNotEqual)
{
    retro::image::color c1(1, 2, 3, 4);
    retro::image::color c2(1, 2, 3, 4);
    retro::image::color c3(4, 3, 2, 1);

    BOOST_TEST(c1 == c2);
    BOOST_TEST(!(c1 != c2));
    BOOST_TEST(c1 != c3);
    BOOST_TEST(!(c1 == c3));
}

BOOST_AUTO_TEST_SUITE_END()