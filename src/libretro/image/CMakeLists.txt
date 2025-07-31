find_package(Stb REQUIRED)

set(INCROOT "${PROJECT_SOURCE_DIR}/include/libretro/image")
set(SRCROOT "${PROJECT_SOURCE_DIR}/src/libretro/image")

set(SRC
	"${INCROOT}/export.h"
	"${INCROOT}/color.h"
	"${INCROOT}/color.inl"
	"${INCROOT}/colors.h"
	"${INCROOT}/bitmap.h"
	"${SRCROOT}/bitmap.cpp"
	"${SRCROOT}/pch.cpp"
	"${SRCROOT}/pch.h"
)

add_library(${PROJECT_NAME}-image 
	SHARED 
		${SRC}
)

target_include_directories(${PROJECT_NAME}-image  
	PUBLIC 
		${PROJECT_SOURCE_DIR}/include
	PRIVATE 
		${Stb_INCLUDE_DIR}
)

target_compile_options(${PROJECT_NAME}-image
	PRIVATE 
		$<$<CXX_COMPILER_ID:MSVC>:${MSVC_WARNINGS}>
		$<$<CXX_COMPILER_ID:GNU>:${GCC_WARNINGS}>
		$<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:MSVC>>:${MSVC_DEBUG_OPTIMISATION}>
		$<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:GNU>>:${GCC_DEBUG_OPTIMISATION}>
		$<$<AND:$<CONFIG:Release>,$<CXX_COMPILER_ID:MSVC>>:${MSVC_RELEASE_OPTIMISATION}>
		$<$<AND:$<CONFIG:Release>,$<CXX_COMPILER_ID:GNU>>:${GCC_RELEASE_OPTIMISATION}>
)

target_precompile_headers(${PROJECT_NAME}-image
	PRIVATE
		"${SRCROOT}/pch.h"
)

target_compile_definitions(${PROJECT_NAME}-image
	PRIVATE
		LIBRETRO_IMAGE_EXPORTS
		-D_CRT_SECURE_NO_WARNINGS
)