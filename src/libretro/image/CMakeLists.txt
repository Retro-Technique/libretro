find_package(Boost REQUIRED COMPONENTS gil)
find_package(PNG REQUIRED)
find_package(libjpeg-turbo CONFIG REQUIRED)

set(INCROOT "${PROJECT_SOURCE_DIR}/include/libretro/image")
set(SRCROOT "${PROJECT_SOURCE_DIR}/src/libretro/image")

set(SRC
	"${SRCROOT}/pch.cpp"
	"${SRCROOT}/pch.h"
	"${SRCROOT}/bitmap.cpp"
	"${SRCROOT}/bitmap.impl.h"
	"${SRCROOT}/bitmap.impl.cpp"
)

add_library(${PROJECT_NAME}-image 
	SHARED 
		${SRC}
)

target_include_directories(${PROJECT_NAME}-image  
	PUBLIC 
		${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}-image 
	PRIVATE 
		Boost::gil
		PNG::PNG
		$<IF:$<TARGET_EXISTS:libjpeg-turbo::jpeg>,libjpeg-turbo::jpeg,libjpeg-turbo::jpeg-static>
		${PROJECT_NAME}-math
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
)