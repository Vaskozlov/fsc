#include "ast/function/magic_methods_table.hpp"
#include "function/argument.hpp"
#include "function/builtin/implement_operators.hpp"
#include "function/builtin/initialize_types.hpp"
#include "function/builtin/math.hpp"
#include "function/default_function_info.hpp"
#include "function/functions_holder.hpp"
#include "type/builtin_types.hpp"
#include "type/type.hpp"
#include <mutex>

namespace fsc::builtin
{
    using namespace ccl;
    using namespace ast;
    using namespace info;
    using namespace ast::magic;

    auto constructInt32Operators() -> Vector<Function>
    {
        auto operators = implementConstructors(Int32, {UInt32, UInt64, Int64, Float32, Float64});

        std::ranges::move(
            implementOperators<FscInt32, FscInt32>(Int32, Int32), std::back_inserter(operators));

        return operators;
    }

    auto constructInt64Operators() -> Vector<Function>
    {
        auto operators = implementConstructors(Int64, {UInt32, UInt64, Int32, Float32, Float64});

        std::ranges::move(
            implementOperators<FscInt64, FscInt64>(Int64, Int64), std::back_inserter(operators));

        std::ranges::move(
            implementOperators<FscInt64, FscInt32>(Int64, Int32), std::back_inserter(operators));

        std::ranges::move(
            implementOperators<FscInt64, FscUInt32>(Int64, UInt32), std::back_inserter(operators));

        return operators;
    }

    auto constructUInt32Operators() -> Vector<Function>
    {
        auto operators = implementConstructors(UInt32, {UInt64, Int32, Int64, Float32, Float64});

        std::ranges::move(
            implementOperators<FscUInt32, FscUInt32>(UInt32, UInt32),
            std::back_inserter(operators));

        return operators;
    }

    auto constructUInt64Operators() -> Vector<Function>
    {
        auto operators =
            implementConstructors(UInt64, {UInt32, UInt64, Int32, Int64, Float32, Float64});

        std::ranges::move(
            implementOperators<FscUInt64, FscUInt64>(UInt64, UInt64),
            std::back_inserter(operators));

        std::ranges::move(
            implementOperators<FscUInt64, FscUInt32>(UInt64, UInt32),
            std::back_inserter(operators));

        return operators;
    }

    auto constructFloat32Operators() -> Vector<Function>
    {
        auto operators = implementConstructors(Float32, {UInt32, UInt64, Int32, Int64, Float64});

        std::ranges::move(
            implementOperators<FscFloat32, FscFloat32>(Float32, Float32),
            std::back_inserter(operators));

        return operators;
    }

    auto constructFloat64Operators() -> Vector<Function>
    {
        auto operators = implementConstructors(Float64, {UInt32, UInt64, Int32, UInt64, Float32});

        std::ranges::move(
            implementOperators<FscFloat64, FscFloat64>(Float64, Float64),
            std::back_inserter(operators));

        std::ranges::move(
            implementOperators<FscFloat64, FscFloat64>(Float64, Float32),
            std::back_inserter(operators));

        return operators;
    }

    auto constructVectorFunctions() -> Vector<Function>
    {
        return Vector<Function>{
            {VectorTemplate,
             "Vector",
             "",
             VectorTemplate,
             {Argument{"value", Template1, ArgumentCategory::IN}},
             FunctionInfo{
                 .NOEXCEPT = false,
                 .IS_METHOD = true,
                 .CONSTANT_METHOD = false,
                 .BUILTIN_FUNCTION = true,
                 .HAVE_PARAMETER_PACK = true,
                 .CONSTEXPR = true,
                 .VISIBILITY = Visibility::PUBLIC},
             {Template1},
             MagicFunctionType::INIT},
            {VectorTemplate, "size", "", UInt64, {}, NoexceptConstantMethod},
            {VectorTemplate,
             "push_back",
             "",
             Void,
             {Argument{"value", Template1, ArgumentCategory::IN}},
             NoexceptMethod},
            {VectorTemplate, "sort", "", Void, {}, NoexceptMethod},
            {VectorTemplate,
             "swap",
             "",
             Void,
             {Argument{"first", UInt64, ArgumentCategory::IN},
              Argument{"second", UInt64, ArgumentCategory::IN}},
             FunctionInfo{
                 .NOEXCEPT = false,
                 .IS_METHOD = true,
                 .CONSTANT_METHOD = false,
                 .BUILTIN_FUNCTION = true,
                 .CONSTEXPR = true,
                 .VISIBILITY = Visibility::PUBLIC}},
            {VectorTemplate,
             "__at__",
             "",
             Template1,
             {Argument{"index", UInt64, ArgumentCategory::IN}},
             ThrowingMethod},
            {VectorTemplate, "max", "", Template1, {}, ThrowingConstantMethod},
            {VectorTemplate, "min", "", Template1, {}, ThrowingConstantMethod},
            {VectorTemplate,
             "max",
             "",
             Template1,
             {Argument{"default", Template1, ArgumentCategory::IN}},
             NoexceptConstantMethod},
            {VectorTemplate,
             "min",
             "",
             Template1,
             {Argument{"default", Template1, ArgumentCategory::IN}},
             NoexceptConstantMethod}};
    }

    auto constructStringOperators() -> Vector<Function>
    {
        return Vector<Function>{
            {String, "size", "", UInt64, {}, NoexceptConstantMethod},
            {String, "toI32", "", Int32, {}, ThrowingConstantMethod},
            {String, "toI64", "", Int64, {}, ThrowingConstantMethod},
            {String, "toU64", "", UInt64, {}, ThrowingConstantMethod},
            {String, "toF32", "", Float32, {}, ThrowingConstantMethod},
            {String, "toF64", "", Float64, {}, ThrowingConstantMethod},
            {String,
             "__at__",
             "",
             Char,
             {Argument{"index", UInt64, ArgumentCategory::IN}},
             ThrowingConstantMethod}};
    }

    auto constructFormattingFunctions() -> Vector<Function>
    {
        return Vector<Function>{
            {Void,
             "format",
             "",
             Void,
             {Argument{"fmt", String, ArgumentCategory::IN}},
             info::RuntimeOnlyNoexceptFunction,
             {}}};
    }

    auto constructOutputFunctions() -> Vector<Function>
    {
        return Vector<Function>{
            {Void,
             "putchar",
             "std::putchar",
             Void,
             {{"value", Int32, ArgumentCategory::IN}},
             FunctionInfo{.NOEXCEPT = true, .CONSTEXPR = false, .VISIBILITY = Visibility::PUBLIC}},
            {Void,
             "print",
             "",
             Void,
             {},
             FunctionInfo{
                 .NOEXCEPT = true,
                 .BUILTIN_FUNCTION = true,
                 .HAVE_PARAMETER_PACK = true,
                 .CONSTEXPR = false,
                 .VISIBILITY = Visibility::PUBLIC},
             {}},
        };
    }

    auto constructMathFunctions() -> Vector<Function>
    {
        return Vector<Function>{
            {Void,
             "sqrt",
             "std::sqrt",
             Float32,
             {Argument{"value", Float32, ArgumentCategory::IN}},
             ThrowingFunction,
             {},
             MagicFunctionType::NONE,
             builtinMathFunction<ccl::f32, std::sqrt>},
            {Void,
             "sqrt",
             "std::sqrt",
             Float64,
             {Argument{"value", Float64, ArgumentCategory::IN}},
             ThrowingFunction,
             {},
             MagicFunctionType::NONE,
             builtinMathFunction<ccl::f64, std::sqrt>},
            {Void,
             "log2",
             "std::log2",
             Float32,
             {Argument{"value", Float32, ArgumentCategory::IN}},
             ThrowingFunction,
             {},
             MagicFunctionType::NONE,
             builtinMathFunction<ccl::f32, std::log2>},
            {Void,
             "log2",
             "std::log2",
             Float64,
             {Argument{"log2", Float64, ArgumentCategory::IN}},
             ThrowingFunction,
             {},
             MagicFunctionType::NONE,
             builtinMathFunction<ccl::f64, std::log2>},
            {Void,
             "log",
             "std::log",
             Float32,
             {Argument{"value", Float32, ArgumentCategory::IN}},
             ThrowingFunction,
             {},
             MagicFunctionType::NONE,
             builtinMathFunction<ccl::f32, std::log>},
            {Void,
             "log",
             "std::log",
             Float64,
             {Argument{"value", Float64, ArgumentCategory::IN}},
             ThrowingFunction,
             {},
             MagicFunctionType::NONE,
             builtinMathFunction<ccl::f64, std::log>},
            {Void,
             "log",
             "",
             Float32,
             {Argument{"argument", Float32, ArgumentCategory::IN},
              Argument{"base", Float32, ArgumentCategory::IN}},
             ThrowingFunction,
             {},
             MagicFunctionType::NONE,
             builtinLogWithBase<ccl::f32, log>},
            {Void,
             "log",
             "",
             Float64,
             {Argument{"argument", Float64, ArgumentCategory::IN},
              Argument{"base", Float64, ArgumentCategory::IN}},
             ThrowingFunction,
             {},
             MagicFunctionType::NONE,
             builtinLogWithBase<ccl::f64, log>},
            {Void,
             "trunc",
             "std::trunc",
             Float32,
             {Argument{"value", Float32, ArgumentCategory::IN}},
             ThrowingFunction,
             {},
             MagicFunctionType::NONE,
             builtinMathFunction<ccl::f32, std::trunc>},
            {Void,
             "trunc",
             "std::trunc",
             Float64,
             {Argument{"value", Float64, ArgumentCategory::IN}},
             ThrowingFunction,
             {},
             MagicFunctionType::NONE,
             builtinMathFunction<ccl::f64, std::trunc>},
            {Void,
             "floor",
             "std::floor",
             Float32,
             {Argument{"value", Float32, ArgumentCategory::IN}},
             ThrowingFunction,
             {},
             MagicFunctionType::NONE,
             builtinMathFunction<ccl::f32, std::floor>},
            {Void,
             "floor",
             "std::floor",
             Float64,
             {Argument{"value", Float64, ArgumentCategory::IN}},
             ThrowingFunction,
             {},
             MagicFunctionType::NONE,
             builtinMathFunction<ccl::f64, std::floor>},
            {Void,
             "ceil",
             "std::ceil",
             Float32,
             {Argument{"value", Float32, ArgumentCategory::IN}},
             ThrowingFunction,
             {},
             MagicFunctionType::NONE,
             builtinMathFunction<ccl::f32, std::ceil>},
            {Void,
             "ceil",
             "std::ceil",
             Float64,
             {Argument{"value", Float64, ArgumentCategory::IN}},
             ThrowingFunction,
             {},
             MagicFunctionType::NONE,
             builtinMathFunction<ccl::f64, std::ceil>},
            {Void,
             "round",
             "std::round",
             Float32,
             {Argument{"value", Float32, ArgumentCategory::IN}},
             ThrowingFunction,
             {},
             MagicFunctionType::NONE,
             builtinMathFunction<ccl::f32, std::round>},
            {Void,
             "round",
             "std::round",
             Float64,
             {Argument{"value", Float64, ArgumentCategory::IN}},
             ThrowingFunction,
             {},
             MagicFunctionType::NONE,
             builtinMathFunction<ccl::f64, std::round>},
            {Void,
             "abs",
             "std::abs",
             Int32,
             {Argument{"value", Int32, ArgumentCategory::IN}},
             ThrowingFunction},
            {Void,
             "abs",
             "std::abs",
             Int64,
             {Argument{"value", Int64, ArgumentCategory::IN}},
             ThrowingFunction},
            {Void,
             "abs",
             "std::abs",
             Float32,
             {Argument{"value", Float32, ArgumentCategory::IN}},
             ThrowingFunction,
             {},
             MagicFunctionType::NONE,
             builtinMathFunction<ccl::f32, std::abs>},
            {Void,
             "abs",
             "std::abs",
             Float64,
             {Argument{"value", Float64, ArgumentCategory::IN}},
             ThrowingFunction,
             {},
             MagicFunctionType::NONE,
             builtinMathFunction<ccl::f64, std::abs>}};
    }

    auto initializeCompilerBuiltin() -> void
    {
        static auto initialized = false;
        static auto initialization_lock = std::mutex();

        if (initialized && !func::ReinitializeOnCompilation) {
            return;
        }

        auto lock = std::scoped_lock{initialization_lock};

        if (initialized && !func::ReinitializeOnCompilation) {
            return;
        }

        if (!initialized) {
            initializeTypes();
        }

        func::Functions.registerFunctions(
            {constructInt32Operators(), constructInt64Operators(), constructUInt32Operators(),
             constructUInt64Operators(), constructFloat32Operators(), constructFloat64Operators(),
             constructMathFunctions(), constructFormattingFunctions(), constructOutputFunctions(),
             constructVectorFunctions(), constructStringOperators()});

        initialized = true;
    }
}// namespace fsc::builtin

namespace fsc::func
{
    FunctionsHolder Functions{};
}