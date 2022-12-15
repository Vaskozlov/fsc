#include "function/argument.hpp"
#include "ast/variable.hpp"

using namespace fsc::ast;

namespace fsc
{
    Argument::Argument(std::string arg_name, ccl::Id type_id, ArgumentCategory argument_category)
      : name{std::move(arg_name)}
      , type{type_id}
      , category{argument_category}
    {}

    Argument::Argument(const ast::Node *node)
      : type{node->getValueType()}
    {}

    auto Argument::toVariable() const -> ast::Variable
    {
        auto optimized_category = category;

        if (category == ArgumentCategory::IN && FscType::isTriviallyCopyable(type)) {
            optimized_category = ArgumentCategory::COPY;
        }

        const auto variable_flags = VariableFlags{
            .constant = optimized_category == ArgumentCategory::IN,
            .reference = optimized_category == ArgumentCategory::IN ||
                         optimized_category == ArgumentCategory::INOUT};

        return {name, type, variable_flags};
    }
}// namespace fsc
