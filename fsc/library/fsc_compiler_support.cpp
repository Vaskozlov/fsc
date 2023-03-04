#include "compiler.hpp"

namespace fsc
{
    using namespace std::string_view_literals;

    constexpr std::string_view CompilerFlags =
        "-std=c++2b -DFMT_HEADER_ONLY=1 -fmodules -fbuiltin-module-map -fimplicit-module-maps "
        "-fprebuilt-implicit-modules -stdlib=libc++";

    constexpr std::string_view FscProgramsHeader = R"cpp(
import std;

#include <fmt/format.h>
#include <fmt/ranges.h>

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using f32 = float;
using f64 = double;

template<typename T>
class Vector : public std::vector<T>
{
public:
    using std::vector<T>::at;
    using std::vector<T>::size;
    using std::vector<T>::empty;

    template<typename... Ts>
    constexpr Vector(Ts &&...initial_value)// NOLINT
        requires(std::constructible_from<std::vector<T>, Ts...>)
      : std::vector<T>{std::forward<Ts>(initial_value)...}
    {}

    constexpr Vector(const std::initializer_list<T> &initializer)// NOLINT
      : std::vector<T>{initializer}
    {}

    constexpr auto max() const -> const T &
    {
        if (empty()) {
            throw std::logic_error{
                fmt::format("Vector<{}>::max vector is empty", typeid(T).name())};
        }

        return *std::ranges::max_element(*this);
    }

    constexpr auto min() const -> const T &
    {
        if (empty()) {
            throw std::logic_error{
                fmt::format("Vector<{}>::min vector is empty", typeid(T).name())};
        }

        return *std::ranges::min_element(*this);
    }

    constexpr auto max(const T &default_value) const -> const T &
    {
        if (empty()) {
            return default_value;
        }

        return *std::ranges::max_element(*this);
    }

    constexpr auto min(const T &default_value) const -> const T &
    {
        if (empty()) {
            return default_value;
        }

        return *std::ranges::min_element(*this);
    }

    constexpr auto swap(size_t first, size_t second) -> void
    {
        if (std::max(first, second) >= size()) {
            throw std::out_of_range{fmt::format("Vector<{}>::swap", typeid(T).name())};
        }

        std::swap(this->at(first), this->at(second));
    }
};

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
        fmt::print("{}", str);
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
