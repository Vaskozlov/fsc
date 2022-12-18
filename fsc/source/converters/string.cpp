#include "converters/string.hpp"

namespace fsc::converter
{
    auto toString(const std::string &repr) -> ccl::SharedPtr<ast::Value>
    {
        auto fsc_value = ccl::makeShared<FscBuiltinType<String>>(String{repr});
        return ccl::makeShared<ast::Value>(std::move(fsc_value));
    }
}// namespace fsc::converter
