find_package(boost_unit_test_framework CONFIG REQUIRED)

add_executable(${PROJECT_NAME}-tiled-tests    
    "main.cpp" 
    "tsx.test.cpp"
    "tmx.test.cpp"
)

target_link_libraries(${PROJECT_NAME}-tiled-tests
    PRIVATE
        ${PROJECT_NAME}-tiled
        Boost::unit_test_framework
)

target_compile_definitions(${PROJECT_NAME}-tiled-tests
	PRIVATE
		TESTS_RESOURCE_DIRECTORY="${CMAKE_CURRENT_SOURCE_DIR}/res"
)

add_test(NAME ${PROJECT_NAME}-tiled.Tests COMMAND ${PROJECT_NAME}-tiled-tests)