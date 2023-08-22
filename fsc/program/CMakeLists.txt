file(
        GLOB_RECURSE
        FSC_PROGRAM_OBJECTS
        "fsc/program/*.cpp"
)

add_executable(
        fsc-compiler
        ${FSC_PROGRAM_OBJECTS}
)

ccl_set_project_warnings(
        fsc-compiler
        ${CCL_STRICT_COMPILATION}
        ""
        ""
        ""
        ""
        ${CCL_HARDENING}
        ${CCL_LIBCPP}
)

target_link_libraries(
        fsc-compiler
        fsc
        fmt::fmt
        cxxopts::cxxopts
)

