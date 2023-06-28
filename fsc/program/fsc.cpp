#include "compiler.hpp"
#include "io.hpp"
#include <ccl/raii.hpp>
#include <chrono>
#include <cxxopts.hpp>
#include <iostream>

using namespace std::chrono_literals;

bool PrintCode = false;
bool PrintTree = false;

unsigned OptimizationLevel = 0;
long long FrontendTime = 0.0;
long long BackendTime = 0.0;

std::string Source;
std::string Output;
std::string CppCompiler = "clang++";
std::string CppFlags;

constexpr static std::string_view TmpFilename = ".fsc-tmp.cpp";

auto doCompilation() -> int
{
    if (!std::filesystem::exists(Source)) {
        fmt::print("Unable to find source file at a given location: {}\n", Source);
    }


    const auto optimization_level = OptimizationLevel == 0 ? fsc::ast::OptimizationLevel::NONE
                                                           : fsc::ast::OptimizationLevel::FAST;

    auto begin = std::chrono::high_resolution_clock::now();

    const auto code = fsc::compile(Source, optimization_level, PrintTree);

    FrontendTime = (std::chrono::high_resolution_clock::now() - begin) / 1us;

    if (PrintCode) {
        fmt::print("{}\n", code);
    }

    auto tmp_file = ccl::Raii{
        [&code]() {
            fsc::writeToFile(std::string{TmpFilename}, fsc::FscProgramsHeader, code);
        },
        []() {
            fsc::deleteFile(TmpFilename);
        }};

    auto system_command = fmt::format(
        "{} {} {} {} -o {} ", CppCompiler, fsc::CompilerFlags, CppFlags, TmpFilename, Output);

    if (OptimizationLevel < 2) {
        system_command = "UBSAN_OPTIONS=print_stacktrace=1 " + system_command;
    }

    if (OptimizationLevel == 0) {
        system_command += "-fsanitize=address,undefined -g -fno-omit-frame-pointer -O0";
    } else if (OptimizationLevel == 1) {
        system_command += "-fsanitize-minimal-runtime -g -fno-omit-frame-pointer -O2";
    } else {
        system_command += "-Ofast";
    }

    begin = std::chrono::high_resolution_clock::now();

    auto returned_code = std::system(system_command.c_str());

    BackendTime = (std::chrono::high_resolution_clock::now() - begin) / 1ms;

    return returned_code;
}


auto main(int argc, char *argv[]) -> int// NOLINT
{
    auto options = cxxopts::Options("fsc", "FSC compiler (https://github.com/Vaskozlov/fsc)");

    options.add_options()("h,help", "Produce help message")(
        "s,source", "File to compile", cxxopts::value(Source))(
        "o,output", "Output filename", cxxopts::value(Output)->default_value("a.out"))(
        "O,optimization", "Optimization leve",
        cxxopts::value(OptimizationLevel)->default_value("0"))(
        "cxx", "C++ compiler",
        cxxopts::value(CppCompiler))("cxx-flags", "C++ additional flags", cxxopts::value(CppFlags))(
        "run", "Run program after compilation")("print-code", "Print generated C++ code")(
        "print-tree", "Print program's tree");

    options.parse_positional({"s", "o"});

    auto result = options.parse(argc, argv);

    if (result.count("help") == 1) {
        std::cout << options.help() << "\n";
        return 1;
    }

    if (result.count("source") == 0) {
        fmt::print(
            "Source file has not bees specified.\n"
            "Type --help to see how to use fsc-compiler\n");
        return 1;
    }

    PrintCode = (result.count("print-code") != 0);
    PrintTree = (result.count("print-tree") != 0);

    if (doCompilation() == 0 && result.count("run") != 0) {
        if (Output[0] != '/') {
            Output = "./" + Output;
        }

        fmt::print(
            "Frontend time: {} us, backend time: {} ms, running program...\n\n", FrontendTime,
            BackendTime);
        std::system(Output.c_str());
    }

    return 0;
}
