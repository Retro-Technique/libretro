find_package(Boost REQUIRED COMPONENTS log)

add_executable(${PROJECT_NAME}-example-sprite_batching
    "main.cpp"    
    "pch.cpp"
    "pch.h"
)

target_link_libraries(${PROJECT_NAME}-example-sprite_batching
    PRIVATE
        ${PROJECT_NAME}-graphics
        ${PROJECT_NAME}-image
        Boost::log
)

target_precompile_headers(${PROJECT_NAME}-example-sprite_batching
	PRIVATE
		"pch.h"
)

target_compile_definitions(${PROJECT_NAME}-example-sprite_batching
	PRIVATE
		RESOURCE_DIRECTORY="${CMAKE_CURRENT_SOURCE_DIR}/res"
)