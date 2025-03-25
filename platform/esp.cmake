cmake_minimum_required(VERSION 3.20)

idf_component_register()

add_library(tiny_interface INTERFACE)
tiny_library_named(tiny)
tiny_include_directories(${TINYPLATFORM_DIR}/include)
add_subdirectory(${TINYPLATFORM_DIR}/src)
target_link_libraries(${COMPONENT_LIB} INTERFACE tiny)
