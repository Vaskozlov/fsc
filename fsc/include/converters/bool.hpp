#ifndef FSC_BOOL_HPP
#define FSC_BOOL_HPP

#include "ast/value/value.hpp"
#include "type/builtin_types_impl.hpp"

namespace fsc::converter
{
    auto toBoolean(const std::string &repr) -> ccl::SharedPtr<ast::Value>;
}

#endif /* FSC_BOOL_HPP */
