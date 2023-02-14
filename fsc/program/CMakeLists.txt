file(
        GLOB_RECURSE
        FSC_PROGRAM_OBJECTS
        "fsc/program/*.cpp"
)

add_executable(
        fsc-compiler
        ${FSC_PROGRAM_OBJECTS}
)

target_link_libraries(
        fsc-compiler
        Boost::program_options
)

target_link_libraries(
        fsc-compiler
        fmt::fmt
)

target_link_libraries(
        fsc-compiler
        fsc
)

