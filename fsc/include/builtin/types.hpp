#ifndef FSC_TYPES_HPP
#define FSC_TYPES_HPP

#include "builtin/uuid_factory.hpp"
#include <any>
#include <fmt/core.h>
#include <string>
#include <unordered_map>

namespace fsc {
    inline UuidFactory TypeFactory;

    using float32 = float;
    using float64 = double;

    struct Auto {
        inline const static size_t hash = TypeFactory();
    };

    struct Int32 {
        inline const static size_t hash = TypeFactory();
        int32_t value;
    };

    struct UInt64 {
        inline const static size_t hash = TypeFactory();
        uint64_t value;
    };

    struct UInt32 {
        inline const static size_t hash = TypeFactory();
        uint32_t value;
    };

    struct Int64 {
        inline const static size_t hash = TypeFactory();
        int64_t value;
    };

    struct Float32 {
        inline const static size_t hash = TypeFactory();
        float32 value;
    };

    struct Float64 {
        inline const static size_t hash = TypeFactory();
        float64 value;
    };

    class FscValue {
    public:
        FscValue() = default;

        explicit FscValue(int32_t value_) : value(value_), type(Int32::hash)
        {}

        explicit FscValue(int64_t value_) : value(value_), type(Int64::hash)
        {}

        explicit FscValue(uint32_t value_) : value(value_), type(UInt32::hash)
        {}

        explicit FscValue(uint64_t value_) : value(value_), type(UInt64::hash)
        {}

        explicit FscValue(float32 value_) : value(value_), type(Float32::hash)
        {}

        explicit FscValue(float64 value_) : value(value_), type(Float64::hash)
        {}

        FscValue(const std::any &value_, const size_t type_) : value(value_), type(type_)
        {}

        FscValue(std::any &&value_, const size_t type_) : value(std::move(value_)), type(type_)
        {}

        friend auto operator==(const FscValue &lhs, const size_t rhs) noexcept
        {
            return lhs.type == rhs;
        }

        friend auto operator==(const FscValue &lhs, const FscValue &rhs) noexcept
        {
            return lhs.type == rhs.type;
        }

        auto toString() const -> std::string;

        static auto typeExists(const std::string &type_name) noexcept -> bool
        {
            return definedTypes.contains(type_name);
        }

        static auto typeByName(const std::string &type_name) -> size_t
        {
            return definedTypes.at(type_name);
        }

        static auto getTypename(const size_t type) -> std::string
        {
            return typenameById.at(type);
        }

        static auto checkTypeExistence(const std::string &type_name) -> void;

    private:
        static std::unordered_map<std::string, size_t> definedTypes;
        static std::unordered_map<size_t, std::string> typenameById;

    public:
        std::any value;
        size_t type;
    };
}// namespace fsc

#endif /* FSC_TYPES_HPP */
