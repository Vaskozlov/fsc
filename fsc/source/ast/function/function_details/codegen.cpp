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

    auto Function::genArguments(codegen::BasicCodeGenerator &output) const -> void
    {
        for (const auto &arg : arguments | ccl::views::dropBack(arguments)) {
            argumentToString(output, arg);
            output << ", ";
        }

        if (!arguments.empty()) {
            argumentToString(output, arguments.back());
        }
    }

    auto Function::generateTemplateParameters(codegen::BasicCodeGenerator &output) const
        -> void
    {
        if (!templates.empty()) {
            output << "template<typename ";
            fmt::format_to(output.getBackInserter(), "{}", fmt::join(templates, ", typename "));
            output << ">\n";
        }
    }

    auto Function::codeGen(codegen::BasicCodeGenerator &output) const -> void
    {
        generateTemplateParameters(output);

        if (isMember()) {
            genVisibility(visibility, output);
        }

        switch (magicType) {
        case MagicFunctionType::DEL:
        case MagicFunctionType::INIT:
            addConstexprModifier(output);
            output << name;
            break;

        case MagicFunctionType::ADD:
        case MagicFunctionType::SUB:
        case MagicFunctionType::MUL:
        case MagicFunctionType::DIV:
        case MagicFunctionType::MOD:
            addNodiscardModifier(output);
            addConstexprModifier(output);

            output << getReturnTypeAsString() << " operator" << MagicToRepr.at(magicType);
            break;

        default:
            addNodiscardModifier(output);
            addConstexprModifier(output);

            output << getReturnTypeAsString() << ' ' << name;
            break;
        }

        output << '(';
        genArguments(output);
        output << ')';

        output << *functionBody.get();
    }
}// namespace fsc::ast
