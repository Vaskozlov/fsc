#include "ast/value/variable.hpp"
#include <fmt/format.h>

namespace fsc::ast
{
    using namespace ccl;

    Variable::Variable(std::string variable_name, Id type_id, VariableFlags variable_flags)
      : name{std::move(variable_name)}
      , typeId{type_id}
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
