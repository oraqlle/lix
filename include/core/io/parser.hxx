#ifndef LIX_PARSER
#   define LIX_PARSER

#include <core/types/types.hxx>
#include <core/types/expr.hxx>

#include <string_view>

using lix::core::types::Expr;

namespace lix::core::io
{

    std::pair<Expr, std::size_t> read_expr(std::string_view str, char endl);


    std::pair<Expr, std::size_t> read(std::string_view str);


    std::pair<Expr, std::size_t> read_sym(std::string_view str);


    char str_unescape(char x);


    std::string str_escape(char x);
}

#endif  // LIX_PARSER
