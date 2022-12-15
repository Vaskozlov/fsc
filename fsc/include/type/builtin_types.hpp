#ifndef FSC_BUILTIN_TYPES_HPP
#define FSC_BUILTIN_TYPES_HPP

#include "uuid_factory.hpp"
#include <ccl/ccl.hpp>
#include <utility>

#define FSC_WRAP_TYPE(TypeName, StoredType)                                                        \
    class TypeName : public FscTypeWrapper<StoredType>                                             \
    {                                                                                              \
    public:                                                                                        \
        CCL_PERFECT_FORWARDING(FSC_T, StoredType)                                                  \
        TypeName(FSC_T &&initial_value)                                                            \
          : FscTypeWrapper{std::forward<FSC_T>(initial_value)}                                     \
        {}                                                                                         \
    }


namespace fsc
{
    inline UuidFactory TypeFactory{1};

    template<typename T>
    struct FscTypeWrapper;

    template<>
    struct FscTypeWrapper<void>
    {
        inline const static ccl::Id typeId = TypeFactory();
    };

    template<typename T>
    class FscTypeWrapper
    {
    public:
        inline const static ccl::Id typeId = TypeFactory();

        T value;

        FscTypeWrapper() = default;

        CCL_PERFECT_FORWARDING(U, T)
        explicit FscTypeWrapper(U &&initial_value)
          : value{std::forward<U>(initial_value)}
        {}
    };

    struct Void : FscTypeWrapper<void>
    {
    };

    FSC_WRAP_TYPE(Bool, bool);
    FSC_WRAP_TYPE(Int32, ccl::i32);
    FSC_WRAP_TYPE(UInt32, ccl::u32);
    FSC_WRAP_TYPE(Int64, ccl::i64);
    FSC_WRAP_TYPE(UInt64, ccl::u64);
    FSC_WRAP_TYPE(Float32, ccl::f32);
    FSC_WRAP_TYPE(Float64, ccl::f64);
}// namespace fsc

#endif /* FSC_BUILTIN_TYPES_HPP */
