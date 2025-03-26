cmake_minimum_required(VERSION 3.20)

zephyr_library()
zephyr_library_sources(${TINYCOMMON_DIR}/src/empty_file.c)

add_library(tiny_interface INTERFACE)
tiny_library_named(tiny)
tiny_include_directories(${PROJECT_DIR}/include)
add_subdirectory(${PROJECT_DIR}/src)
tiny_library_link_libraries(zephyr_interface)

zephyr_link_libraries(tiny)
