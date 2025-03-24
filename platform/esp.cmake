cmake_minimum_required(VERSION 3.20)

# idf_component_register()

# CHECK needed for esp-idf build system to avoid errors

# if(NOT CMAKE_BUILD_EARLY_EXPANSION)
message(STATUS "Building tinyplatform for ESP-IDF *******************")
add_library(tinylibs_interface INTERFACE)
tiny_library_named(tinylibs)
tiny_include_directories(${TINYPLATFORM_DIR}/include)
add_subdirectory(${TINYPLATFORM_DIR}/src)
# target_link_libraries(${COMPONENT_LIB} INTERFACE tinylibs) endif()
