#ifndef LIX_ENV
#   define LIX_ENV

#include <map>
#include <memory>
#include <string>

#include <core/types/types.hxx>
#include <core/types/expr.hxx>
#include <core/types/value.hxx>
#include <core/utils/match.hxx>

using lix::core::utils::match;

namespace lix::core::types
{
    class Env
    {
    public:
        Env ()                              = default;
        Env (const Env& env)                = default;
        Env (Env&& env)                     = default;
        Env& operator= (const Env& env)     = default;
        Env& operator= (Env&& env)          = default;
        ~Env ()                             = default;

    public:
        std::map<Value, Value> syms;
        std::shared_ptr<Env> parent;
    };
}

#endif  /// LIX_ENV
