#include "compiler.hpp"
#include "FscLexer.h"
#include "FscParser.h"
#include "type/builtin_types.hpp"
#include "visitor.hpp"

using namespace ccl;

namespace fsc
{
    auto compile(std::string_view filename, std::ifstream &stream) -> std::string
    {
        initializeCompilerBuiltin();

        auto input = antlr4::ANTLRInputStream{stream};
        auto lexer = FscLexer{&input};
        auto token_stream = antlr4::CommonTokenStream{&lexer};

        auto parser = FscParser{&token_stream};
        auto *tree = parser.program();

        auto visitor = fsc::Visitor{filename, input};

        visitor.visit(tree);
        visitor.analyze();

        return visitor.codeGen();
    }
}// namespace fsc
