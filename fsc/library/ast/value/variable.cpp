#include "ast/value/variable.hpp"
#include <fmt/format.h>

namespace fsc::ast
{
    using namespace ccl;

    Variable::Variable(
        std::string variable_name, ccl::Lazy<FscType> &&fsc_type, VariableFlags variable_flags)
      : name{std::move(variable_name)}
      , type{std::move(fsc_type)}
      , flags{variable_flags}
    {
        CCL_ASSERT(this->getNodeType() == NodeType::VARIABLE);
    }

    auto Variable::analyze() -> AnalysisReport
    {
        return {};
    }

    auto Variable::codeGen(codegen::BasicCodeGenerator &output) -> void
    {
        output << name;
    }

    auto Variable::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print("{}{}\n", getPrintingPrefix(prefix, is_left), name);
    }
}// namespace fsc::ast
