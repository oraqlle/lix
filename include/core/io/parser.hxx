#ifndef LIX_PARSER
#   define LIX_PARSER

#include <core/types/types.hxx>

#include <string>

using lix::core::types::Value;

namespace lix::core::parser
{

    Value lval_read_expr(std::string str, int& i, char endl);


    Value lval_read(std::string str, int& i);


    Value read_str(std::string str, int& i);


    Value read_sym(std::string str, int& i);


    char str_unescape(char x);


    std::string str_escape(char x);
}

#endif  // LIX_PARSER
