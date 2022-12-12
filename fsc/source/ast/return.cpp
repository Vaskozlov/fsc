#include "ast/return.hpp"
#include <fmt/format.h>

namespace fsc::ast
{
    using namespace std::string_view_literals;

    Return::Return(NodePtr value_to_return)
      : value{std::move(value_to_return)}
    {
        CCL_ASSERT(this->getNodeType() == NodeType::RETURN);
    }

    auto Return::codeGen(gen::CodeGenerator &output) const -> void
    {
        output.write("return "sv);
        value->codeGen(output);
    }

    auto Return::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print("{}return \n", getPrintingPrefix(prefix, is_left));
        value->print(expandPrefix(prefix, is_left), false);
    }
}// namespace fsc::ast
