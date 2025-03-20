cmake_minimum_required(VERSION 3.20)

target_sources(
  tinyplatform-platform INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/platform.c
                                  ${CMAKE_CURRENT_SOURCE_DIR}/logging.c)

target_include_directories(tinyplatform-platform
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_definitions(
  tinyplatform-platform
  INTERFACE -DTINYPLATFORM_CONFIG_LOG_LEVEL=${CONFIG_TINYPLATFORM_LOG_LEVEL}
            -DTINYPLATFORM_PLATFORM_CONFIG_FILE="tinyplatform-esp-config.h")
