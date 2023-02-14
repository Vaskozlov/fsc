#include "converters/string.hpp"

namespace fsc::converter
{
    using namespace ccl;

    auto toString(const std::string &repr) -> SharedPtr<ast::Value>
    {
        auto fsc_value = makeUnique<FscBuiltinType<FscString>>(repr);
        return makeShared<ast::Value>(std::move(fsc_value));
    }
}// namespace fsc::converter
