cmake_minimum_required(VERSION 3.20)

# "tb_interface" is a source-less library that encapsulates all the global
# compiler options needed by all source files. All zephyr libraries, including
# the library named "tb" link with this library to obtain these flags.
# https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html#interface-libraries
add_library(tiny_interface INTERFACE)
tiny_library_named(tiny)
tiny_include_directories(${PROJECT_DIR}/include)
add_subdirectory(${PROJECT_DIR}/src)
