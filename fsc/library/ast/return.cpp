#include "ast/return.hpp"
#include "ast/value/value.hpp"
#include "type/builtin_types.hpp"
#include "type/builtin_types_impl.hpp"
#include <fmt/format.h>
#include <stdexcept>

namespace fsc::ast
{
    using namespace std::string_view_literals;

    Return::Return(NodePtr value_to_return, BasicContextPtr node_context)
      : NodeWrapper{node_context}
      , value{std::move(value_to_return)}
    {}

    auto Return::analyze() -> AnalysisReport
    {
        if (value == nullptr) {
            return {};
        }

        return value->analyze();
    }

    auto Return::codeGen(ccl::codegen::BasicCodeGenerator &output) -> void
    {
        output << "return ";

        if (value != nullptr) {
            output << *value;
        }
    }

    auto Return::getValueType() -> FscType
    {
        if (value == nullptr) {
            return Void;
        }

        return value->getValueType();
    }

    auto Return::optimize(OptimizationLevel level) -> void
    {
        if (value == nullptr) {
            return;
        }

        value->optimize(level);
    }

    auto Return::print(const std::string &prefix, bool is_left) const -> void
    {
        fmt::print("{}return \n", getPrintingPrefix(prefix, is_left));

        if (value != nullptr) {
            value->print(expandPrefix(prefix, is_left), false);
        }
    }
}// namespace fsc::ast
