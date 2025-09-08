cmake_minimum_required(VERSION 3.21)

set(PROJECT_NAME libretro)
set(PROJECT_DESCRIPTION "Modern C++ minimalist utility library for cross-platform development")
set(PROJECT_VERSION "1.0.0")
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

option(${PROJECT_NAME}_BUILD_TESTS "Build the test suite" ON)

if(${PROJECT_NAME}_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

add_subdirectory(examples)

add_subdirectory(src/libretro)