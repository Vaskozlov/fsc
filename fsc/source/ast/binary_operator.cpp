#include "ast/binary_operator.hpp"
#include <ranges>

namespace fsc::ast {
    auto BinaryOperation::getValueType() const noexcept -> TypeId
    {
        const auto left_argument_type = Argument(lhs.get());
        const auto right_argument_type = Argument(rhs.get());
        auto function_name = operatorToFunctionName.at(operationType);

        return func::Functions
                .get(std::string{function_name}, {left_argument_type, right_argument_type},
                     CallRequirements::IMPLICIT)
                ->getReturnType();
    }

    auto BinaryOperation::codeGen(gen::CodeGenerator &output) const -> void
    {
        lhs->codeGen(output);
        output.write(fmt::format(" {} ", operationType));
        rhs->codeGen(output);
    }

    auto BinaryOperation::print(const std::string &prefix, const bool is_left) const -> void
    {
        fmt::print("{}{}\n", getPrintingPrefix(prefix, is_left), operationType);

        lhs->print(expandPrefix(prefix, is_left), true);
        rhs->print(expandPrefix(prefix, is_left), false);
    }
}// namespace fsc::ast
