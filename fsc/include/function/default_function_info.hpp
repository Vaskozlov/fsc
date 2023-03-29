#ifndef FSC_DEFAULT_FUNCTION_INFO_HPP
#define FSC_DEFAULT_FUNCTION_INFO_HPP

#include "ast/function/function.hpp"

namespace fsc::info
{
    constexpr inline auto NoexceptReturningFunction = ast::FunctionInfo{
        .NOEXCEPT = true,
        .BUILTIN_FUNCTION = true,
        .NODISCARD = true,
        .CONSTEXPR = true,
        .VISIBILITY = Visibility::PUBLIC};

    constexpr inline auto ThrowingConstantMethod = ast::FunctionInfo{
        .NOEXCEPT = false,
        .IS_METHOD = true,
        .CONSTANT_METHOD = true,
        .BUILTIN_FUNCTION = true,
        .CONSTEXPR = true,
        .VISIBILITY = Visibility::PUBLIC};

    constexpr inline auto NoexceptConstantMethod = ast::FunctionInfo{
        .NOEXCEPT = true,
        .IS_METHOD = true,
        .CONSTANT_METHOD = true,
        .BUILTIN_FUNCTION = true,
        .CONSTEXPR = true,
        .VISIBILITY = Visibility::PUBLIC};

    constexpr inline auto ThrowingFunction = ast::FunctionInfo{
        .NOEXCEPT = false,
        .BUILTIN_FUNCTION = true,
        .CONSTEXPR = true,
        .VISIBILITY = Visibility::PUBLIC};

    constexpr inline auto NoexceptMethod = ast::FunctionInfo{
        .NOEXCEPT = true,
        .IS_METHOD = true,
        .BUILTIN_FUNCTION = true,
        .CONSTEXPR = true,
        .VISIBILITY = Visibility::PUBLIC};

    constexpr inline auto ThrowingMethod = ast::FunctionInfo{
        .NOEXCEPT = false,
        .IS_METHOD = true,
        .BUILTIN_FUNCTION = true,
        .CONSTEXPR = true,
        .VISIBILITY = Visibility::PUBLIC};

    constexpr inline auto RuntimeThrowingMethod = ast::FunctionInfo{
        .NOEXCEPT = false,
        .IS_METHOD = true,
        .BUILTIN_FUNCTION = true,
        .CONSTEXPR = false,
        .VISIBILITY = Visibility::PUBLIC};

    constexpr inline auto RuntimeThrowingConstMethod = ast::FunctionInfo{
        .NOEXCEPT = false,
        .IS_METHOD = true,
        .CONSTANT_METHOD = true,
        .BUILTIN_FUNCTION = true,
        .CONSTEXPR = false,
        .VISIBILITY = Visibility::PUBLIC};

    constexpr inline auto RuntimeOnlyNoexceptFunction =
        ast::FunctionInfo{.NOEXCEPT = true, .CONSTEXPR = false, .VISIBILITY = Visibility::PUBLIC};

    constexpr inline auto RuntimeOnlyNoexceptMethod = ast::FunctionInfo{
        .NOEXCEPT = true,
        .CONSTEXPR = false,
        .IS_METHOD = true,
        .VISIBILITY = Visibility::PUBLIC};

    constexpr inline auto RuntimeOnlyNoexceptConstMethod = ast::FunctionInfo{
        .NOEXCEPT = true,
        .CONSTEXPR = false,
        .IS_METHOD = true,
        .CONSTANT_METHOD = true,
        .VISIBILITY = Visibility::PUBLIC};
}// namespace fsc::info

#endif /* FSC_DEFAULT_FUNCTION_INFO_HPP */
