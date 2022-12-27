#include "converters/bool.hpp"
#include "ccl/core/types.hpp"

namespace fsc::converter
{
    auto toBoolean(const std::string &repr) -> ccl::SharedPtr<ast::Value>
    {
        auto fsc_value = ccl::makeUnique<FscBuiltinType<Bool>>(Bool{repr == "true"});
        return ccl::makeShared<ast::Value>(std::move(fsc_value));
    }
}// namespace fsc::converters
