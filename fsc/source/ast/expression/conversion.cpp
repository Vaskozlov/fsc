#include "ast/expression/conversion.hpp"
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

    auto Conversion::codeGen(gen::CodeGenerator &output) const -> void
    {
        output << fmt::format("{}{{", FscType::getTypeName(typeId)) << *value << '}';
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
