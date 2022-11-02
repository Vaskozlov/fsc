#include "converters/float.hpp"
#include "ast/value.hpp"

namespace fsc::converter {
    auto toFloat(const std::string &repr) -> std::shared_ptr<ast::Value>
    {
        constexpr static auto default_options =
                ValueOptions{.constant = true, .compile_time_available = true};

        if (repr.ends_with("F64")) {
            auto result = std::stod(repr);
            auto fsc_value =
                    std::make_shared<FscBuiltinType<Float64>>(Float64{result}, default_options);
            return std::make_shared<ast::Value>(fsc_value);
        }

        auto result = std::stof(repr);
        auto fsc_value =
                std::make_shared<FscBuiltinType<Float32>>(Float32{result}, default_options);

        return std::make_shared<ast::Value>(fsc_value);
    }
}// namespace fsc::converter
