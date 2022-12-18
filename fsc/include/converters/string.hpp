#ifndef FSC_STRING_HPP
#define FSC_STRING_HPP

#include "ast/value.hpp"
#include "type/builtin_types_impl.hpp"

namespace fsc::converter
{
    auto toString(const std::string &repr) -> ccl::SharedPtr<ast::Value>;
}

#endif /* FSC_STRING_HPP */
