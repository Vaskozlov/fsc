#include "ast/function/function.hpp"

namespace fsc::ast
{
    auto Function::operator==(SignatureView other) const noexcept -> bool
    {
        if (arguments.size() > std::size(other.arguments)) {
            return false;
        }

        const auto is_constructor =
            (other.classType == Void && getMagicType() == MagicFunctionType::INIT);

        const auto argument_before_parameter_pack_equal = std::ranges::equal(
            arguments.cbegin(), arguments.cend(), other.arguments.cbegin(),
            other.arguments.cbegin() + ccl::as<std::ptrdiff_t>(arguments.size()));

        if (!argument_before_parameter_pack_equal) {
            return false;
        }

        auto arguments_equal = argument_before_parameter_pack_equal;

        if (std::size(other.arguments) > arguments.size()) {
            arguments_equal = functionInfo.HAVE_PARAMETER_PACK;
        }

        if (!arguments_equal) {
            return false;
        }

        const auto have_similar_names = name == other.name;
        const auto have_similar_class_id = classType == other.classType;

        return have_similar_names && (have_similar_class_id || is_constructor);
    }
}// namespace fsc::ast
