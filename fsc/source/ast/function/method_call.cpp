#include "ast/function/method_call.hpp"
#include "ast/function/function_call.hpp"
#include "type/type.hpp"
#include <cmath>

namespace fsc::ast
{
    using namespace std::string_view_literals;

    MethodCall::MethodCall(
        NodePtr expression_for_call, ccl::SharedPtr<Function> function_to_call,
        const ccl::SmallVector<NodePtr> &function_arguments)
      : NodeWrapper{std::move(function_to_call), function_arguments}
      , expression{std::move(expression_for_call)}
    {}

    auto MethodCall::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print(
            "{}Method call {}\n", getPrintingPrefix(prefix, is_left),
            FscType::getTypeName(expression->getValueType()));
        defaultFunctionCallPrint(expandPrefix(prefix, false), false);
    }

    auto MethodCall::codeGen(gen::CodeGenerator &output) const -> void
    {
        switch (expression->getNodeType()) {
        case NodeType::VALUE:
        case NodeType::VARIABLE:
        case NodeType::MEMBER_VARIABLE:
        case NodeType::METHOD_CALL:
        case NodeType::FUNCTION_CALL:
        case NodeType::VARIABLE_DEFINITION:
            output << *expression << '.';
            break;

        default:
            output << '(' << *expression << ").";
            break;
        }

        defaultFunctionCallCodeGen(output);
    }
};// namespace fsc::ast
