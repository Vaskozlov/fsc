#include "compiler.hpp"
#include "io.hpp"
#include <boost/program_options.hpp>
#include <boost/program_options/option.hpp>
#include <boost/program_options/parsers.hpp>
#include <ccl/lex/analyzer_generator/analyzer_generator.hpp>
#include <ccl/raii.hpp>
#include <iostream>

namespace po = boost::program_options;

bool PrintCode = false;
bool PrintTree = false;

unsigned OptimizationLevel = 0;
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

    auto code = fsc::compile(Source, stream, fsc::ast::OptimizationLevel::NONE, PrintTree);

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
        system_command += "-O2";
    }

    return std::system(system_command.c_str());
}

auto parseOptionsAndCompile(int argc, char *argv[]) -> void
{
    po::options_description desc("Allowed options");

    desc.add_options()("help,h", "Produce help message")(
        "source,s", po::value(&Source), "Fsc file, which will be compiled")(
        "output,o", po::value(&Output), "Name of generated file")(
        "optimization,O", po::value(&OptimizationLevel),
        "Optimization level from 0 to 2 (for optimized builds -O1 is recommended)")(
        "cxx", po::value(&CppCompiler), "C++ compiler")(
        "cxx-flags", po::value(&CppFlags), "C++ additional flags (by default is clang++)")(
        "run", "Run compiled program")("print-code", "Prints translated version of fsc program")(
        "print-tree", "Prints fsc program's tree");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
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

        fmt::print("Running program...\n\n");
        std::system(Output.c_str());
    }
}

auto main(int argc, char *argv[]) -> int
{
    try {
        parseOptionsAndCompile(argc, argv);
        return 0;
    } catch (const std::exception &exception) {
        fmt::print(std::cerr, "{}\n", exception.what());
    } catch (...) {
        fmt::print(std::cerr, "Unknown error\n");
    }

    return 1;
}
