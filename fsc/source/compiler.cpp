#include "compiler.hpp"
#include "FscLexer.h"
#include "FscParser.h"
#include "visitor.hpp"
#include <filesystem>

using namespace std::literals;

auto CodeSupport = R"cpp(

#include <string>
#include <cstddef>
#include <cinttypes>
#include <fmt/format.h>

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using f32 = float;
using f64 = double;

using namespace std;

auto print(const std::string &fmt, auto&&... args) -> void
{
    fmt::print(fmt::runtime(fmt), std::forward<decltype(args)>(args)...);
}

auto format(const std::string &fmt, auto&&... args) -> string
{
    return fmt::format(fmt::runtime(fmt), std::forward<decltype(args)>(args)...);
}

)cpp"s;

auto ClangArguments = R"(-std=c++2b -DFMT_HEADER_ONLY=1)";

namespace fsc
{
    static auto writeToFile(const std::string &filename, std::string_view data) -> void
    {
        auto out = std::ofstream{filename};
        out.write(data.data(), ccl::as<long>(data.size()));
        out.close();
    }

    static auto compileUsingSystemCommand(
        std::string_view source_file, std::string_view output_binary, bool execute = false) -> void
    {
        system(
            fmt::format("clang++ {} {} -o {}", ClangArguments, source_file, output_binary).c_str());

        if (execute) {
            system(fmt::format("./{}", output_binary).c_str());
        }
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

        auto visitor = fsc::Visitor{};
        visitor.visit(tree);

        auto code = CodeSupport + visitor.codeGen();

        fmt::print("{}\n", code);

        writeToFile(".fsc-tmp.cpp", code);
        compileUsingSystemCommand(".fsc-tmp.cpp", "fsc-compiled", true);
        deleteFile(".fsc-tmp.cpp");
    }
}// namespace fsc
