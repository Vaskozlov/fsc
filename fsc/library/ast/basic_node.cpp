#include "ast/basic_node.hpp"
#include "type/type.hpp"
#include <ccl/handler/cmd_handler.hpp>
#include <Token.h>

using namespace ccl;
using namespace std::string_literals;
using namespace std::string_view_literals;

namespace fsc::ast
{
    std::string SourceFile;
    ccl::Vector<std::string> SourceLines;

    static auto operator*(std::string_view str, size_t repeat) -> std::string
    {
        auto result = std::string{};
        result.reserve(str.size() * repeat);

        for (size_t i = 0; i != repeat; ++i) {
            result.append(str);
        }

        return result;
    }

    Node::Node(
        NodeType node_type, SemicolonNeed need_semicolon, BasicContextPtr node_context) noexcept
      : context{node_context}
      , nodeType{node_type}
      , needSemicolon{need_semicolon}
    {}

    auto Node::setNodeType(NodeType node_type) noexcept -> void
    {
        nodeType = node_type;
    }

    auto Node::setSemicolonNeed(SemicolonNeed need_semicolon) noexcept -> void
    {
        needSemicolon = need_semicolon;
    }

    auto Node::getStart() const noexcept -> ccl::Optional<antlr4::Token *>
    {
        if (start == nullptr) {
            return std::nullopt;
        }

        return start;
    }

    auto Node::getStop() const noexcept -> ccl::Optional<antlr4::Token *>
    {
        if (stop == nullptr) {
            return std::nullopt;
        }

        return stop;
    }

    auto Node::getContext() const noexcept -> ccl::Optional<BasicContextPtr>
    {
        if (context == nullptr) {
            return std::nullopt;
        }

        return context;
    }

    auto Node::getPrintingPrefix(const std::string &prefix, bool is_left) -> std::string
    {
        if (is_left) {
            return prefix + "\u251c\u2500\u2500";
        }

        return prefix + "\u2514\u2500\u2500";
    }

    auto Node::expandPrefix(const std::string &prefix, bool is_left, size_t extra_expansion)
        -> std::string
    {
        static constexpr auto default_printing_shift = "   "sv;

        auto result = prefix + (is_left ? "\u2502   " : "    ");
        result.append(default_printing_shift * extra_expansion);

        return result;
    }

    auto Node::reportAboutError(const std::exception &exception) const -> void
    {
        if (start == nullptr || stop == nullptr) {
            throw exception;
        }

        const auto line = start->getLine();
        const auto begin_column = start->getCharPositionInLine();
        const auto end_column = stop->getCharPositionInLine();

        auto &handler = ccl::handler::Cmd::instance();
        auto location = ccl::text::Location{SourceFile, line, begin_column};
        auto length = end_column - begin_column + stop->getText().size();

        auto iterator_exception = ccl::text::TextIteratorException{
            ccl::ExceptionCriticality::PANIC,
            ccl::AnalysisStage::PARSING,
            location,
            length,
            SourceLines.at(location.getLine() - 1),
            exception.what(),
            ""};

        handler.handle(iterator_exception);
        std::exit(1);// NOLINT
    }

    auto Node::getValueType() noexcept(false) -> FscType
    {
        throw std::runtime_error{"getValueType() is not implemented"};
    }

    auto Node::optimize(OptimizationLevel /* unused */) -> void
    {}

    auto operator<<(codegen::BasicCodeGenerator &generator, Node &node)
        -> codegen::BasicCodeGenerator &
    {
        node.codeGen(generator);
        return generator;
    }
}// namespace fsc::ast
