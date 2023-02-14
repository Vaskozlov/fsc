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

target_compile_definitions(
        fsc-catch
        PRIVATE
        "BOOST_TEST_DYN_LINK"
)

set_source_files_properties(
        catch/runner.cpp PRIVATE
        PROPERTIES SKIP_PRECOMPILE_HEADERS ON
)

target_link_libraries(
        fsc-catch
        fmt::fmt
)

target_link_libraries(
        fsc-catch
        ccl
)

target_link_libraries(
        fsc-catch
        fsc
)

target_link_libraries(
        fsc-catch
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

if (${PRECOMPILED_HEADER})
    target_precompile_headers(
            fsc-catch
            PUBLIC
            "pch.hpp"
            <boost/test/unit_test.hpp>
    )
endif ()

add_test(fsc-catch-test fsc-catch)
