find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

set(INCROOT "${PROJECT_SOURCE_DIR}/include/libretro/graphics")
set(SRCROOT "${PROJECT_SOURCE_DIR}/src/libretro/graphics")

set(SRC
	"${SRCROOT}/pch.cpp"
	"${SRCROOT}/pch.h"
	"${SRCROOT}/gl.cpp"
)

add_library(${PROJECT_NAME}-graphics 
	SHARED 
		${SRC}
)

target_include_directories(${PROJECT_NAME}-graphics  
	PUBLIC 
		${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}-graphics 
	PRIVATE 
		glfw
		glad::glad
		glm::glm-header-only
		${PROJECT_NAME}-math
		${PROJECT_NAME}-image
)

target_compile_options(${PROJECT_NAME}-graphics
	PRIVATE 
		$<$<CXX_COMPILER_ID:MSVC>:${MSVC_WARNINGS}>
		$<$<CXX_COMPILER_ID:GNU>:${GCC_WARNINGS}>
		$<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:MSVC>>:${MSVC_DEBUG_OPTIMISATION}>
		$<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:GNU>>:${GCC_DEBUG_OPTIMISATION}>
		$<$<AND:$<CONFIG:Release>,$<CXX_COMPILER_ID:MSVC>>:${MSVC_RELEASE_OPTIMISATION}>
		$<$<AND:$<CONFIG:Release>,$<CXX_COMPILER_ID:GNU>>:${GCC_RELEASE_OPTIMISATION}>
)

target_precompile_headers(${PROJECT_NAME}-graphics
	PRIVATE
		"${SRCROOT}/pch.h"
)

target_compile_definitions(${PROJECT_NAME}-graphics
	PRIVATE
		LIBRETRO_GRAPHICS_EXPORTS
		-D_CRT_SECURE_NO_WARNINGS
)