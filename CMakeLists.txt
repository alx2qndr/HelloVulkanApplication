cmake_minimum_required(VERSION 3.24.0)
project(HelloVulkanApplication VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(external)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/HelloVulkanApplication.cpp
    src/Window.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC include
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE external::external
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

if(WIN32)
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different
        $<TARGET_FILE:SDL3::SDL3-shared>
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
        VERBATIM
    )
endif()