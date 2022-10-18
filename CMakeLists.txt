cmake_minimum_required(VERSION 3.24)
project(fsc VERSION 0.0.1.0 LANGUAGES C CXX)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(project-options)
include(compile-options)
include(libraries)

include(fsc/CMakeLists.txt)
