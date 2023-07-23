#include "converters/int.hpp"
#include <utility>

using namespace std::string_view_literals;

namespace fsc::converter
{
    using namespace ccl;

    constexpr static auto BinaryBegin = "0b"sv;
    constexpr static auto OctalBegin = "0o"sv;
    constexpr static auto HexadecimalBegin = "0x"sv;

    static auto toUInt(std::string repr, BasicContextPtr value_context) -> SharedPtr<ast::Value>
    {
        CCL_ASSERT(repr.back() == 'U');
        repr.pop_back();

        auto result = as<size_t>(0);

        if (repr.starts_with(BinaryBegin)) {
            result = std::stoull(repr.substr(BinaryBegin.size()), nullptr, 2);
        } else if (repr.starts_with(OctalBegin)) {
            result = std::stoull(repr.substr(OctalBegin.size()), nullptr, 8);
        } else if (repr.starts_with(HexadecimalBegin)) {
            result = std::stoull(repr.substr(HexadecimalBegin.size()), nullptr, 16);
        } else {
            result = std::stoull(repr);
        }

        if (std::in_range<uint32_t>(result)) {
            auto fsc_value = makeUnique<FscBuiltinType<FscUInt32>>(as<uint32_t>(result));
            return makeShared<ast::Value>(std::move(fsc_value), value_context);
        }

        auto fsc_value = makeUnique<FscBuiltinType<FscUInt64>>(result);
        return makeShared<ast::Value>(std::move(fsc_value), value_context);
    }

    auto toInt(const std::string &repr, BasicContextPtr value_context) -> SharedPtr<ast::Value>
    {
        if (repr.back() == 'U') {
            return toUInt(repr, value_context);
        }

        auto result = as<ssize_t>(0);

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
            return makeShared<ast::Value>(std::move(fsc_value), value_context);
        }

        auto fsc_value = makeUnique<FscBuiltinType<FscInt64>>(result);
        return makeShared<ast::Value>(std::move(fsc_value), value_context);
    }
}// namespace fsc::converter
