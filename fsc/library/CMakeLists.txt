file(
        GLOB_RECURSE
        FSC_OBJECTS
        "fsc/library/*.cpp"
)

add_library(fsc STATIC ${FSC_OBJECTS})

add_dependencies(fsc antlr4_static)
add_dependencies(fsc ccl)

target_link_libraries(fsc ccl)
target_link_libraries(fsc fmt::fmt)
target_link_libraries(fsc antlr4_static)

target_link_libraries(fsc ${LLVM_LIBS})
target_link_libraries(fsc ${CLANG_LIBS})