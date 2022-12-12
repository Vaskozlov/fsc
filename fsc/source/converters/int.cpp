#include "converters/int.hpp"
#include <utility>

using namespace std::string_view_literals;

namespace fsc::converter
{
    constexpr static auto BinaryBegin = "0b"sv;
    constexpr static auto OctalBegin = "0o"sv;
    constexpr static auto HexadecimalBegin = "0x"sv;

    auto toInt(const std::string &repr) -> ccl::SharedPtr<ast::Value>
    {
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
            auto i32_value = Int32{ccl::as<int32_t>(result)};
            auto fsc_value = ccl::makeShared<FscBuiltinType<Int32>>(i32_value);
            return ccl::makeShared<ast::Value>(std::move(fsc_value));
        }

        auto fsc_value = ccl::makeShared<FscBuiltinType<Int64>>(Int64{result});
        return ccl::makeShared<ast::Value>(std::move(fsc_value));
    }
}// namespace fsc::converter
