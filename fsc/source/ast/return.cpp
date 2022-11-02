#include "ast/return.hpp"
#include <fmt/format.h>

namespace fsc::ast {
    using namespace std::string_view_literals;

    auto Return::codeGen(gen::CodeGenerator &output) const -> void
    {
        output.add("return "sv);
        value->codeGen(output);
    }

    auto Return::print(const std::string &prefix, const bool is_left) const -> void
    {
        fmt::print("{}return \n", getPrintingPrefix(prefix, is_left));
        value->print(expandPrefix(prefix, is_left), false);
    }
}// namespace fsc::ast
