#include "type/builtin_types_impl.hpp"

namespace fsc
{
    FscBuiltinType<ReprOrValue<ccl::f32>>::FscBuiltinType(ReprOrValue<ccl::f32> initializer)
      : FscTypeInterface{FscFloat32::typeId}
      , value{std::move(initializer)}
    {}

    auto FscBuiltinType<ReprOrValue<ccl::f32>>::toString() const -> std::string
    {
        auto result = value.toString();

        if (!result.contains('.')) {
            result += ".0";
        }

        return result + "F";
    }

    auto FscBuiltinType<ReprOrValue<ccl::f32>>::getValue() const -> std::any
    {
        return {value};
    }

    FscBuiltinType<ReprOrValue<ccl::f64>>::FscBuiltinType(ReprOrValue<ccl::f64> initializer)
      : FscTypeInterface{FscFloat64::typeId}
      , value{std::move(initializer)}
    {}

    auto FscBuiltinType<ReprOrValue<ccl::f64>>::toString() const -> std::string
    {
        auto result = value.toString();

        if (!result.contains('.')) {
            result += ".0";
        }

        return result;
    }

    auto FscBuiltinType<ReprOrValue<ccl::f64>>::getValue() const -> std::any
    {
        return {value};
    }

    FscBuiltinType<FscChar>::FscBuiltinType(FscChar initializer)
      : FscTypeInterface{FscChar::typeId}
      , value{initializer}
    {}

    auto FscBuiltinType<FscChar>::toString() const -> std::string
    {
        return fmt::format("'{}'", value.value);
    }

    auto FscBuiltinType<FscChar>::getValue() const -> std::any
    {
        return {value};
    }

    FscBuiltinType<FscString>::FscBuiltinType(FscString initializer)
      : FscTypeInterface{FscString::typeId}
      , value{std::move(initializer)}
    {}

    auto FscBuiltinType<FscString>::toString() const -> std::string
    {
        return fmt::format("String{{{}}}", value.value);
    }

    auto FscBuiltinType<FscString>::getValue() const -> std::any
    {
        return {value};
    }

    FscBuiltinType<FscBool>::FscBuiltinType(FscBool initializer)
      : FscTypeInterface{FscBool::typeId}
      , value{initializer}
    {}

    auto FscBuiltinType<FscBool>::toString() const -> std::string
    {
        return fmt::to_string(value.value);
    }

    auto FscBuiltinType<FscBool>::getValue() const -> std::any
    {
        return {value};
    }
}// namespace fsc
