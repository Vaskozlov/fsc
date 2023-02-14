#include "converters/float.hpp"
#include "ast/value/value.hpp"

namespace fsc::converter
{
    using namespace ccl;

    auto toFloat(const std::string &repr) -> SharedPtr<ast::Value>
    {
        if (repr.ends_with("F64")) {
            auto result = std::stod(repr);
            auto fsc_value = makeUnique<FscBuiltinType<FscFloat64>>(result);
            return makeShared<ast::Value>(std::move(fsc_value));
        }

        auto result = std::stof(repr);
        auto fsc_value = makeUnique<FscBuiltinType<FscFloat32>>(result);

        return makeShared<ast::Value>(std::move(fsc_value));
    }
}// namespace fsc::converter
