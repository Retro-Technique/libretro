find_package(Boost REQUIRED COMPONENTS property_tree)
find_package(Boost REQUIRED COMPONENTS beast)
find_package(Boost REQUIRED COMPONENTS iostreams)
find_package(boost_algorithm CONFIG REQUIRED)

set(INCROOT "${PROJECT_SOURCE_DIR}/include/libretro/tiled")
set(SRCROOT "${PROJECT_SOURCE_DIR}/src/libretro/tiled")

set(SRC
	"${INCROOT}/export.h"
	"${INCROOT}/file.h"
	"${INCROOT}/tsx.h"
	"${INCROOT}/tmx.h"
	"${SRCROOT}/file.cpp"
	"${SRCROOT}/parser.h"
	"${SRCROOT}/tmx_parser.h"
	"${SRCROOT}/tsx_parser.h"
	"${SRCROOT}/pch.cpp"
	"${SRCROOT}/pch.h"
)

add_library(${PROJECT_NAME}-tiled 
	SHARED 
		${SRC}
)

target_include_directories(${PROJECT_NAME}-tiled  
	PUBLIC 
		${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}-tiled
	PRIVATE 
		Boost::property_tree
		Boost::beast
		Boost::iostreams
		Boost::algorithm
)

target_compile_options(${PROJECT_NAME}-tiled
	PRIVATE 
		$<$<CXX_COMPILER_ID:MSVC>:${MSVC_WARNINGS}>
		$<$<CXX_COMPILER_ID:GNU>:${GCC_WARNINGS}>
		$<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:MSVC>>:${MSVC_DEBUG_OPTIMISATION}>
		$<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:GNU>>:${GCC_DEBUG_OPTIMISATION}>
		$<$<AND:$<CONFIG:Release>,$<CXX_COMPILER_ID:MSVC>>:${MSVC_RELEASE_OPTIMISATION}>
		$<$<AND:$<CONFIG:Release>,$<CXX_COMPILER_ID:GNU>>:${GCC_RELEASE_OPTIMISATION}>
)

target_precompile_headers(${PROJECT_NAME}-tiled
	PRIVATE
		"${SRCROOT}/pch.h"
)

target_compile_definitions(${PROJECT_NAME}-tiled
	PRIVATE
		LIBRETRO_TILED_EXPORTS
)