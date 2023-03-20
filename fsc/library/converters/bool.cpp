#include "converters/bool.hpp"
#include <ccl/core/types.hpp>

namespace fsc::converter
{
    using namespace ccl;

    auto toBoolean(const std::string &repr, BasicContextPtr value_context) -> SharedPtr<ast::Value>
    {
        auto fsc_value = makeUnique<FscBuiltinType<FscBool>>(repr == "true");
        return makeShared<ast::Value>(std::move(fsc_value), value_context);
    }
}// namespace fsc::converter
