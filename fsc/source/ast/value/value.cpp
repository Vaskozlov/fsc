#include "ast/value/value.hpp"
#include <fmt/format.h>

namespace fsc::ast
{
    using namespace std::string_view_literals;

    Value::Value(ccl::UniquePtr<FscType> t_value)
      : value{std::move(t_value)}
    {
        CCL_ASSERT(this->getNodeType() == NodeType::VALUE);
    }

    auto Value::codeGen(gen::CodeGenerator &output) const -> void
    {
        output << *value;
    }

    auto Value::getValueType() const -> ccl::Id
    {
        return value->getId();
    }

    auto Value::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print("{}{}\n", getPrintingPrefix(prefix, is_left), value->toString());
    }
}// namespace fsc::ast
