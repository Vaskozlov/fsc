#include "ast/value/value.hpp"
#include <fmt/format.h>

namespace fsc::ast
{
    using namespace ccl;
    using namespace std::string_view_literals;

    Value::Value(UniquePtr<FscTypeInterface> t_value, BasicContextPtr node_context)
      : NodeWrapper{node_context}
      , value{std::move(t_value)}
    {}

    auto Value::analyze() -> AnalysisReport
    {
        return {};
    }

    auto Value::codeGen(codegen::BasicCodeGenerator &output) -> void
    {
        output << *value;
    }

    auto Value::getValueType() -> FscType
    {
        return *value;
    }

    auto Value::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print("{}{}\n", getPrintingPrefix(prefix, is_left), value->toString());
    }
}// namespace fsc::ast
