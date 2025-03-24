cmake_minimum_required(VERSION 3.20)

add_library(tinylibs_interface INTERFACE)
tiny_library_named(tinylibs)
tiny_include_directories(${TINYPLATFORM_DIR}/include)
add_subdirectory(${TINYPLATFORM_DIR}/src)
tiny_library_link_libraries(zephyr_interface)
