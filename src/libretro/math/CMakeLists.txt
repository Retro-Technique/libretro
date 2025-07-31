add_library(${PROJECT_NAME}-math
	INTERFACE
)

target_include_directories(${PROJECT_NAME}-math
	INTERFACE
		"$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
		"$<INSTALL_INTERFACE:include>"
)