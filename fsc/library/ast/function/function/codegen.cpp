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
        if (classType != Void || magicType == MagicFunctionType::INIT || name == "main") {
            return;
        }

        switch (visibility) {
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
        if (getReturnTypeAsString() != "void" && name != "main") {
            output << "[[nodiscard]] ";
        }
    }

    auto Function::addConstexprModifier(codegen::BasicCodeGenerator &output) const -> void
    {
        if (name != "main") {
            output << "constexpr ";
        }
    }

    auto Function::genArguments(codegen::BasicCodeGenerator &output) -> void
    {
        output << ccl::join(
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
            genVisibility(visibility, output);
        }

        if (magicType == MagicFunctionType::INIT || magicType == MagicFunctionType::DEL) {
            addConstexprModifier(output);
            output << name;
        } else {
            addNodiscardModifier(output);
            addConstexprModifier(output);
            addVisibility(output);

            if (magicType != MagicFunctionType::NONE) {
                output << getReturnTypeAsString() << " operator" << MagicToRepr.at(magicType);
            } else {
                output << getReturnTypeAsString() << ' ' << name;
            }
        }

        output << '(';
        genArguments(output);
        output << ')';

        output << *functionBody.get();
    }
}// namespace fsc::ast
