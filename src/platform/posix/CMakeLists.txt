cmake_minimum_required(VERSION 3.20)

tiny_sources(
  ${CMAKE_CURRENT_SOURCE_DIR}/platform.c
  ${CMAKE_CURRENT_SOURCE_DIR}/exit_code.c ${CMAKE_CURRENT_SOURCE_DIR}/logging.c)

tiny_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

tiny_compile_definitions(# -DTINY_CONFIG_LOG_LEVEL=${CONFIG_TINY_LOG_LEVEL}
                         -DTINY_PLATFORM_CONFIG_FILE="tiny-posix-config.h")
