find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(Microsoft.GSL CONFIG REQUIRED)

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
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(${PROJECT_NAME}-graphics 
	PRIVATE 
		glfw
		glad::glad
		glm::glm-header-only
		Microsoft.GSL::GSL
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
)

install(
    TARGETS ${PROJECT_NAME}-graphics
    EXPORT ${PROJECT_NAME}Targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} 
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} 
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    DIRECTORY ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}/graphics/
    DESTINATION include/${PROJECT_NAME}/graphics
)

install(
    FILES ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}/graphics.h
    DESTINATION include/${PROJECT_NAME}
)