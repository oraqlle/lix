#ifndef LIX_ENV
#   define LIX_ENV

#include <core/utils/match.hxx>
#include <core/types/types.hxx>
#include <core/types/value.hxx>

#include <variant>

using lix::core::types::Env;
using lix::core::types::Value;

namespace lix::core::env
{
    Value eval(const Env& env, const Value val);

    Value sexpr_eval(const Env& env, const std::shared_ptr<Value>& val);

    void add_builtin(Env& env);

    void add_builtins(Env& env);
}

#endif  /// LIX_ENV
