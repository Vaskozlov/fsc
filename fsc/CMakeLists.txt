file(
        GLOB_RECURSE
        FSC_OBJECTS
        "fsc/source/*.cpp"
        "fsc/antlr-generated/*.cpp"
)

add_executable(fsc ${FSC_OBJECTS})

add_dependencies(fsc antlr4_static)
add_dependencies(fsc ccl)

target_link_libraries(fsc ccl)
target_link_libraries(fsc fmt::fmt)
target_link_libraries(fsc antlr4_static)

include_directories(SYSTEM fsc/include)
include_directories(SYSTEM fsc/antlr-generated)

target_link_libraries(fsc ${LLVM_LIBS})
target_link_libraries(fsc ${CLANG_LIBS})
