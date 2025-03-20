cmake_minimum_required(VERSION 3.20)

# CHECK needed for esp-idf build system to avoid errors
if(NOT CMAKE_BUILD_EARLY_EXPANSION)
  add_library(tinyplatform INTERFACE)
  add_library(tinyplatform-platform INTERFACE)
  target_link_libraries(tinyplatform INTERFACE tinyplatform-platform)
  target_include_directories(tinyplatform INTERFACE ${TINYPLATFORM_DIR}/include)
  add_subdirectory(${TINYPLATFORM_DIR}/src)
endif()

idf_component_register()
target_link_libraries(${COMPONENT_LIB} INTERFACE tinyplatform)
