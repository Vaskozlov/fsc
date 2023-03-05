#ifndef FSC_STRING_HPP
#define FSC_STRING_HPP

#include "ast/value/value.hpp"
#include "type/builtin_types_impl.hpp"

namespace fsc::converter
{
    auto toChar(const std::string &repr, BasicContextPtr value_context)
        -> ccl::SharedPtr<ast::Value>;

    auto toString(const std::string &repr, BasicContextPtr value_context)
        -> ccl::SharedPtr<ast::Value>;
}// namespace fsc::converter

#endif /* FSC_STRING_HPP */
