#include "ast/variable_definition.hpp"
#include "type/type.hpp"

namespace fsc::ast {
    using namespace std::string_view_literals;

    auto VariableDefinition::print(const std::string &prefix, const bool is_left) const -> void
    {
        fmt::print("{}Definition of {}\n", getPrintingPrefix(prefix, is_left), getName());

        if (initializer != nullptr) {
            initializer->print(expandPrefix(prefix, is_left), false);
        }
    }

    auto VariableDefinition::codeGen(gen::CodeGenerator &output) const -> void
    {
        const auto &type_name = FscType::getTypeName(getValueType());

        output.write(type_name);
        output.write(' ');
        output.write(getName());
        output.write(" = "sv);

        if (initializer != nullptr) {
            initializer->codeGen(output);
        } else {
            output.write(fmt::format("{}{{}}", type_name));
        }
    }
}// namespace fsc::ast
