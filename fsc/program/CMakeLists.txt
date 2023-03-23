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
        fsc
        fmt::fmt
        cxxopts::cxxopts
)

