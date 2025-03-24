cmake_minimum_required(VERSION 3.20)

# test if the system is Linux
tiny_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

if(ESP_PLATFORM)
  add_subdirectory(esp)
elseif(ZEPHYR_BASE)
  add_subdirectory(zephyr)
elseif(POSIX_PLATFORM)
  add_subdirectory(posix)
else()
  message(FATAL_ERROR "Unsupported platform")

endif()
