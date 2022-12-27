#include "compiler.hpp"
#include "ccl/string_view.hpp"
#include "FscLexer.h"
#include "FscParser.h"
#include "visitor.hpp"
#include <filesystem>

namespace fsc
{
    template<typename... Ts>
    static auto writeToFile(const std::string &filename, Ts &&...args) -> void
    {
        auto out = std::ofstream{filename};
        (out.write(std::data(args), ccl::as<long>(std::size(args))), ...);
        out.close();
    }

    static auto compileAndExecuteUsingSystemCommand(
        std::string_view source_file, std::string_view output_binary) -> void
    {
        auto compiler_command =
            fmt::format("clang++ {} {} -o {}", ClangCompilerFlags, source_file, output_binary);

        system(compiler_command.c_str());

        fmt::print("Running program...\n");
        system(fmt::format("./{}", output_binary).c_str());
    }

    static auto deleteFile(std::string_view filename) -> void
    {
        std::filesystem::remove(filename);
    }

    auto compile(std::ifstream &stream) -> void
    {
        auto input = antlr4::ANTLRInputStream{stream};
        auto lexer = FscLexer{&input};
        auto token_stream = antlr4::CommonTokenStream{&lexer};

        auto parser = FscParser{&token_stream};
        auto tree = parser.program();

        auto visitor = fsc::Visitor{input, parser};
        visitor.visit(tree);

        auto code = visitor.codeGen();

        fmt::print("{} {}\n", FscProgramsHeader, code);

        writeToFile(".fsc-tmp.cpp", FscProgramsHeader, code);
        compileAndExecuteUsingSystemCommand(".fsc-tmp.cpp", "fsc-compiled");
        deleteFile(".fsc-tmp.cpp");
    }
}// namespace fsc
