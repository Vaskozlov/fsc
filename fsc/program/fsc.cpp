#include "compiler.hpp"
#include "io.hpp"
#include <boost/program_options.hpp>
#include <boost/program_options/option.hpp>
#include <boost/program_options/parsers.hpp>
#include <ccl/raii.hpp>
#include <chrono>
#include <iostream>

namespace po = boost::program_options;
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

    std::ifstream stream(Source);

    if (!stream.is_open()) {
        fmt::print("{} is not a valid file\n", Source);
        return 1;
    }

    const auto optimization_level = OptimizationLevel == 0 ? fsc::ast::OptimizationLevel::NONE
                                                           : fsc::ast::OptimizationLevel::FAST;

    auto begin = std::chrono::high_resolution_clock::now();

    const auto code = fsc::compile(Source, stream, optimization_level, PrintTree);

    FrontendTime = (std::chrono::high_resolution_clock::now() - begin) / 1ms;

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
        system_command += "-fsanitize=address,undefined,leak -g -fno-omit-frame-pointer -O0";
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

auto parseOptionsAndCompile(int argc, char *argv[]) -> void
{
    po::options_description desc("Allowed options");

    desc.add_options()("help,h", "Produce help message");

    desc.add_options()("source,s", po::value(&Source), "Fsc file, which will be compiled");

    desc.add_options()("output,o", po::value(&Output), "Name of generated file");

    desc.add_options()(
        "optimization,O", po::value(&OptimizationLevel),
        "Optimization level from 0 to 2 (for optimized builds -O1 is recommended)");

    desc.add_options()("cxx", po::value(&CppCompiler), "C++ compiler");

    desc.add_options()(
        "cxx-flags", po::value(&CppFlags), "C++ additional flags (by default is clang++)");

    desc.add_options()("run", "Run compiled program");

    desc.add_options()("print-code", "Prints translated version of fsc program")(
        "print-tree", "Prints fsc program's tree");

    po::positional_options_description po;
    po.add("source", -1);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).positional(po).run(), vm);
    po::notify(vm);

    if (vm.count("help") == 1) {
        std::cout << desc << "\n";
        return;
    }

    if (vm.count("source") == 0) {
        std::cout << "Source file has not bees specified." << std::endl;
        std::cout << "Type --help to see how to use fsc-compiler" << std::endl;
        return;
    }

    if (vm.count("output") == 0) {
        Output = "a.out";
    }

    PrintCode = (vm.count("print-code") != 0);
    PrintTree = (vm.count("print-tree") != 0);

    if (doCompilation() == 0 && vm.count("run") != 0) {
        if (Output[0] != '/') {
            Output = "./" + Output;
        }

        fmt::print(
            "Frontend time: {} ms, backend time: {} ms, running program...\n\n", FrontendTime,
            BackendTime);
        std::system(Output.c_str());
    }
}

auto main(int argc, char *argv[]) -> int
{
    parseOptionsAndCompile(argc, argv);

    return 0;
}
