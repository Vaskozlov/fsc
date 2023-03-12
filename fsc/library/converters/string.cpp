#include "converters/string.hpp"

namespace fsc::converter
{
    using namespace ccl;

    auto toChar(const std::string &repr, BasicContextPtr value_context)
        -> ccl::SharedPtr<ast::Value>
    {
        auto fsc_value = makeUnique<FscBuiltinType<FscChar>>(repr[1]);
        return makeShared<ast::Value>(std::move(fsc_value), value_context);
    }

    auto toString(const std::string &repr, BasicContextPtr value_context) -> SharedPtr<ast::Value>
    {
        auto fsc_value = makeUnique<FscBuiltinType<FscString>>(repr);
        return makeShared<ast::Value>(std::move(fsc_value), value_context);
    }
}// namespace fsc::converter
