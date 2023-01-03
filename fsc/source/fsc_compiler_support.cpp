#include "compiler.hpp"

namespace fsc
{
    using namespace std::string_view_literals;

    constinit const std::string_view ClangCompilerFlags = "-std=c++2b -DFMT_HEADER_ONLY=1";

    constinit const std::string_view FscProgramsHeader = R"cpp(
#include <cinttypes>
#include <concepts>
#include <cstddef>
#include <fmt/format.h>
#include <iostream>
#include <string>

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using f32 = float;
using f64 = double;

class String : public std::string
{
public:
    template<typename... Ts>
    constexpr String(Ts &&...initial_value)// NOLINT
        requires(std::constructible_from<std::string, Ts...>)
      : std::string{std::forward<Ts>(initial_value)...}
    {}

    [[nodiscard]] constexpr auto toI32() const -> i32
    {
        return std::stoi(*this);
    }

    [[nodiscard]] constexpr auto toI64() const -> i64
    {
        return std::stol(*this);
    }

    [[nodiscard]] constexpr auto toU64() const -> u64
    {
        return std::stoul(*this);
    }

    [[nodiscard]] constexpr auto toF32() const -> f32
    {
        return std::stof(*this);
    }

    [[nodiscard]] constexpr auto toF64() const -> f64
    {
        return std::stod(*this);
    }
};

auto input(String str = {}) -> String
{
    if (!str.empty()) {
        fmt::print("{}\n", str);
    }

    String result;
    std::getline(std::cin, result);
    return result;
}

auto print(const String &fmt, auto &&...args) -> void
{
    fmt::print(fmt::runtime(fmt), std::forward<decltype(args)>(args)...);
}

constexpr auto format(const String &fmt, auto &&...args) -> String
{
    return fmt::format(fmt::runtime(fmt), std::forward<decltype(args)>(args)...);
}

)cpp";
}// namespace fsc
