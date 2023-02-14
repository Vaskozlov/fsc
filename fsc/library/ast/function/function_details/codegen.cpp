#include "ast/function/function.hpp"
#include "ast/function/magic_methods_table.hpp"

using namespace ccl;
using namespace fsc::ast::magic;
using namespace std::string_view_literals;

namespace fsc::ast
{
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
        for (auto &arg : arguments | ccl::views::dropBack(arguments)) {
            argumentToString(output, arg);
            output << ", ";
        }

        if (!arguments.empty()) {
            argumentToString(output, arguments.back());
        }
    }

    auto Function::generateTemplateParameters(codegen::BasicCodeGenerator &output) const -> void
    {
        if (!templates.empty()) {
            output << "template<typename ";
            fmt::format_to(output.getBackInserter(), "{}", fmt::join(templates, ", typename "));
            output << ">\n";
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
