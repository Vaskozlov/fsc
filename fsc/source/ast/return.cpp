#include "ast/return.hpp"
#include "type/builtin_types.hpp"
#include <ast/basic_node.hpp>
#include <fmt/format.h>
#include <stdexcept>

namespace fsc::ast
{
    using namespace std::string_view_literals;

    Return::Return(NodePtr value_to_return)
      : value{std::move(value_to_return)}
    {}

    auto Return::analyze() const -> void
    {
        value->analyze();
    }

    auto Return::codeGen(ccl::codegen::BasicCodeGenerator &output) const -> void
    {
        output << "return " << *value;
    }

    auto Return::getValueType() const -> FscType
    {
        return value->getValueType();
    }

    auto Return::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print("{}return \n", getPrintingPrefix(prefix, is_left));
        value->print(expandPrefix(prefix, is_left), false);
    }
}// namespace fsc::ast
