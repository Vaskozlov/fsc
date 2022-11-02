#include "ast/variable_definition.hpp"

namespace fsc::ast {
    using namespace std::string_view_literals;

    auto VariableDefinition::print(const std::string &prefix, const bool is_left) const -> void
    {
        fmt::print("{}Definition of {}\n", getPrintingPrefix(prefix, is_left), name);

        if (initializer.has_value()) {
            (*initializer)->print(expandPrefix(prefix, is_left), false);
        }
    }

    auto VariableDefinition::codeGen(gen::CodeGenerator &output) const -> void
    {
        const auto &type_name = FscType::getTypeName(typeId);

        output.add(type_name);
        output.add(' ');
        output.add(name);
        output.add(" = "sv);

        if (initializer.has_value()) {
            (*initializer)->codeGen(output);
        } else {
            output.add(fmt::format("{}{{}}", type_name));
        }
    }
}// namespace fsc::ast
