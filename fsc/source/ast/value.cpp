#include "ast/value.hpp"
#include <fmt/format.h>

namespace fsc::ast {
    using namespace std::string_view_literals;

    auto Value::codeGen(gen::CodeGenerator &output) const -> void
    {
        value->codeGen(output);
    }

    auto Value::print(const std::string &prefix, const bool is_left) const -> void
    {
        fmt::print("{}{}\n", getPrintingPrefix(prefix, is_left), value->toString());
    }
}// namespace fsc::ast
