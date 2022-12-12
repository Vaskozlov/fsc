#include "converters/float.hpp"
#include "ast/value.hpp"

namespace fsc::converter
{
    auto toFloat(const std::string &repr) -> ccl::SharedPtr<ast::Value>
    {
        if (repr.ends_with("F64")) {
            auto result = std::stod(repr);
            auto fsc_value = ccl::makeShared<FscBuiltinType<Float64>>(Float64{result});
            return ccl::makeShared<ast::Value>(fsc_value);
        }

        auto result = std::stof(repr);
        auto fsc_value = ccl::makeShared<FscBuiltinType<Float32>>(Float32{result});

        return ccl::makeShared<ast::Value>(fsc_value);
    }
}// namespace fsc::converter
