#include "debug/debug.hpp"
#include "compiler.hpp"
#include "function/functions_holder.hpp"
#include "io.hpp"
#include <ccl/future.hpp>
#include <ccl/raii.hpp>
#include <fstream>

namespace fsc
{
    static auto compileCppProgram(std::string_view cpp_program) -> std::string
    {
        static constinit std::atomic<size_t> file_uuid{0};

        const auto test_uuid = file_uuid++;
        const auto cpp_filename = fmt::format("test-{}.cpp", test_uuid);
        const auto compiled_filename = fmt::format("./test-{}", test_uuid);
        const auto output_filename = fmt::format("test-out-{}.txt", test_uuid);
        const auto file_cleaner = ccl::Raii{
            []() {
            },
            [cpp_filename, compiled_filename, output_filename]() {
                deleteFile(cpp_filename);
                deleteFile(compiled_filename);
                deleteFile(output_filename);
            }};

        writeToFile(cpp_filename, fsc::FscProgramsHeader, cpp_program);

        const auto compiler_command = fmt::format(
            "UBSAN_OPTIONS=print_stacktrace=1 clang++ {} -fsanitize=address,undefined,leak -g "
            "-fno-omit-frame-pointer -O0 {} -o {}",
            CompilerFlags, cpp_filename, compiled_filename);

        const auto run_command = fmt::format("{} > {}", compiled_filename, output_filename);

        if (std::system(compiler_command.c_str()) != 0) {
            throw std::runtime_error{fmt::format("Unable to compile {} program", cpp_filename)};
        }

        std::system(run_command.c_str());

        return readFile(output_filename);
    }

    static auto compileFscProgram(std::string_view fsc_program) -> std::string
    {
        static constinit std::atomic<size_t> file_uuid{0};

        const auto test_uuid = file_uuid++;
        const auto fsc_filename = fmt::format("test-{}.fsc", test_uuid);
        const auto file_cleaner = ccl::Raii{
            []() {
            },
            [fsc_filename]() {
                deleteFile(fsc_filename);
            }};

        writeToFile(fsc_filename, fsc_program);

        std::ifstream stream(fsc_filename);

        if (!stream.is_open()) {
            fmt::print("{} is not a valid file\n", fsc_filename);
        }

        return compileCppProgram(fsc::compile(fsc_filename, stream, ast::OptimizationLevel::NONE));
    }

    auto compareProgramsOutput(std::string_view fsc_program, std::string_view cpp_program) -> bool
    {
        func::ReinitializeOnCompilation = true;
        auto function_holder_save = func::Functions;

        auto fsc_result = ccl::async([fsc_program]() {
            return compileFscProgram(fsc_program);
        });

        auto cpp_result = ccl::async([cpp_program]() {
            return compileCppProgram(cpp_program);
        });

        auto result = fsc_result.get() == cpp_result.get();

        func::Functions = function_holder_save;

        return result;
    }
}// namespace fsc