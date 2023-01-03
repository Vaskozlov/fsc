#include "ast/container/program.hpp"
#include <ast/basic_node.hpp>
#include <ranges>

namespace fsc::ast
{
    auto Program::codeGen(ccl::codegen::BasicCodeGenerator &output) const -> void
    {
        using namespace ccl::codegen;

        for (const auto &node : *this) {
            output << *node;

            if (node->semicolonRequired() == SemicolonNeed::NEED) {
                output << ';';
            }

            output << endl << endl;
        }
    }

    auto Program::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print("{}Program\n", getPrintingPrefix(prefix, is_left));
        defaultBodyPrint(expandPrefix(prefix, is_left), false);
    }
}// namespace fsc::ast
