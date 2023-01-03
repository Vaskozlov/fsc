#include "ast/return.hpp"
#include "type/builtin_types.hpp"
#include <ast/basic_node.hpp>
#include <fmt/format.h>
#include <stdexcept>

namespace fsc::ast
{
    using namespace std::string_view_literals;

    Return::Return(Visitor &visitor, NodePtr value_to_return)
      : value{std::move(value_to_return)}
    {
        CCL_ASSERT(this->getNodeType() == NodeType::RETURN);

        if (auto return_type = visitor.getCurrentFunctionReturnType();
            return_type == Auto::typeId) {
            visitor.updateFunctionReturnType(value->getValueType());
        } else if (return_type != value->getValueType()) {
            throw std::runtime_error{
                "Return type of the function does not math with function return type"};
        }
    }

    auto Return::codeGen(ccl::codegen::BasicCodeGenerator &output) const -> void
    {
        output << "return " << *value;
    }

    auto Return::getValueType() const -> ccl::Id
    {
        return value->getValueType();
    }

    auto Return::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print("{}return \n", getPrintingPrefix(prefix, is_left));
        value->print(expandPrefix(prefix, is_left), false);
    }
}// namespace fsc::ast
