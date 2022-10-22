#include "builtin/types.hpp"

namespace fsc {
    std::unordered_map<std::string, size_t> FscValue::definedTypes{
            {"auto", Auto::hash},  {"i32", Int32::hash},  {"u32", UInt32::hash},
            {"i64", Int64::hash},  {"u64", UInt64::hash}, {"f32", Float32::hash},
            {"f64", Float64::hash}};

    std::unordered_map<size_t, std::string> FscValue::typenameById{
            {Auto::hash, "auto"},  {Int32::hash, "i32"},  {UInt32::hash, "u32"},
            {Int64::hash, "i64"},  {UInt64::hash, "u64"}, {Float32::hash, "f32"},
            {Float64::hash, "f64"}};

    auto FscValue::toString() const -> std::string
    {
        auto result = std::string{};
        const auto inserter = std::back_inserter(result);

        if (type == Int32::hash) {
            fmt::format_to(inserter, "i32: {}",
                           value.has_value() ? 0 : std::any_cast<int32_t>(value));
        } else if (type == Int64::hash) {
            fmt::format_to(inserter, "i64: {}",
                           value.has_value() ? 0L : std::any_cast<int64_t>(value));
        } else if (type == Float32::hash) {
            fmt::format_to(inserter, "f32: {}",
                           value.has_value() ? 0.0F : std::any_cast<float>(value));
        } else if (type == Float64::hash) {
            fmt::format_to(inserter, "f64: {}",
                           value.has_value() ? 0.0 : std::any_cast<double>(value));
        } else {
            result = "value with unprintable type";
        }

        return result;
    }

    auto FscValue::checkTypeExistence(const std::string &type_name) -> void
    {
        if (!typeExists(type_name)) {
            throw std::runtime_error(
                    fmt::format("Type {} does not exist or has not been declared yet", type_name));
        }
    }
}// namespace fsc
