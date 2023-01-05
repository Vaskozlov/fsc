#include "ast/expression/conversion.hpp"
#include "function/functions_holder.hpp"
#include "type/type.hpp"

namespace fsc::ast
{
    using namespace std::string_view_literals;

    Conversion::Conversion(NodePtr value_to_convert, ccl::Id type_id)
      : value{std::move(value_to_convert)}
      , typeId{type_id}
    {
        CCL_ASSERT(this->getNodeType() == NodeType::CONVERSION);
    }

    auto Conversion::analyze() const -> void
    {
        const auto function_name = FscType::getTypeName(typeId);

        [[maybe_unused]] auto make_sure_that_conversion_exists = func::Functions.visitFunction(
            {std::string{function_name}, {Argument{value.get()}}},
            std::mem_fn(&Function::getReturnType));
    }

    auto Conversion::codeGen(ccl::codegen::BasicCodeGenerator &output) const -> void
    {
        output << FscType::getTypeName(typeId) << '{' << *value << '}';
    }

    auto Conversion::getValueType() const -> ccl::Id
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
