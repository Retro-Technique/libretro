add_executable(${PROJECT_NAME}-example-simple_window
    "main.cpp" 
)

target_link_libraries(${PROJECT_NAME}-example-simple_window
    PRIVATE
        ${PROJECT_NAME}-graphics
)