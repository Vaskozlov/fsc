#include "function/argument.hpp"
#include "ast/variable.hpp"

using namespace fsc::ast;

namespace fsc
{
    auto Argument::toVariable() const -> ast::Variable
    {
        auto optimized_category = category;

        if (category == ArgumentCategory::IN && FscType::isTriviallyCopyable(type)) {
            optimized_category = ArgumentCategory::COPY;
        }

        return {
            name, type,
            VariableFlags{
                .constant = optimized_category == ArgumentCategory::IN,
                .reference = optimized_category == ArgumentCategory::IN ||
                             optimized_category == ArgumentCategory::INOUT}};
    }
}// namespace fsc
