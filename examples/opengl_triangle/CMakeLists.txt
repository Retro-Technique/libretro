find_package(Boost REQUIRED COMPONENTS log)

add_executable(${PROJECT_NAME}-example-opengl_triangle
    "main.cpp"    
    "pch.cpp"
    "pch.h"
)

target_link_libraries(${PROJECT_NAME}-example-opengl_triangle
    PRIVATE
        ${PROJECT_NAME}-graphics
        Boost::log
)

target_precompile_headers(${PROJECT_NAME}-example-opengl_triangle
	PRIVATE
		"pch.h"
)