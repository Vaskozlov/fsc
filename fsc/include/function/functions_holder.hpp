#ifndef FSC_FUNCTIONS_HPP
#define FSC_FUNCTIONS_HPP

#include "ast/function/function.hpp"
#include "function/argument.hpp"
#include "type/type.hpp"
#include <ccl/core/types.hpp>
#include <list>

namespace fsc::func
{
    enum struct FunctionFindFailure : ccl::u32
    {
        NO_FUNCTIONS_WITH_THE_SAME_NAME,
        NO_FUNCTIONS_WITH_THE_SAME_PARAMETERS
    };

    inline constinit bool ReinitializeOnCompilation = false;

    class FunctionsHolder
    {
    private:
        using FunctionsList = std::list<ccl::SharedPtr<ast::Function>>;
        using FunctionsByNameMap = ccl::Map<std::string, FunctionsList>;
        using FunctionByClassIdMap = ccl::Map<FscType, FunctionsByNameMap>;

        FunctionByClassIdMap functions;
        ccl::Map<FscType, FscType> superclassFromSelf;

    public:
        FunctionsHolder();

        FunctionsHolder(ccl::InitializerList<ccl::Vector<ast::Function>> functions_);

        auto map(FscType base, FscType derived) -> void
        {
            superclassFromSelf.emplace(derived, base);
        }

        [[nodiscard]] auto cleanupType(FscType type) const -> FscType
        {
            if (superclassFromSelf.contains(type)) {
                return superclassFromSelf.at(type);
            }

            return type;
        }

        auto registerFunction(ccl::SharedPtr<ast::Function> function) -> void;

        CCL_PERFECT_FORWARDING(T, ast::Function)
        auto registerFunction(T &&function) -> void
        {
            return registerFunction(ccl::makeShared<ast::Function>(std::forward<T>(function)));
        }

        auto registerFunctions(ccl::Vector<ccl::Vector<ast::Function>> &&functions_) -> void
        {
            for (auto &line : functions_) {
                for (auto &function : line) {
                    registerFunction(std::move(function));
                }
            }
        }

        [[nodiscard]] auto get(SignatureView signature) const -> ccl::SharedPtr<ast::Function>;

        [[nodiscard]] auto
            get(const std::string &name, const ccl::SmallVector<Argument> &arguments) const
            -> ccl::SharedPtr<ast::Function>;

    private:
        auto appendFunction(ccl::SharedPtr<ast::Function> &function, FscType class_type) noexcept(
            false) -> void;

        [[nodiscard]] auto findFunction(SignatureView signature) const ->
            typename FunctionsList::const_iterator;

        [[nodiscard]] auto findMagicFunction(SignatureView signature) const ->
            typename FunctionsList::const_iterator;

        [[nodiscard]] auto checkMagicFunctionOrReturnFailure(
            SignatureView signature, FunctionFindFailure failure_type) const ->
            typename FunctionsList::const_iterator;

        [[noreturn]] static auto
            throwUnableToFindFunctionWithGivenName(SignatureView signature) noexcept(false) -> void;

        [[noreturn]] static auto
            throwUnableToFindFunctionWithGivenParameters(SignatureView signature) noexcept(false)
                -> void;
    };

    extern FunctionsHolder Functions;
}// namespace fsc::func

#endif /* FSC_FUNCTIONS_HPP */
