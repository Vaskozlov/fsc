file(
        GLOB_RECURSE
        FSC_OBJECTS
        "fsc/source/*.cpp"
        "fsc/antlr-generated/*.cpp"
)

add_executable(fsc ${FSC_OBJECTS})

add_dependencies(fsc antlr4_static)
add_dependencies(fsc ccl-project)

target_link_libraries(fsc ccl::ccl)
target_link_libraries(fsc fmt::fmt)
target_link_libraries(fsc antlr4_static)

include_directories(SYSTEM fsc/include)
include_directories(SYSTEM fsc/antlr-generated)

target_link_libraries(fsc ${llvm_libs})
target_link_libraries(fsc ${CLANG_LIBS})

if (${PRECOMPILED_HEADERS})
    target_precompile_headers(
            fsc
            PUBLIC
            "pch.hpp"
    )
endif ()
