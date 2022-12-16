#include "ast/if.hpp"

namespace fsc::ast
{
    using namespace std::string_view_literals;

    If::If(IfType if_type, NodePtr if_condition, NodePtr if_body) noexcept
      : condition{std::move(if_condition)}
      , body{std::move(if_body)}
      , ifType{if_type}
    {}

    auto If::codeGen(gen::CodeGenerator &output) const -> void
    {
        output << IfTypeToStr.at(getIfType()) << " ("sv << *condition << ')';
        output << gen::endl << *body;
    }

    auto If::print(const std::string &prefix, bool is_left) const -> void
    {
        const auto expanded_prefix = expandPrefix(prefix, is_left);

        fmt::print("{}{}\n", getPrintingPrefix(prefix, is_left), IfTypeToStr.at(getIfType()));

        condition->print(expanded_prefix, true);
        body->print(expanded_prefix, false);
    }
}// namespace fsc::ast
