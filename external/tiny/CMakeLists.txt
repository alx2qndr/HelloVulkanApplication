add_library(tiny_obj_loader INTERFACE)
target_include_directories(tiny_obj_loader INTERFACE "${CMAKE_CURRENT_LIST_DIR}/include")
add_library(tiny::obj_loader ALIAS tiny_obj_loader)