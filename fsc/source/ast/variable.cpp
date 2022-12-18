#include "ast/variable.hpp"
#include <ast/basic_node.hpp>
#include <fmt/format.h>

namespace fsc::ast
{
    Variable::Variable(std::string variable_name, ccl::Id type_id, VariableFlags variable_flags)
      : name{std::move(variable_name)}
      , typeId{type_id}
      , flags{variable_flags}
    {
        CCL_ASSERT(this->getNodeType() == NodeType::VARIABLE);
    }

    auto Variable::codeGen(gen::CodeGenerator &output) const -> void
    {
        output << name;
    }

    auto Variable::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print("{}{}\n", getPrintingPrefix(prefix, is_left), name);
    }
}// namespace fsc::ast
