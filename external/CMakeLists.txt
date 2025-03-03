include(FetchContent)

add_library(external INTERFACE)
add_library(external::external ALIAS external)

find_package(SDL3 QUIET CONFIG)
if (NOT SDL3_FOUND)
    FetchContent_Declare(
        SDL3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-3.2.6
    )
    FetchContent_MakeAvailable(SDL3)
endif ()

find_package(Vulkan REQUIRED)

target_link_libraries(external INTERFACE
    SDL3::SDL3
    Vulkan::Vulkan
)
