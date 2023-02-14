cmake_minimum_required(VERSION 3.20)
project(fsc VERSION 0.0.1.0 LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

add_compile_definitions(CCL_DEBUG=1)
add_subdirectory(ccl EXCLUDE_FROM_ALL SYSTEM)

include(project-options)
include(compile-options)
include(libraries)
include(fsc/CMakeLists.txt)
include(fsc/program/CMakeLists.txt)
include(catch/CMakeLists.txt)
