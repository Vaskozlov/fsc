#ifndef FSC_CODEGEN_HPP
#define FSC_CODEGEN_HPP

#include <string>

namespace fsc::gen
{
    class CodeGenerator
    {
        std::string generated;
        std::string prefix;

    public:
        [[nodiscard]] auto getGenerated() const -> const std::string &
        {
            return generated;
        }

        [[nodiscard]] auto getBackInserter() -> std::back_insert_iterator<std::string>
        {
            return std::back_inserter(generated);
        }

        auto write(std::string_view str) -> void;
        auto write(const std::string &str) -> void;
        auto write(char chr) -> void;

        auto newLine() -> void;

        auto pushScope() -> void;
        auto popScope() -> void;

        auto openCurly() -> void;
        auto closeCurly() -> void;
    };
}// namespace fsc::gen

#endif /* FSC_CODEGEN_HPP */
