enable_testing()

file(
        GLOB_RECURSE
        FSC_CATCH_OBJECTS
        "catch/*.cpp"
)

add_executable(
        fsc-catch
        ${FSC_CATCH_OBJECTS}
)

ccl_set_project_warnings(
        fsc-catch
        ${CCL_STRICT_COMPILATION}
        ""
        ""
        ""
        ""
        ${CCL_HARDENING}
        ${CCL_LIBCPP}
)

set_source_files_properties(
        catch/runner.cpp PRIVATE
        PROPERTIES SKIP_PRECOMPILE_HEADERS ON
)

target_link_libraries(
        fsc-catch
        ccl
        fmt::fmt
        fsc
        Catch2::Catch2
        Catch2::Catch2WithMain
)

if (${PRECOMPILED_HEADER})
    target_precompile_headers(
            fsc-catch
            PUBLIC
            "pch.hpp"
    )
endif ()

add_test(fsc-catch-test fsc-catch)
