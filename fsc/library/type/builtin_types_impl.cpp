#include "type/builtin_types_impl.hpp"

namespace fsc
{
    FscBuiltinType<ReprOrValue<ccl::f32>>::FscBuiltinType(ReprOrValue<ccl::f32> initializer)
      : FscTypeInterface{FscFloat32::getTypeId()}
      , value{std::move(initializer)}
    {}

    auto FscBuiltinType<ReprOrValue<ccl::f32>>::toString() const -> std::string
    {
        auto result = value.toString();

        if (result.find('.') == std::string::npos) {
            result.append(".0");
        }

        result.push_back('F');
        return result;
    }

    auto FscBuiltinType<ReprOrValue<ccl::f32>>::getValue() const -> std::any
    {
        return {value};
    }

    FscBuiltinType<ReprOrValue<ccl::f64>>::FscBuiltinType(ReprOrValue<ccl::f64> initializer)
      : FscTypeInterface{FscFloat64::getTypeId()}
      , value{std::move(initializer)}
    {}

    auto FscBuiltinType<ReprOrValue<ccl::f64>>::toString() const -> std::string
    {
        auto result = value.toString();

        if (result.find('.') == std::string::npos) {
            result.append(".0");
        }

        return result;
    }

    auto FscBuiltinType<ReprOrValue<ccl::f64>>::getValue() const -> std::any
    {
        return {value};
    }

    FscBuiltinType<FscChar>::FscBuiltinType(FscChar initializer)
      : FscTypeInterface{FscChar::getTypeId()}
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
      : FscTypeInterface{FscString::getTypeId()}
      , value{std::move(initializer)}
    {}

    auto FscBuiltinType<FscString>::toString() const -> std::string
    {
        return fmt::format("String{{ {} }}", value.value);
    }

    auto FscBuiltinType<FscString>::getValue() const -> std::any
    {
        return {value};
    }

    FscBuiltinType<FscBool>::FscBuiltinType(FscBool initializer)
      : FscTypeInterface{FscBool::getTypeId()}
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
