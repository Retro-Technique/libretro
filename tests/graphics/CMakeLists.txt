find_package(boost_unit_test_framework CONFIG REQUIRED)

add_executable(${PROJECT_NAME}-graphics-tests    
    "main.cpp" 
    "window.test.cpp"
)

target_link_libraries(${PROJECT_NAME}-graphics-tests
    PRIVATE
        ${PROJECT_NAME}-graphics
        Boost::unit_test_framework
)

add_test(NAME ${PROJECT_NAME}-graphics.Tests COMMAND ${PROJECT_NAME}-graphics-tests)