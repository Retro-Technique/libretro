find_package(boost_unit_test_framework CONFIG REQUIRED)

add_executable(${PROJECT_NAME}-math-tests    
    "main.cpp" 
    "vector2.test.cpp"
    "rect.test.cpp" 
    "line.test.cpp" 
    "circle.test.cpp"
    "distance.test.cpp"
    "collide.test.cpp"
    "matrix3x3.test.cpp"
    "matrix_stack.test.cpp"
)

target_link_libraries(${PROJECT_NAME}-math-tests
    PRIVATE
        ${PROJECT_NAME}-math
        Boost::unit_test_framework
)

add_test(NAME 
        ${PROJECT_NAME}-math.Tests 
    COMMAND 
        ${PROJECT_NAME}-math-tests
)