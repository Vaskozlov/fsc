cmake_minimum_required(VERSION 3.23)
project(fsc VERSION 0.0.1.0 LANGUAGES C CXX)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(ExternalProject)
ExternalProject_Add(ccl-project
        GIT_REPOSITORY    https://github.com/Vaskozlov/ccl-project
        GIT_TAG           experimental_brench
        CMAKE_ARGS -DPRECOMPILED_HEADERS=OFF -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
        )

find_package(ccl QUIET)

if (NOT ccl_FOUND)
    message(AUTHOR_WARNING "Build all external projects then reload cmake.")
    return()
endif()

add_compile_definitions(CCL_DEBUG=1)

include(project-options)
include(compile-options)
include(libraries)
include(fsc/CMakeLists.txt)
