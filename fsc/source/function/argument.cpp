#include "function/argument.hpp"
#include "ast/value/variable.hpp"

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

        const auto should_be_constant = optimized_category == ArgumentCategory::IN;
        const auto should_be_reference = optimized_category != ArgumentCategory::COPY;
        const auto variable_flags =
            VariableFlags{.constant = should_be_constant, .reference = should_be_reference};

        return {name, type, variable_flags};
    }

    auto operator<<(ccl::codegen::BasicCodeGenerator &generator, const Argument &argument)
        -> ccl::codegen::BasicCodeGenerator &
    {
        const auto category = argument.getCategory();
        const auto &name = argument.getName();
        const auto &type_name = FscType::getTypeName(argument.getType());
        const auto type_id = argument.getType();
        const auto is_trivially_copiable = FscType::isTriviallyCopyable(type_id);

        if (category == ArgumentCategory::IN || category == ArgumentCategory::INOUT) {
            generator << "const ";
        }

        generator << type_name << ' ';

        if ((!is_trivially_copiable && category == ArgumentCategory::IN) ||
            category == ArgumentCategory::OUT || category == ArgumentCategory::INOUT) {
            generator << "&";
        }

        generator << name;
        return generator;
    }
}// namespace fsc
