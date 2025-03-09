cmake_minimum_required(VERSION 3.24)
project(HelloVulkanApplication VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

add_subdirectory("${CMAKE_SOURCE_DIR}/external")

add_executable(${PROJECT_NAME} "${CMAKE_CURRENT_LIST_DIR}/src/main.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/HelloVulkanApplication.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/HelloVulkanApplication.hpp"
)

target_link_libraries(${PROJECT_NAME} PRIVATE
	external::external
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