set(CMAKE_CXX_STANDARD 23)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(FSC_DEBUG=1)
endif ()

if (MSVC)
    include(msvc)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    include(unix)
    include(clang)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    include(unix)
endif ()
