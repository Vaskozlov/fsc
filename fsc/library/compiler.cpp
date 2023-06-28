#include "compiler.hpp"
#include "FscLexer.h"
#include "FscParser.h"
#include "type/builtin_types.hpp"
#include "visitor.hpp"
#include <ccl/future.hpp>
#include "io.hpp"

using namespace ccl;

namespace fsc
{
    auto compile(
        const std::filesystem::path &filename, ast::OptimizationLevel optimization_level,
        bool print_tree) -> std::string
    {
        auto builtin_initialization = std::jthread(builtin::initializeCompilerBuiltin);

        auto input = antlr4::ANTLRInputStream{fsc::readFile(filename)};
        auto lexer = FscLexer{&input};
        auto token_stream = antlr4::CommonTokenStream{&lexer};

        auto parser = FscParser{&token_stream};
        auto *tree = parser.program();

        auto visitor = fsc::Visitor{filename.string(), input};
        GlobalVisitor = &visitor;

        builtin_initialization.join();
        visitor.visit(tree);

        visitor.analyze();
        visitor.optimize(optimization_level);

        if (print_tree) {
            visitor.print();
        }

        return visitor.codeGen();
    }
}// namespace fsc
