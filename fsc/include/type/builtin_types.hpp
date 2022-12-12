#ifndef FSC_BUILTIN_TYPES_HPP
#define FSC_BUILTIN_TYPES_HPP

#include "ccl/core/types.hpp"
#include "uuid_factory.hpp"

namespace fsc
{
    using float32 = ccl::f32;
    using float64 = ccl::f64;
    inline UuidFactory TypeFactory;

    struct Void
    {
        inline const static ccl::Id typeId = TypeFactory();
    };

    struct Int32
    {
        inline const static ccl::Id typeId = TypeFactory();
        int32_t value;
    };

    struct UInt64
    {
        inline const static ccl::Id typeId = TypeFactory();
        uint64_t value;
    };

    struct UInt32
    {
        inline const static ccl::Id typeId = TypeFactory();
        uint32_t value;
    };

    struct Int64
    {
        inline const static ccl::Id typeId = TypeFactory();
        int64_t value;
    };

    struct Float32
    {
        inline const static ccl::Id typeId = TypeFactory();
        float32 value;
    };

    struct Float64
    {
        inline const static ccl::Id typeId = TypeFactory();
        float64 value;
    };

    struct Bool
    {
        inline const static ccl::Id typeId = TypeFactory();
        bool value;
    };
}// namespace fsc

#endif /* FSC_BUILTIN_TYPES_HPP */
