#include "ast/conversion.hpp"

namespace fsc::ast {
    using namespace std::string_view_literals;

    auto Conversion::codeGen(gen::CodeGenerator &output) const -> void
    {
        output.add(fmt::format("{}(", FscType::getTypeName(typeId)));
        value->codeGen(output);
        output.add(')');
    }

    auto Conversion::print(const std::string &prefix, const bool is_left) const -> void
    {
        fmt::print("{} Conversion to {}\n", getPrintingPrefix(prefix, is_left),
                   FscType::getTypeName(typeId));
        value->print(expandPrefix(prefix, is_left), false);
    }
}// namespace fsc::ast
