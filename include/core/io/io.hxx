#ifndef LIX_IO
#   define LIX_IO

#include <core/types/types.hxx>

using lix::core::types::Value;

namespace lix::core::io
{
    void print(const Value& val);


    void println(const Value& val);


    void print_expr(const Value& val, char open, char close);


    void print_str(const Value& val);
}

#endif  /// LIX_IO
