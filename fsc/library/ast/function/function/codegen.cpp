#include "ast/function/function.hpp"
#include "ast/function/magic_methods_table.hpp"
#include "stack/stack.hpp"
#include <ccl/join.hpp>

using namespace ccl;
using namespace fsc::ast::magic;
using namespace std::string_view_literals;

namespace fsc::ast
{
    auto Function::addVisibility(codegen::BasicCodeGenerator &output) const -> void
    {
        if (isMember() || magicType == MagicFunctionType::INIT || name == "main") {
            return;
        }

        switch (functionInfo.VISIBILITY) {
        case Visibility::EXPORT:
        case Visibility::PUBLIC:
            output << "extern ";
            break;

        default:
            output << "static ";
        }
    }

    auto Function::addNodiscardModifier(codegen::BasicCodeGenerator &output) const -> void
    {
        if (getReturnType() != Void && name != "main" && functionInfo.NODISCARD) {
            output << "[[nodiscard]] ";
        }
    }

    auto Function::addConstexprModifier(codegen::BasicCodeGenerator &output) const -> void
    {
        if (name != "main" && functionInfo.CONSTEXPR) {
            output << "constexpr ";
        }
    }

    auto Function::addStaticModifier(ccl::codegen::BasicCodeGenerator &output) const -> void
    {
        if (functionInfo.IS_METHOD && functionInfo.STATIC_METHOD) {
            output << "static ";
        }
    }

    auto Function::addConstModifier(ccl::codegen::BasicCodeGenerator &output) const -> void
    {
        if (functionInfo.IS_METHOD && functionInfo.CONSTANT_METHOD && !functionInfo.STATIC_METHOD) {
            output << "const ";
        }
    }

    auto Function::addNoexceptModifier(ccl::codegen::BasicCodeGenerator &output) const -> void
    {
        if (functionInfo.NOEXCEPT) {
            output << "noexcept ";
        }
    }

    auto Function::argumentsToString(bool include_default) const -> std::string
    {
        return ccl::join(
            arguments,
            [this, include_default](const Argument &argument) {
                return argumentToString(argument, include_default);
            },
            ", ");
    }

    auto Function::generateTemplateParameters(codegen::BasicCodeGenerator &output) const -> void
    {
        if (!templates.empty()) {
            fmt::format_to(
                output.getBackInserter(), "template<typename {}>\n",
                fmt::join(templates, ", typename "));
        }
    }

    auto Function::generateFunctionDefinition(
        ccl::codegen::BasicCodeGenerator &output, Id stream_id,
        bool include_default_arguments) const -> void
    {
        output << ccl::codegen::setStream(stream_id);

        if (isMember()) {
            genVisibility(functionInfo.VISIBILITY, output);
        }

        generateTemplateParameters(output);

        if (magicType == MagicFunctionType::INIT || magicType == MagicFunctionType::DEL) {
            addConstexprModifier(output);
            output << name;
        } else {
            addNodiscardModifier(output);
            addConstexprModifier(output);
            addStaticModifier(output);
            addVisibility(output);

            if (magicType != MagicFunctionType::NONE) {
                output << getReturnType().getName() << " operator" << MagicToRepr.at(magicType);
            } else {
                output << getReturnType().getName() << ' ' << name;
            }
        }

        output << '(' << argumentsToString(include_default_arguments) << ") ";

        addConstModifier(output);
        addNoexceptModifier(output);
    }

    auto Function::codeGen(codegen::BasicCodeGenerator &output) -> void
    {
        if (classType == Void) {
            generateFunctionDefinition(output, classType.getId() * 2, true);

            output << ';' << codegen::endl << codegen::endl;
        }

        auto stream_id =
            classType == Void ? std::numeric_limits<u32>::max() : classType.getId() * 2 + 1;

        generateFunctionDefinition(output, stream_id, false);

        if (functionBody != nullptr) {
            output << *functionBody.get();
        } else {
            output << ';';
        }
    }

    auto Function::optimize(OptimizationLevel level) -> void
    {
        if (!templates.empty()) {
            return;// with current model it is impossible to optimize templated functions
        }

        auto uuid = functionUuid;

        if (ProgramStack.hasFunctionInCallTree(uuid)) {
            return;
        }

        const auto function_scope = ProgramStack.acquireAnalysisScope(uuid, shared_from_this());

        if (functionBody != nullptr) {
            functionBody->optimize(level);
        }
    }
}// namespace fsc::ast
