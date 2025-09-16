cmake_minimum_required(VERSION 3.21)
cmake_policy(SET CMP0167 NEW)

include(CMakePackageConfigHelpers)

set(PROJECT_NAME libretro)
set(PROJECT_DESCRIPTION "Modern C++ minimalist utility library for cross-platform development")
set(PROJECT_VERSION "0.0.1")
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

project(${PROJECT_NAME} 
	LANGUAGES CXX
	DESCRIPTION ${PROJECT_DESCRIPTION}
	VERSION ${PROJECT_VERSION}
)

configure_package_config_file(
    ${CMAKE_CURRENT_LIST_DIR}/cmake/Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/libretroConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/libretro
)

install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/libretroConfig.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/libretro
    RENAME libretroConfig.cmake
)

install(
    EXPORT libretroTargets
    FILE libretroTargets.cmake
    NAMESPACE libretro::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/libretro
)

option(BUILD_TESTS "Build the test suite" ON)
option(BUILD_EXAMPLES "Build the example suite" ON)
option(BUILD_MATH "Build ${PROJECT_NAME}-math" ON)
option(BUILD_IMAGE "Build ${PROJECT_NAME}-image" ON)
option(BUILD_GRAPHICS "Build ${PROJECT_NAME}-graphics" ON)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

add_subdirectory(src/${PROJECT_NAME})