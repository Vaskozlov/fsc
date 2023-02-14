#include "ast/function/function.hpp"
#include "ast/function/magic_methods_table.hpp"
#include <type/builtin_types.hpp>
#include <type/type.hpp>

using namespace fsc::ast::magic;

namespace fsc::ast
{
    auto Function::processMagicMethod() -> void
    {
        if (classType != Void) {
            if (name == "__init__") {
                processInitMethod();
            } else if (name == "__del__") {
                processDelMethod();
            } else if (SpecialFunctionsMagic.contains(name)) {
                processBinaryOperatorMethod(SpecialFunctionsMagic[name]);
            }
        }
    }

    auto Function::processInitMethod() noexcept(false) -> void
    {
        magicType = MagicFunctionType::INIT;
        name = classType.getName();

        if (getReturnType() != Auto) {
            throw std::runtime_error("You are not allowed to set return type of __init__ method");
        }

        returnType = classType;
    }

    auto Function::processDelMethod() noexcept(false) -> void
    {
        magicType = MagicFunctionType::DEL;
        name = fmt::format("~{}", classType.getName());

        if (!arguments.empty()) {
            throw std::runtime_error(
                "You are not allowed to set pass any arguments to __del__ method");
        }

        if (getReturnType() != Auto) {
            throw std::runtime_error("You are not allowed to set return type of __del__ method");
        }

        returnType = Void;
    }

    auto Function::processBinaryOperatorMethod(MagicFunctionType binary_operator) noexcept(false)
        -> void
    {
        magicType = binary_operator;
        name = MagicToFscName.at(binary_operator);

        if (arguments.size() != 1) {
            throw std::runtime_error("You are allowed to pass one argument to binary magic method");
        }
    }
}// namespace fsc::ast
