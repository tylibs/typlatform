cmake_minimum_required(VERSION 3.20)

# "tb_interface" is a source-less library that encapsulates all the global
# compiler options needed by all source files. All zephyr libraries, including
# the library named "tb" link with this library to obtain these flags.
# https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html#interface-libraries
add_library(tinylibs_interface INTERFACE)
tiny_library_named(tinylibs)
tiny_include_directories(${TINYPLATFORM_DIR}/include)
add_subdirectory(${TINYPLATFORM_DIR}/src)
tiny_library_link_libraries(zephyr_interface)

# target_compile_options( tinylibs_interface INTERFACE
# $<TARGET_PROPERTY:zephyr_interface,INTERFACE_COMPILE_OPTIONS>
# $<TARGET_PROPERTY:compiler,no_builtin> -imacros ${AUTOCONF_H})

# Zephyr compiler options target_include_directories( tinylibs_interface
# INTERFACE $<TARGET_PROPERTY:zephyr_interface,INTERFACE_INCLUDE_DIRECTORIES>)

# target_include_directories( tinylibs_interface SYSTEM INTERFACE
# $<TARGET_PROPERTY:zephyr_interface,INTERFACE_SYSTEM_INCLUDE_DIRECTORIES>)

# target_compile_definitions( tinylibs_interface INTERFACE
# $<TARGET_PROPERTY:zephyr_interface,INTERFACE_COMPILE_DEFINITIONS>)
