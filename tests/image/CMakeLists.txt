find_package(boost_unit_test_framework CONFIG REQUIRED)

add_executable(${PROJECT_NAME}-image-tests    
    "main.cpp" 
    "color.test.cpp"
    "bitmap.test.cpp"
)

target_link_libraries(${PROJECT_NAME}-image-tests
    PRIVATE
        ${PROJECT_NAME}-image
        Boost::unit_test_framework
)

target_compile_definitions(${PROJECT_NAME}-image-tests
	PRIVATE
		TESTS_RESOURCE_DIRECTORY="${CMAKE_CURRENT_SOURCE_DIR}/res"
)

add_test(NAME ${PROJECT_NAME}-image.Tests COMMAND ${PROJECT_NAME}-image-tests)