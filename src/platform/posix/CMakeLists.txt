cmake_minimum_required(VERSION 3.20)

tiny_sources(
  ${CMAKE_CURRENT_SOURCE_DIR}/platform.c
  ${CMAKE_CURRENT_SOURCE_DIR}/exit_code.c ${CMAKE_CURRENT_SOURCE_DIR}/logging.c)

tiny_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

tiny_compile_definitions(
  -DTINYPLATFORM_CONFIG_LOG_LEVEL=${CONFIG_TINYPLATFORM_LOG_LEVEL}
  -DTINYPLATFORM_PLATFORM_CONFIG_FILE="tinyplatform-posix-config.h")
