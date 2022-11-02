#include "converters/int.hpp"
#include <utility>

using namespace std::string_view_literals;

namespace fsc::converter {
    constexpr static auto BinaryBegin = "0b"sv;
    constexpr static auto OctalBegin = "0o"sv;
    constexpr static auto HexadecimalBegin = "0x"sv;

    auto toInt(const std::string &repr) -> std::shared_ptr<ast::Value>
    {
        constexpr static auto default_options =
                ValueOptions{.constant = true, .compile_time_available = true};

        auto result = 0Z;

        if (repr.starts_with(BinaryBegin)) {
            result = std::stoll(repr.substr(BinaryBegin.size()), nullptr, 2);
        } else if (repr.starts_with(OctalBegin)) {
            result = std::stoll(repr.substr(OctalBegin.size()), nullptr, 8);
        } else if (repr.starts_with(HexadecimalBegin)) {
            result = std::stoll(repr.substr(HexadecimalBegin.size()), nullptr, 16);
        } else {
            result = std::stoll(repr);
        }

        if (std::in_range<int32_t>(result)) {
            auto fsc_value = std::make_shared<FscBuiltinType<Int32>>(
                    Int32{static_cast<int32_t>(result)}, default_options);
            return std::make_shared<ast::Value>(fsc_value);
        }

        auto fsc_value = std::make_shared<FscBuiltinType<Int64>>(Int64{result}, default_options);
        return std::make_shared<ast::Value>(fsc_value);
    }
}// namespace fsc::converter
