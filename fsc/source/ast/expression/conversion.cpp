#include "ast/expression/conversion.hpp"
#include "function/argument.hpp"
#include "function/functions_holder.hpp"
#include "type/type.hpp"
#include <ccl/core/types.hpp>

namespace fsc::ast
{
    using namespace ccl;
    using namespace std::string_view_literals;

    Conversion::Conversion(NodePtr value_to_convert, ccl::Id type_id)
      : value{std::move(value_to_convert)}
      , typeId{type_id}
    {}

    auto Conversion::analyze() const -> void
    {
        const auto function_name = std::string{FscType::getTypeName(typeId)};
        const auto arguments = SmallVector<Argument>{Argument{value.get()}};
        const auto signature_view = SignatureView{function_name, arguments};

        [[maybe_unused]] auto make_sure_that_conversion_exists =
            func::Functions.visitFunction(signature_view, std::mem_fn(&Function::getReturnType));
    }

    auto Conversion::codeGen(codegen::BasicCodeGenerator &output) const -> void
    {
        output << FscType::getTypeName(typeId) << '{' << *value << '}';
    }

    auto Conversion::getValueType() const -> Id
    {
        return typeId;
    }

    auto Conversion::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print(
            "{} Conversion to {}\n",
            getPrintingPrefix(prefix, is_left),
            FscType::getTypeName(typeId));
        value->print(expandPrefix(prefix, is_left), false);
    }
}// namespace fsc::ast
