#include "ast/function/function.hpp"
#include "ast/function/magic_methods_table.hpp"
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
        if (getReturnType().getName() != "void" && name != "main" && functionInfo.NODISCARD) {
            output << "[[nodiscard]] ";
        }
    }

    auto Function::addConstexprModifier(codegen::BasicCodeGenerator &output) const -> void
    {
        if (name != "main" && functionInfo.CONSTEXPR) {
            output << "constexpr ";
        }
    }

    auto Function::addConstModifier(ccl::codegen::BasicCodeGenerator &output) const -> void
    {
        if (functionInfo.IS_METHOD && functionInfo.CONSTANT_METHOD) {
            output << "const ";
        }
    }

    auto Function::addNoexceptModifier(ccl::codegen::BasicCodeGenerator &output) const -> void
    {
        if (functionInfo.NOEXCEPT) {
            output << "noexcept ";
        }
    }

    auto Function::argumentsToString() -> std::string
    {
        return ccl::join(
            arguments,
            [this](Argument &argument) {
                return argumentToString(argument);
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

    auto Function::codeGen(codegen::BasicCodeGenerator &output) -> void
    {
        generateTemplateParameters(output);

        if (isMember()) {
            genVisibility(functionInfo.VISIBILITY, output);
        }

        if (magicType == MagicFunctionType::INIT || magicType == MagicFunctionType::DEL) {
            addConstexprModifier(output);
            output << name;
        } else {
            addNodiscardModifier(output);
            addConstexprModifier(output);
            addVisibility(output);

            if (magicType != MagicFunctionType::NONE) {
                output << getReturnType().getName() << " operator" << MagicToRepr.at(magicType);
            } else {
                output << getReturnType().getName() << ' ' << name;
            }
        }

        output << '(' << argumentsToString() << ") ";

        addConstModifier(output);
        addNoexceptModifier(output);

        if (functionBody != nullptr) {
            output << *functionBody.get();
        } else {
            output << ';';
        }
    }
}// namespace fsc::ast
