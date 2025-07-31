#include <boost/test/unit_test.hpp>
#include <libretro/math.h>

BOOST_AUTO_TEST_SUITE(MatrixStackTests)

BOOST_AUTO_TEST_CASE(DefaultConstructor)
{
    retro::math::matrix_stack_8 stack;

    BOOST_CHECK_EQUAL(stack.size(), 1);
    BOOST_CHECK(stack.top() == retro::math::matrix3x3::identity());
}

BOOST_AUTO_TEST_CASE(PushAndPop)
{
    retro::math::matrix_stack_8 stack;

    stack.push();
    BOOST_CHECK_EQUAL(stack.size(), 2);
    stack.pop();
    BOOST_CHECK_EQUAL(stack.size(), 1);
    stack.pop(); 
    BOOST_CHECK_EQUAL(stack.size(), 1);
}

BOOST_AUTO_TEST_CASE(Identity)
{
    retro::math::matrix_stack_8 stack;
    retro::math::matrix3x3 m;

    m.translate({ 2.0f, 3.0f });
    stack.load(m);
    BOOST_CHECK(stack.top() == m);
    stack.identity();
    BOOST_CHECK(stack.top() == retro::math::matrix3x3::identity());
}

BOOST_AUTO_TEST_CASE(Load)
{
    retro::math::matrix_stack_8 stack;
    retro::math::matrix3x3 m;

    m.translate({ 1.0f, 2.0f });
    stack.load(m);

    BOOST_CHECK(stack.top() == m);
}

BOOST_AUTO_TEST_CASE(Multiply)
{
    retro::math::matrix_stack_8 stack;
    retro::math::matrix3x3 m;

    m.scale(2.0f, { 0.0f, 0.0f });
    stack.multiply(m);

    retro::math::matrix3x3 expected = retro::math::matrix3x3::identity() * m;

    BOOST_CHECK(stack.top() == expected);
}

BOOST_AUTO_TEST_CASE(Rotate)
{
    retro::math::matrix_stack_8 stack;
    retro::math::matrix3x3 m;

    stack.rotate(3.14f, { 1.0f, 2.0f });
    m.rotate(3.14f, { 1.0f, 2.0f });

    BOOST_CHECK(stack.top() == retro::math::matrix3x3::identity() * m);
}

BOOST_AUTO_TEST_CASE(Scale)
{
    retro::math::matrix_stack_8 stack;
    retro::math::matrix3x3 m;

    stack.scale(2.0f, { 1.0f, 1.0f });
    m.scale(2.0f, { 1.0f, 1.0f });

    BOOST_CHECK(stack.top() == retro::math::matrix3x3::identity() * m);
}

BOOST_AUTO_TEST_CASE(Translate)
{
    retro::math::matrix_stack_8 stack;
    retro::math::matrix3x3 m;

    stack.translate({ 5.0f, 6.0f });
    m.translate({ 5.0f, 6.0f });

    BOOST_CHECK(stack.top() == retro::math::matrix3x3::identity() * m);
}

BOOST_AUTO_TEST_CASE(PushCopiesTop)
{
    retro::math::matrix_stack_8 stack;

    stack.translate({ 1.0f, 2.0f });
    retro::math::matrix3x3 before = stack.top();
    stack.push();

    BOOST_CHECK(stack.top() == before);
}

BOOST_AUTO_TEST_SUITE_END()