#include "ast/value/variable.hpp"
#include <fmt/format.h>
#include <type/type.hpp>

namespace fsc::ast
{
    using namespace ccl;

    Variable::Variable(std::string variable_name, FscType fsc_type, VariableFlags variable_flags)
      : name{std::move(variable_name)}
      , type{fsc_type}
      , flags{variable_flags}
    {
        CCL_ASSERT(this->getNodeType() == NodeType::VARIABLE);
    }

    auto Variable::analyze() const -> void
    {}

    auto Variable::codeGen(codegen::BasicCodeGenerator &output) const -> void
    {
        output << name;
    }

    auto Variable::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print("{}{}\n", getPrintingPrefix(prefix, is_left), name);
    }
}// namespace fsc::ast
