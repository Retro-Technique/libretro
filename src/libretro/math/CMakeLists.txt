add_library(${PROJECT_NAME}-math
	INTERFACE
)

target_include_directories(${PROJECT_NAME}-math
	INTERFACE
		"$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
		"$<INSTALL_INTERFACE:include>"
)

install(
    TARGETS ${PROJECT_NAME}-math
    EXPORT ${PROJECT_NAME}Targets
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    DIRECTORY ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}/math/
    DESTINATION include/${PROJECT_NAME}/math
)

install(
    FILES ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}/math.h
    DESTINATION include/${PROJECT_NAME}
)