set(CMAKE_CXX_STANDARD 23)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(FSC_DEBUG=1)
endif ()

include(ccl/cmake/CompilerOptions.cmake)