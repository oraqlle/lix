#ifndef LIX_IO
#   define LIX_IO

#include <core/types/types.hxx>

using lix::core::types::Value;

namespace lix::core::io
{
    void print(const std::shared_ptr<Value>& val);


    void println(const std::shared_ptr<Value>& val);


    void print_expr(const std::shared_ptr<Value>& val, char open, char close);


    void print_str(const std::shared_ptr<Value>& val);
}

#endif  /// LIX_IO
