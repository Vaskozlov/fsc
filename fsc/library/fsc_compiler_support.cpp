#include "compiler.hpp"

namespace fsc
{
    using namespace std::string_view_literals;

    constexpr std::string_view CompilerFlags = "-std=c++17";

    constexpr std::string_view FscProgramsHeader = R"cpp(
#include <algorithm>
#include <cinttypes>
#include <cmath>
#include <concepts>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using f32 = float;
using f64 = double;

static auto operator*(const std::string &str, size_t repeat) -> std::string
{
    auto result = std::string{};
    result.reserve(str.size() * repeat);

    for (size_t i = 0; i != repeat; ++i) {
        result.append(str);
    }

    return result;
}

template<typename T>
static auto log(T argument, T base) -> T
{
    return std::log(argument) / std::log(base);
}

template<typename T>
class Vector : public std::vector<T>
{
public:
    using std::vector<T>::at;
    using std::vector<T>::size;
    using std::vector<T>::empty;

    using std::vector<T>::begin;
    using std::vector<T>::end;

    using std::vector<T>::rbegin;
    using std::vector<T>::rend;

    template<typename... Ts>
    constexpr Vector(Ts &&...initial_value)// NOLINT
      : std::vector<T>{std::forward<Ts>(initial_value)...}
    {}

    constexpr Vector(const std::initializer_list<T> &initializer)// NOLINT
      : std::vector<T>{initializer}
    {}

    [[nodiscard]] constexpr auto operator[](size_t index) -> T &
    {
        return at(index);
    }

    [[nodiscard]] constexpr auto operator[](size_t index) const -> const T &
    {
        return at(index);
    }

    [[nodiscard]] constexpr auto max() const -> const T &
    {
        if (empty()) {
            throw std::logic_error{"Vector<T>::max vector is empty"};
        }

        return *std::max_element(begin(), end());
    }

    [[nodiscard]] constexpr auto min() const -> const T &
    {
        if (empty()) {
            throw std::logic_error{"Vector<T>::min vector is empty"};
        }

        return *std::min_element(begin(), end());
    }

    [[nodiscard]] constexpr auto max(const T &default_value) const -> const T &
    {
        if (empty()) {
            return default_value;
        }

        return *std::max_element(begin(), end());
    }

    [[nodiscard]] constexpr auto min(const T &default_value) const -> const T &
    {
        if (empty()) {
            return default_value;
        }

        return *std::min_element(begin(), end());
    }

    constexpr auto swap(size_t first, size_t second) -> void
    {
        std::swap(at(first), at(second));
    }

    constexpr auto sort(bool reverse = false) -> void
    {
        if (reverse) {
            std::sort(rbegin(), rend());
        } else {
            std::sort(begin(), end());
        }
    }
};

class String : public std::string
{
public:
    template<typename... Ts>
    constexpr String(Ts &&...initial_value)// NOLINT
      : std::string{std::forward<Ts>(initial_value)...}
    {}

    [[nodiscard]] constexpr auto operator[](size_t index) -> char &
    {
        return this->at(index);
    }

    [[nodiscard]] constexpr auto operator[](size_t index) const -> const char &
    {
        return this->at(index);
    }

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
        std::cout << str;
    }

    String result;
    std::getline(std::cin, result);
    return result;
}

template<typename T>
auto print(T &&arg) -> void
{
    std::cout << arg << std::endl;
}

template<typename T, typename... Ts>
auto print(T &&arg, Ts &&...args) -> void
{
    std::cout << arg << ' ';
    print(std::forward<Ts>(args)...);
}

template<typename Os, typename T>
auto operator<<(Os &os, const Vector<T> &vec) -> Os &
{
    auto begin = std::begin(vec);
    const auto end = std::end(vec);

    os << '[';

    if (begin == end) {
        os << ']';
        return os;
    }

    os << *begin;

    for (++begin; begin != end; ++begin) {
        os << ", ";
        os << *begin;
    }

    os << ']';

    return os;
}
)cpp";
}// namespace fsc
