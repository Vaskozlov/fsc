#include "ast/value/value.hpp"
#include <fmt/format.h>

namespace fsc::ast
{
    using namespace ccl;
    using namespace std::string_view_literals;

    Value::Value(UniquePtr<FscType> t_value)
      : value{std::move(t_value)}
    {}

    auto Value::analyze() const -> void
    {}

    auto Value::codeGen(codegen::BasicCodeGenerator &output) const -> void
    {
        output << *value;
    }

    auto Value::getValueType() const -> Id
    {
        return value->getId();
    }

    auto Value::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print("{}{}\n", getPrintingPrefix(prefix, is_left), value->toString());
    }
}// namespace fsc::ast
