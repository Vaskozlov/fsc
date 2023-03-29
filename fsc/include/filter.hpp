#ifndef FSC_FILTER_HPP
#define FSC_FILTER_HPP

#include <antlr4-runtime.h>
#include <range/v3/view.hpp>

namespace fsc::filter
{
    namespace detail
    {
        inline auto filterForCharacter(antlr4::tree::ParseTree *elem, char character) -> bool
        {
            const auto text = elem->getText();
            return !text.empty() && text[0] != character;
        }
    }// namespace detail

    constexpr auto comma = ranges::views::filter([](antlr4::tree::ParseTree *elem) {
        return detail::filterForCharacter(elem, ',');
    });

    constexpr auto newline = ranges::views::filter([](antlr4::tree::ParseTree *elem) {
        return detail::filterForCharacter(elem, '\n');
    });
}// namespace fsc::filter

#endif /* FSC_FILTER_HPP */
