#include "ast/variable.hpp"
#include <fmt/format.h>

namespace fsc::ast {
    auto Variable::print(const std::string &prefix, const bool is_left) const -> void
    {
        fmt::print("{}{}\n", getPrintingPrefix(prefix, is_left), name);
    }
}// namespace fsc::ast
