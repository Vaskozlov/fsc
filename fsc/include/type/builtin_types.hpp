#ifndef FSC_BUILTIN_TYPES_HPP
#define FSC_BUILTIN_TYPES_HPP

#include "uuid_factory.hpp"

namespace fsc {
    using TypeId = size_t;
    using float32 = float;
    using float64 = double;
    inline UuidFactory TypeFactory;

    struct Void {
        inline const static TypeId typeId = TypeFactory();
    };

    struct Int32 {
        inline const static TypeId typeId = TypeFactory();
        int32_t value;
    };

    struct UInt64 {
        inline const static TypeId typeId = TypeFactory();
        uint64_t value;
    };

    struct UInt32 {
        inline const static TypeId typeId = TypeFactory();
        uint32_t value;
    };

    struct Int64 {
        inline const static TypeId typeId = TypeFactory();
        int64_t value;
    };

    struct Float32 {
        inline const static TypeId typeId = TypeFactory();
        float32 value;
    };

    struct Float64 {
        inline const static TypeId typeId = TypeFactory();
        float64 value;
    };

    struct Bool {
        inline const static TypeId typeId = TypeFactory();
        bool value;
    };
}// namespace fsc

#endif /* FSC_BUILTIN_TYPES_HPP */
