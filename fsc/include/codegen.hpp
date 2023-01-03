#ifndef FSC_CODEGEN_HPP
#define FSC_CODEGEN_HPP

#include <ccl/string_view.hpp>
#include <ostream>
#include <string>
#include <type_traits>

namespace fsc
{
    class FscType;
    class Argument;
}// namespace fsc

namespace fsc::ast
{
    class Node;
}

namespace fsc::gen
{
    class CodeGenerator
    {
    public:
        struct PushScope : std::true_type
        {
        };

        struct PopScope : std::false_type
        {
        };

    private:
        std::string generated;
        std::string prefix;

    public:
        [[nodiscard]] auto getGenerated() const noexcept -> const std::string &
        {
            return generated;
        }

        [[nodiscard]] auto getBackInserter() noexcept -> std::back_insert_iterator<std::string>
        {
            return std::back_inserter(generated);
        }

        auto operator<<(const Argument &argument) -> CodeGenerator &;
        auto operator<<(const ast::Node &node) -> CodeGenerator &;
        auto operator<<(const FscType &fsc_type) -> CodeGenerator &;

        auto operator<<(char chr) -> CodeGenerator &;
        auto operator<<(std::string_view str) -> CodeGenerator &;
        auto operator<<(const std::string &str) -> CodeGenerator &;

        auto operator<<(PushScope /* unused */) -> CodeGenerator &;
        auto operator<<(PopScope /* unused */) -> CodeGenerator &;

        template<size_t N>
        auto operator<<(const char (&character_array)[N]) -> CodeGenerator &
        {
            return *this << std::string_view{std::forward<const char(&)[N]>(character_array)};
        }

    private:
        auto newLine() -> void;
        auto pushScope() -> void;
        auto popScope() -> void;
    };

    constexpr inline auto endl = '\n';
    constexpr inline auto curly_opening = '{';
    constexpr inline auto curly_closing = '}';
    constexpr inline auto push_scope = CodeGenerator::PushScope{};
    constexpr inline auto pop_scope = CodeGenerator::PopScope{};
}// namespace fsc::gen

#endif /* FSC_CODEGEN_HPP */
