cmake_minimum_required(VERSION 3.20)

add_library(tinyplatform INTERFACE)
add_library(tinyplatform-platform INTERFACE)
target_link_libraries(tinyplatform INTERFACE tinyplatform-platform)
target_include_directories(tinyplatform INTERFACE ${TINYPLATFORM_DIR}/include)
add_subdirectory(${TINYPLATFORM_DIR}/src)
