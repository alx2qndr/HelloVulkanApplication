add_library(external INTERFACE)
add_library(external::external ALIAS external)

FetchContent_Declare(
	SDL3
	GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
	GIT_TAG release-3.2.8
)
FetchContent_MakeAvailable(SDL3)

FetchContent_Declare(
	glm
	GIT_REPOSITORY https://github.com/g-truc/glm.git
	GIT_TAG 1.0.1
)
FetchContent_MakeAvailable(glm)

find_package(Vulkan REQUIRED)

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/stb" EXCLUDE_FROM_ALL)
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/tiny" EXCLUDE_FROM_ALL)

target_link_libraries(external INTERFACE 
	SDL3::SDL3
	Vulkan::Vulkan 
	glm::glm
	stb::image
	tiny::obj_loader
)
