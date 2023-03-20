#ifndef FSC_MAGIC_METHODS_TABLE_HPP
#define FSC_MAGIC_METHODS_TABLE_HPP

#include "ast/function/function.hpp"
#include <ccl/flatmap.hpp>

namespace fsc::ast::magic
{
    constexpr inline auto SpecialFunctionsMagic =
        ccl::StaticFlatmap<std::string_view, MagicFunctionType, 21>{
            {"__add__", MagicFunctionType::ADD},
            {"__sub__", MagicFunctionType::SUB},
            {"__mul__", MagicFunctionType::MUL},
            {"__div__", MagicFunctionType::DIV},
            {"__mod__", MagicFunctionType::MOD},
            {"__iadd__", MagicFunctionType::IADD},
            {"__isub__", MagicFunctionType::ISUB},
            {"__imul__", MagicFunctionType::IMUL},
            {"__idiv__", MagicFunctionType::IDIV},
            {"__imod__", MagicFunctionType::IMOD},
            {"__equal__", MagicFunctionType::EQUAL},
            {"__not_equal__", MagicFunctionType::NOT_EQUAL},
            {"__less__", MagicFunctionType::LESS},
            {"__greater__", MagicFunctionType::GREATER},
            {"__less_equal__", MagicFunctionType::LESS_EQ},
            {"__greater_equal__", MagicFunctionType::GREATER_EQ},
            {"__copy__", MagicFunctionType::COPY_ASSIGN},
            {"__init__", MagicFunctionType::INIT},
            {"__del__", MagicFunctionType::DEL},
            {"__invert__", MagicFunctionType::INVERT},
            {"__logical_not__", MagicFunctionType::LOGICAL_NOT}};

    constexpr inline ccl::StaticFlatmap<MagicFunctionType, std::string_view, 19> MagicToFscName = {
        {MagicFunctionType::ADD, "__add__"},
        {MagicFunctionType::SUB, "__sub__"},
        {MagicFunctionType::MUL, "__mul__"},
        {MagicFunctionType::DIV, "__div__"},
        {MagicFunctionType::MOD, "__mod__"},
        {MagicFunctionType::IADD, "__iadd__"},
        {MagicFunctionType::ISUB, "__isub__"},
        {MagicFunctionType::IMUL, "__imul__"},
        {MagicFunctionType::IDIV, "__idiv__"},
        {MagicFunctionType::IMOD, "__imod__"},
        {MagicFunctionType::EQUAL, "__equal__"},
        {MagicFunctionType::NOT_EQUAL, "__not_equal__"},
        {MagicFunctionType::LESS, "__less__"},
        {MagicFunctionType::GREATER, "__greater__"},
        {MagicFunctionType::LESS_EQ, "__less_equal__"},
        {MagicFunctionType::GREATER_EQ, "__greater_equal__"},
        {MagicFunctionType::COPY_ASSIGN, "__copy__"},
        {MagicFunctionType::INVERT, "__invert__"},
        {MagicFunctionType::LOGICAL_NOT, "__logical_not__"}};

    constexpr inline ccl::StaticFlatmap<MagicFunctionType, std::string_view, 19> MagicToRepr = {
        {MagicFunctionType::ADD, "+"},         {MagicFunctionType::SUB, "-"},
        {MagicFunctionType::MUL, "*"},         {MagicFunctionType::DIV, "/"},
        {MagicFunctionType::MOD, "%"},         {MagicFunctionType::COPY_ASSIGN, "="},
        {MagicFunctionType::IADD, "+="},       {MagicFunctionType::ISUB, "-="},
        {MagicFunctionType::IMUL, "*="},       {MagicFunctionType::IDIV, "/="},
        {MagicFunctionType::IMOD, "%="},       {MagicFunctionType::EQUAL, "=="},
        {MagicFunctionType::NOT_EQUAL, "!="},  {MagicFunctionType::LESS, "<"},
        {MagicFunctionType::GREATER, ">"},     {MagicFunctionType::LESS_EQ, "<="},
        {MagicFunctionType::GREATER_EQ, ">="}, {MagicFunctionType::INVERT, "~"},
        {MagicFunctionType::LOGICAL_NOT, "!"},
    };
}// namespace fsc::ast::magic

#endif /* FSC_MAGIC_METHODS_TABLE_HPP */
