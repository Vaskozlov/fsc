#include "interpreter.hpp"
#include "FscLexer.h"
#include "FscParser.h"
#include "visitor.hpp"

namespace fsc {
    auto interpret(std::ifstream &stream) -> void
    {
        auto input = antlr4::ANTLRInputStream{stream};
        auto lexer = FscLexer{&input};
        auto token_stream = antlr4::CommonTokenStream{&lexer};

        auto parser = FscParser{&token_stream};
        auto tree = parser.program();

        auto visitor = fsc::Visitor{};
        visitor.visit(tree);

        visitor.callMain();
    }
}// namespace fsc
