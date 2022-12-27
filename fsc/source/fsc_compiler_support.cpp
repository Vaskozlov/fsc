#include "compiler.hpp"

namespace fsc
{
    using namespace std::string_view_literals;

    constinit const std::string_view ClangCompilerFlags = "-std=c++2b -DFMT_HEADER_ONLY=1";

    constinit const std::string_view FscProgramsHeader = R"cpp(
#include <concepts>
#include <string>
#include <cstddef>
#include <cinttypes>
#include <iostream>
#include <fmt/format.h>

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using f32 = float;
using f64 = double;

class string : public std::string
{
public:
    string() = default;

    template<typename T>
    constexpr string(T &&initial_value)
        requires(std::constructible_from<std::string, T>)
      : std::string{std::forward<T>(initial_value)}
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

auto input(string str = {}) -> string
{
    if (!str.empty())
    {
        fmt::print("{}\n", str);
    }

    string result;
    std::getline(std::cin, result);
    return result;
}

auto print(const string &fmt, auto&&... args) -> void
{
    fmt::print(fmt::runtime(fmt), std::forward<decltype(args)>(args)...);
}

auto format(const string &fmt, auto&&... args) -> string
{
    return fmt::format(fmt::runtime(fmt), std::forward<decltype(args)>(args)...);
}

)cpp";
}// namespace fsc
