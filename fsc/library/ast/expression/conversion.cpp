#include "ast/expression/conversion.hpp"
#include "function/argument.hpp"
#include "function/functions_holder.hpp"
#include "type/type.hpp"
#include <ccl/core/types.hpp>

namespace fsc::ast
{
    using namespace ccl;
    using namespace std::string_view_literals;

    Conversion::Conversion(NodePtr value_to_convert, FscType fsc_type)
      : value{std::move(value_to_convert)}
      , type{fsc_type}
    {}

    auto Conversion::analyze() -> AnalysisReport
    {
        const auto &function_name = type.getName();
        const auto arguments = SmallVector<Argument>{Argument{value.get()}};
        const auto signature_view = SignatureView{function_name, arguments, Void};
        auto function = func::Functions.get(signature_view);

        return function->analyze();
    }

    auto Conversion::codeGen(codegen::BasicCodeGenerator &output) -> void
    {
        output << "static_cast<" << type.getName() << ">(" << *value << ')';
    }

    auto Conversion::getValueType() -> FscType
    {
        return type;
    }

    auto Conversion::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print("{} Conversion to {}\n", getPrintingPrefix(prefix, is_left), type);
        value->print(expandPrefix(prefix, is_left), false);
    }
}// namespace fsc::ast
