#include "ast/value.hpp"
#include <fmt/format.h>

namespace fsc::ast
{
    using namespace std::string_view_literals;

    Value::Value(ccl::SharedPtr<FscType> t_value)
      : value{std::move(t_value)}
    {
        CCL_ASSERT(this->getNodeType() == NodeType::VALUE);
    }

    auto Value::codeGen(gen::CodeGenerator &output) const -> void
    {
        value->codeGen(output);
    }

    auto Value::getValueType() const noexcept -> ccl::Id
    {
        return value->getId();
    }

    auto Value::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print("{}{}\n", getPrintingPrefix(prefix, is_left), value->toString());
    }
}// namespace fsc::ast
