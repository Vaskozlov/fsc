#include "converters/bool.hpp"
#include <ccl/core/types.hpp>

namespace fsc::converter
{
    using namespace ccl;

    auto toBoolean(const std::string &repr) -> SharedPtr<ast::Value>
    {
        auto fsc_value = makeUnique<FscBuiltinType<Bool>>(repr == "true");
        return makeShared<ast::Value>(std::move(fsc_value));
    }
}// namespace fsc::converters
