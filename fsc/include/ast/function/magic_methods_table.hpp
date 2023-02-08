 #ifndef FSC_MAGIC_METHODS_TABLE_HPP
#define FSC_MAGIC_METHODS_TABLE_HPP

#include "ast/function/function.hpp"
#include <ccl/flatmap.hpp>

namespace fsc::ast::magic
{
    constexpr inline auto SpecialFunctionsMagic =
        ccl::StaticFlatmap<std::string_view, MagicFunctionType, 14>{
            {"__add__", MagicFunctionType::ADD},
            {"__sub__", MagicFunctionType::SUB},
            {"__mul__", MagicFunctionType::MUL},
            {"__div__", MagicFunctionType::DIV},
            {"__mod__", MagicFunctionType::MOD},
            {"__equal__", MagicFunctionType::EQUAL},
            {"__not_equal__", MagicFunctionType::NOT_EQUAL},
            {"__less__", MagicFunctionType::LESS},
            {"__greater__", MagicFunctionType::GREATER},
            {"__less_eq__", MagicFunctionType::LESS_EQ},
            {"__greater_eq__", MagicFunctionType::GREATER_EQ},
            {"__copy__", MagicFunctionType::GREATER_EQ},
            {"__init__", MagicFunctionType::INIT},
            {"__del__", MagicFunctionType::DEL}};

    constexpr inline ccl::StaticFlatmap<MagicFunctionType, std::string_view, 12> MagicToFscName = {
        {MagicFunctionType::ADD, "__add__"},
        {MagicFunctionType::SUB, "__sub__"},
        {MagicFunctionType::MUL, "__mul__"},
        {MagicFunctionType::DIV, "__div__"},
        {MagicFunctionType::MOD, "__mod__"},
        {MagicFunctionType::EQUAL, "__equal__"},
        {MagicFunctionType::NOT_EQUAL, "__not_equal__"},
        {MagicFunctionType::LESS, "__less__"},
        {MagicFunctionType::GREATER, "__greater__"},
        {MagicFunctionType::LESS_EQ, "__less_eq__"},
        {MagicFunctionType::GREATER_EQ, "__greater_eq__"},
        {MagicFunctionType::ASSIGN, "__copy__"}};

    constexpr inline ccl::StaticFlatmap<MagicFunctionType, std::string_view, 12> MagicToRepr = {
        {MagicFunctionType::ADD, "+"},         {MagicFunctionType::SUB, "-"},
        {MagicFunctionType::MUL, "*"},         {MagicFunctionType::DIV, "/"},
        {MagicFunctionType::MOD, "%"},         {MagicFunctionType::EQUAL, "=="},
        {MagicFunctionType::NOT_EQUAL, "!="},  {MagicFunctionType::LESS, "<"},
        {MagicFunctionType::GREATER, ">"},     {MagicFunctionType::LESS_EQ, "<="},
        {MagicFunctionType::GREATER_EQ, ">="}, {MagicFunctionType::ASSIGN, "="}};
}// namespace fsc::ast::magic

#endif /* FSC_MAGIC_METHODS_TABLE_HPP */
