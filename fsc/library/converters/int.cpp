#include "converters/int.hpp"
#include <utility>

using namespace std::string_view_literals;

namespace fsc::converter
{
    using namespace ccl;

    constexpr static auto BinaryBegin = "0b"sv;
    constexpr static auto OctalBegin = "0o"sv;
    constexpr static auto HexadecimalBegin = "0x"sv;

    auto toInt(const std::string &repr) -> SharedPtr<ast::Value>
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
            auto fsc_value = makeUnique<FscBuiltinType<FscInt32>>(as<int32_t>(result));
            return makeShared<ast::Value>(std::move(fsc_value));
        }

        auto fsc_value = makeUnique<FscBuiltinType<FscInt64>>(result);
        return makeShared<ast::Value>(std::move(fsc_value));
    }
}// namespace fsc::converter
