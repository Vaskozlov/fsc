#ifndef FSC_TYPE_HPP
#define FSC_TYPE_HPP

#include "codegen.hpp"
#include "fmt/format.h"
#include "function/signature.hpp"
#include <vector>

namespace fsc {
    using TypeId = size_t;

    namespace ast {
        class Node;
    };

    struct TypeFlags {
        bool isTriviallyCopyable : 1;
    };

    struct ValueOptions {
        bool constant : 1;
        bool compile_time_available : 1;
    };

    class FscType {
        static std::map<TypeId, std::string> typenameById;
        static std::map<std::string, TypeId> idByTypename;
        static std::map<TypeId, TypeFlags> typeFlags;
        static std::map<TypeId, std::map<std::string, TypeId>> typeMemberVariables;

        TypeId typeId;
        ValueOptions valueOptions;

    public:
        explicit FscType(const TypeId type_id, ValueOptions value_options);
        explicit FscType(const std::string &type_name, ValueOptions value_options);

        FscType(const FscType &other) = default;
        FscType(FscType &&other) noexcept = default;

        virtual ~FscType() = default;

        auto operator=(const FscType &other) -> FscType & = default;
        auto operator=(FscType &&other) noexcept -> FscType & = default;

        [[nodiscard]] virtual auto toString() const -> std::string = 0;
        virtual auto codeGen(gen::CodeGenerator &output) const -> void = 0;

        [[nodiscard]] static auto isTriviallyCopyable(const TypeId id) -> bool
        {
            return typeFlags[id].isTriviallyCopyable;
        }

        [[nodiscard]] auto getOptions() const noexcept -> ValueOptions
        {
            return valueOptions;
        }

        [[nodiscard]] auto is(const TypeId id) const noexcept -> bool
        {
            return id == getId();
        }

        template<std::derived_from<FscType> T>
        [[nodiscard]] auto as() -> T &
        {
            return static_cast<T &>(*this);
        }

        [[nodiscard]] auto getId() const noexcept -> TypeId
        {
            return typeId;
        }

        [[nodiscard]] auto getTypeName() const -> std::string
        {
            return FscType::getTypeName(getId());
        }

        [[nodiscard]] static auto exists(const TypeId type_id) -> bool
        {
            return typenameById.contains(type_id);
        }

        [[nodiscard]] static auto exists(const std::string &type_name) -> bool
        {
            return idByTypename.contains(type_name);
        }

        [[nodiscard]] static auto checkExistence(const std::string &type_name) -> void;

        [[nodiscard]] static auto getTypeId(const std::string &type_name) -> TypeId
        {
            return idByTypename.at(type_name);
        }

        [[nodiscard]] static auto getTypeName(const TypeId type_id) -> std::string
        {
            return typenameById.at(type_id);
        }

        static auto registerNewType(const std::string &name, const TypeFlags flags) -> void;
        static auto addMemberVariable(TypeId type_id, const std::string &name, TypeId variable_id) -> void;

        static auto hasMemberVariables(TypeId type_id, const std::string &name) -> bool;
        static auto getMemberVariable(TypeId type_id, const std::string &name) -> TypeId;
    };
}// namespace fsc

#endif /* FSC_TYPE_HPP */
