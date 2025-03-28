cmake_minimum_required(VERSION 3.20)

tiny_library_sources(
  ${CMAKE_CURRENT_SOURCE_DIR}/platform.c ${CMAKE_CURRENT_SOURCE_DIR}/misc.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/exit_code.c ${CMAKE_CURRENT_SOURCE_DIR}/logging.c)

tiny_library_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

if(CONFIG_TY_LOG_LEVEL)
  set(CONFIG_TY_LOG_LEVEL ${CONFIG_TY_LOG_LEVEL})
else()
  set(CONFIG_TY_LOG_LEVEL 1)
endif()
tiny_library_compile_definitions(
  -DTY_CONFIG_LOG_LEVEL=${CONFIG_TY_LOG_LEVEL}
  -DTY_PLATFORM_CONFIG_FILE="tiny-posix-config.h")
