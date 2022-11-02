#include "ast/function.hpp"
#include "function/function.hpp"
#include <ranges>

using namespace std::string_view_literals;

namespace fsc::ast {
    auto Function::print(const std::string &prefix, const bool is_left) const -> void
    {
        fmt::print("{}Function {}\n", getPrintingPrefix(prefix, is_left), function.getName());

        auto body = function.getBody();
        body.value()->print(expandPrefix(prefix, is_left));
    }

    auto Function::codeGen(gen::CodeGenerator &output) const -> void
    {
        output.add(FscType::getTypeName(function.getReturnType()));
        output.add(' ');
        output.add(function.getName());

        output.add('(');
        genArguments(output);
        output.add(')');

        const auto &body = function.getBody();
        (body.value())->codeGen(output);
    }

    auto Function::genArguments(gen::CodeGenerator &output) const -> void
    {
        const auto &arguments = function.getArguments();

        for (const auto &arg : arguments | std::views::take(arguments.size() - 1)) {
            argumentToString(output, arg);
            output.add(", "sv);
        }

        if (!arguments.empty()) {
            argumentToString(output, arguments.back());
        }
    }

    auto Function::argumentToString(gen::CodeGenerator &output, const func::Argument &arg) const
            -> void
    {
        const auto &name = arg.name;
        auto category = arg.category;
        const auto &type_name = FscType::getTypeName(arg.type);

        if (category == func::ArgumentCategory::IN && FscType::isTriviallyCopyable(arg.type)) {
            category = func::ArgumentCategory::COPY;
        }

        switch (category) {
            case func::ArgumentCategory::COPY:
                output.add(fmt::format("{} {}", type_name, name));
                break;

            case func::ArgumentCategory::IN:
                output.add(fmt::format("const {} & {}", type_name, name));
                break;

            case func::ArgumentCategory::OUT:
            case func::ArgumentCategory::INOUT:
                output.add(fmt::format("{} & {}", type_name, name));
                break;

            default:
                std::unreachable();
        }

        const auto &default_arguments = function.getDefaultArguments();

        if (default_arguments.contains(name)) {
            output.add(" = "sv);
            default_arguments.at(name)->codeGen(output);
        }
    }
}// namespace fsc::ast
