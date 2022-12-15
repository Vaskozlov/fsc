#include "ast/program.hpp"
#include <ranges>

namespace fsc::ast
{
    auto Program::codeGen(gen::CodeGenerator &output) const -> void
    {
        for (const auto &node : *this) {
            node->codeGen(output);
            output.newLine();
            output.newLine();
        }
    }

    auto Program::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print("{}Class\n", getPrintingPrefix(prefix, is_left));
        defaultBodyPrint(expandPrefix(prefix, is_left), false);
    }
}// namespace fsc::ast
