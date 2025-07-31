#include <boost/test/unit_test.hpp>
#include <libretro/math.h>

BOOST_AUTO_TEST_SUITE(MatrixTests)

constexpr float epsilon = 1e-5f;

BOOST_AUTO_TEST_CASE(DefaultConstructor)
{
    retro::math::matrix3x3 m;

    auto id = retro::math::matrix3x3::identity();

    BOOST_CHECK(m == id);
}

#if 0

BOOST_AUTO_TEST_CASE(ParameterizedConstructor)
{
    retro::math::matrix3x3 m(1, 2, 3, 4, 5, 6, 7, 8, 9);

    const float* data = m.data().data();

    BOOST_CHECK_CLOSE(data[0], 1.f, epsilon);
    BOOST_CHECK_CLOSE(data[1], 2.f, epsilon);
    BOOST_CHECK_CLOSE(data[2], 3.f, epsilon);
    BOOST_CHECK_CLOSE(data[3], 4.f, epsilon);
    BOOST_CHECK_CLOSE(data[4], 5.f, epsilon);
    BOOST_CHECK_CLOSE(data[5], 6.f, epsilon);
    BOOST_CHECK_CLOSE(data[6], 7.f, epsilon);
    BOOST_CHECK_CLOSE(data[7], 8.f, epsilon);
    BOOST_CHECK_CLOSE(data[8], 9.f, epsilon);
}

BOOST_AUTO_TEST_CASE(Identity)
{
    auto id = retro::math::matrix3x3::identity();

    BOOST_CHECK(id == retro::math::matrix3x3());
}

BOOST_AUTO_TEST_CASE(Inverse)
{
    retro::math::matrix3x3 m(1, 2, 3, 0, 1, 4, 5, 6, 0);

    auto inv = m.inverse();
    auto prod = m * inv;

    BOOST_CHECK(prod == retro::math::matrix3x3::identity());
}

BOOST_AUTO_TEST_CASE(TransformVector)
{
    retro::math::matrix3x3 m;
    retro::math::vector2f v{ 1, 2 };

    auto res = m.transform(v);
    
    BOOST_CHECK_CLOSE(res.x, 1.f, epsilon);
    BOOST_CHECK_CLOSE(res.y, 2.f, epsilon);
}

BOOST_AUTO_TEST_CASE(TransformXY)
{
    retro::math::matrix3x3 m;

    auto res = m.transform(3.f, 4.f);

    BOOST_CHECK_CLOSE(res.x, 3.f, epsilon);
    BOOST_CHECK_CLOSE(res.y, 4.f, epsilon);
}

BOOST_AUTO_TEST_CASE(TransformRect)
{
    retro::math::matrix3x3 m;
    retro::math::floatrect r{ 1,2,3,4 };

    auto res = m.transform(r);

    BOOST_CHECK_CLOSE(res.left(), 1.f, epsilon);
    BOOST_CHECK_CLOSE(res.top(), 2.f, epsilon);
    BOOST_CHECK_CLOSE(res.size.x, 3.f, epsilon);
    BOOST_CHECK_CLOSE(res.size.y, 4.f, epsilon);
}

BOOST_AUTO_TEST_CASE(Combine)
{
    retro::math::matrix3x3 m1, m2;

    m1.translate(1, 2);
    m2.rotate(90);
    auto m3 = m1;
    m3.combine(m2);

    BOOST_CHECK(m3 == m1 * m2);
}

BOOST_AUTO_TEST_CASE(Translate)
{
    retro::math::matrix3x3 m;

    m.translate(5, 7);
    auto v = m.transform(0, 0);

    BOOST_CHECK_CLOSE(v.x, 5.f, epsilon);
    BOOST_CHECK_CLOSE(v.y, 7.f, epsilon);
}

BOOST_AUTO_TEST_CASE(Rotate)
{
    retro::math::matrix3x3 m;

    m.rotate(90);
    auto v = m.transform(1, 0);

    BOOST_CHECK_CLOSE(v.x, 0.f, 1e-4f);
    BOOST_CHECK_CLOSE(v.y, 1.f, 1e-4f);
}

BOOST_AUTO_TEST_CASE(Scale)
{
    retro::math::matrix3x3 m;

    m.scale(2, 3);
    auto v = m.transform(1, 1);

    BOOST_CHECK_CLOSE(v.x, 2.f, epsilon);
    BOOST_CHECK_CLOSE(v.y, 3.f, epsilon);
}

BOOST_AUTO_TEST_CASE(OperatorMultiply)
{
    retro::math::matrix3x3 m1, m2;

    m1.translate(1, 2);
    m2.scale(2, 2);
    auto m3 = m1 * m2;
    auto v = m3.transform(1, 1);

    BOOST_CHECK_CLOSE(v.x, 4.f, epsilon);
    BOOST_CHECK_CLOSE(v.y, 6.f, epsilon);
}

BOOST_AUTO_TEST_CASE(OperatorMultiplyVector)
{
    retro::math::matrix3x3 m;
    retro::math::vector2f v{ 3, 4 };

    m.translate(1, 2);
    auto res = m * v;

    BOOST_CHECK_CLOSE(res.x, 4.f, epsilon);
    BOOST_CHECK_CLOSE(res.y, 6.f, epsilon);
}

BOOST_AUTO_TEST_CASE(OperatorMultiplyAssign)
{
    retro::math::matrix3x3 m1, m2;

    m2.translate(2, 3);
    m1 *= m2;
    auto v = m1.transform(0, 0);

    BOOST_CHECK_CLOSE(v.x, 2.f, epsilon);
    BOOST_CHECK_CLOSE(v.y, 3.f, epsilon);
}

BOOST_AUTO_TEST_CASE(OperatorEquality)
{
    retro::math::matrix3x3 m1, m2;

    BOOST_CHECK(m1 == m2);

    m2.translate(1, 0);

    BOOST_CHECK(m1 != m2);
}

#endif

BOOST_AUTO_TEST_SUITE_END()