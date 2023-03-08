#include "converters/float.hpp"
#include "ast/value/value.hpp"

namespace fsc::converter
{
    using namespace ccl;

    auto toFloat(const std::string &repr, BasicContextPtr value_context) -> SharedPtr<ast::Value>
    {
        if (repr.ends_with("F64")) {
            auto value = ReprOrValue<ccl::f64>{repr.substr(0, repr.size() - 3)};
            auto fsc_value = makeUnique<FscBuiltinType<ReprOrValue<ccl::f64>>>(Float64, value);
            return makeShared<ast::Value>(std::move(fsc_value), value_context);
        }

        auto value = ReprOrValue<f32>(repr);
        auto fsc_value = makeUnique<FscBuiltinType<ReprOrValue<ccl::f32>>>(Float32, value);

        return makeShared<ast::Value>(std::move(fsc_value), value_context);
    }
}// namespace fsc::converter
