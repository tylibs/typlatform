cmake_minimum_required(VERSION 3.20)

ty_library_sources(
  ${CMAKE_CURRENT_SOURCE_DIR}/platform.c ${CMAKE_CURRENT_SOURCE_DIR}/misc.c
  ${CMAKE_CURRENT_SOURCE_DIR}/logging.c)

ty_library_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

ty_library_compile_definitions(
  -DTY_CONFIG_LOG_LEVEL=${CONFIG_TY_LOG_LEVEL}
  -DTY_PLATFORM_CONFIG_FILE="ty-zephyr-config.h")
