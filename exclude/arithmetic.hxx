#ifndef LIX_ARITHMETIC
#   define LIX_ARITHMETIC

#include <core/types/types.hxx>

using lix::core::types::Value;
using lix::core::types::Env;

namespace lix::core::func
{
    Value builtin_op(const Env& env, Value& arg, const Value& op);

    Value add(const Env& env, Value& val);
}

#endif  /// LIX_ARITHMETIC