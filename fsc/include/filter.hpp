#ifndef FSC_FILTER_HPP
#define FSC_FILTER_HPP

#include <antlr4-runtime.h>
#include <ranges>

namespace fsc::filter
{
    constexpr auto comma = std::views::filter([](antlr4::tree::ParseTree *elem) {
        const auto text = elem->getText();
        return !text.empty() && text[0] != ',';
    });

    constexpr auto newline = std::views::filter([](antlr4::tree::ParseTree *elem) {
        const auto text = elem->getText();
        return !text.empty() && text[0] != '\n';
    });
}// namespace fsc::filter

#endif /* FSC_FILTER_HPP */
