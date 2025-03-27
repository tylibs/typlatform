cmake_minimum_required(VERSION 3.20)
set(COMMON_INCLUDES ${PROJECT_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR})

set(COMMON_SOURCES instance/instance.cpp common/string.cpp common/error.cpp
                   logging/logging.cpp logging/log.cpp)

# test if the system is Linux
tiny_include_directories(${COMMON_INCLUDES})
tiny_sources(${COMMON_SOURCES})

if(ESP_PLATFORM)
  add_subdirectory(platform/esp)
elseif(ZEPHYR_BASE)
  add_subdirectory(platform/zephyr)
elseif(POSIX_PLATFORM)
  add_subdirectory(platform/posix)
else()
  message(FATAL_ERROR "Unsupported platform")

endif()
