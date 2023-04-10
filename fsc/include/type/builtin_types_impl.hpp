#ifndef FSC_BUILTIN_TYPES_IMPL_HPP
#define FSC_BUILTIN_TYPES_IMPL_HPP

#include "type/builtin_types.hpp"
#include "type/type.hpp"
#include <fmt/format.h>

namespace fsc
{
    template<typename T>
    concept FscIntegral = ccl::IsSameToAny<T, FscBool, FscInt32, FscInt64, FscUInt32, FscUInt64>;

    template<typename T>
    concept FscFloatingPoint = ccl::IsSameToAny<T, FscFloat32, FscFloat64>;

    template<typename T>
    class FscBuiltinType;

    template<FscIntegral Int>
    class FscBuiltinType<Int> : public FscTypeInterface
    {
    private:
        Int value;

    public:
        explicit FscBuiltinType(Int initializer)
          : FscTypeInterface{Int::getTypeId()}
          , value{initializer}
        {}

        [[nodiscard]] auto toString() const -> std::string final
        {
            return fmt::format("{}", value.value);
        }

        auto codeGen(ccl::codegen::BasicCodeGenerator &output) -> void final
        {
            output << value.value;
        }

        [[nodiscard]] auto getValue() const -> std::any final
        {
            return std::any{value};
        }
    };

    template<>
    class FscBuiltinType<ReprOrValue<ccl::f32>> : public FscTypeInterface
    {
        ReprOrValue<ccl::f32> value;

    public:
        explicit FscBuiltinType(ReprOrValue<ccl::f32> initializer);

        [[nodiscard]] auto toString() const -> std::string final;
        [[nodiscard]] auto getValue() const -> std::any final;
    };

    template<>
    class FscBuiltinType<ReprOrValue<ccl::f64>> : public FscTypeInterface
    {
        ReprOrValue<ccl::f64> value;

    public:
        explicit FscBuiltinType(ReprOrValue<ccl::f64> initializer);

        [[nodiscard]] auto toString() const -> std::string final;
        [[nodiscard]] auto getValue() const -> std::any final;
    };

    template<>
    class FscBuiltinType<VoidType> : public FscTypeInterface
    {
    public:
        explicit FscBuiltinType()
          : FscTypeInterface{VoidType::getTypeId()}
        {}

        [[nodiscard]] auto toString() const -> std::string final
        {
            return "void";
        }

        [[nodiscard]] auto getValue() const -> std::any final
        {
            return {};
        }
    };

    template<>
    class FscBuiltinType<FscChar> : public FscTypeInterface
    {
        FscChar value;

    public:
        explicit FscBuiltinType(FscChar initializer);

        [[nodiscard]] auto toString() const -> std::string final;
        [[nodiscard]] auto getValue() const -> std::any final;
    };

    template<>
    class FscBuiltinType<FscString> : public FscTypeInterface
    {
        FscString value;

    public:
        explicit FscBuiltinType(FscString initializer);

        [[nodiscard]] auto toString() const -> std::string final;
        [[nodiscard]] auto getValue() const -> std::any final;
    };

    template<>
    class FscBuiltinType<FscBool> : public FscTypeInterface
    {
        FscBool value;

    public:
        explicit FscBuiltinType(FscBool initializer);

        [[nodiscard]] auto toString() const -> std::string final;
        [[nodiscard]] auto getValue() const -> std::any final;
    };
}// namespace fsc

#endif /* FSC_BUILTIN_TYPES_IMPL_HPP */
