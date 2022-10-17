#ifndef FSC_TYPES_HPP
#define FSC_TYPES_HPP

#include "builtin/uuid_factory.hpp"
#include <string>
#include <unordered_map>

namespace fsc {
    inline UuidFactory TypeFactory;

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

    struct Float {
        inline const static size_t hash = TypeFactory();
        float value;
    };

    struct Double {
        inline const static size_t hash = TypeFactory();
        double value;
    };

    struct FscValue {
        auto operator==(size_t other) const noexcept
        {
            return type == other;
        }

        auto operator==(const FscValue &other) const noexcept
        {
            return type == other.type;
        }

        static auto typeExists(const std::string &type_name) noexcept -> bool
        {
            return defined_types.contains(type_name);
        }

        static auto typeByName(const std::string &type_name) -> size_t
        {
            return defined_types.at(type_name);
        }

        static auto getTypename(size_t type) -> std::string
        {
            return typename_by_id.at(type);
        }

        static auto checkTypeExistence(const std::string &type_name) -> void
        {
            if (!typeExists(type_name)) {
                throw std::runtime_error("Type " + type_name +
                                         " does not exist or has not been declared yet");
            }
        }

    private:
        static inline std::unordered_map<std::string, size_t> defined_types{
                {"auto", Auto::hash}, {"i32", Int32::hash},  {"u32", UInt32::hash},
                {"i64", Int64::hash}, {"u64", UInt64::hash}, {"f32", Float::hash},
                {"f64", Double::hash}};

        static inline std::unordered_map<size_t, std::string> typename_by_id{
                {Auto::hash, "auto"}, {Int32::hash, "i32"},  {UInt32::hash, "u32"},
                {Int64::hash, "i64"}, {UInt64::hash, "u64"}, {Float::hash, "f32"},
                {Double::hash, "f64"}};

    public:
        std::any value;
        size_t type;
    };
}// namespace fsc

#endif /* FSC_TYPES_HPP */
