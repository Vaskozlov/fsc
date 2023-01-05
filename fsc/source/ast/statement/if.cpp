#include "ast/statement/if.hpp"

namespace fsc::ast
{
    using namespace std::string_view_literals;

    constexpr static ccl::StaticFlatmap<IfType, std::string_view, 3> IfTypeToStr{
        {IfType::IF, "if "},
        {IfType::ELIF, "else if "},
        {IfType::ELSE, "else "},
    };

    If::If(IfType if_type, NodePtr if_condition, NodePtr if_body) noexcept
      : condition{std::move(if_condition)}
      , body{std::move(if_body)}
      , ifType{if_type}
    {}

    auto If::analyze() const -> void
    {
        condition->analyze();
        body->analyze();
    }

    auto If::codeGen(ccl::codegen::BasicCodeGenerator &output) const -> void
    {
        using namespace ccl::codegen;

        output << IfTypeToStr.at(getIfType());

        if (getIfType() != IfType::ELSE) {
            output << *condition;
        }

        output << endl << *body;
    }

    auto If::print(const std::string &prefix, bool is_left) const -> void
    {
        const auto expanded_prefix = expandPrefix(prefix, is_left);

        fmt::print("{}{}\n", getPrintingPrefix(prefix, is_left), IfTypeToStr.at(getIfType()));

        if (getIfType() != IfType::ELSE) {
            condition->print(expanded_prefix, true);
        }

        body->print(expanded_prefix, false);
    }
}// namespace fsc::ast
