#ifndef LIX_EXPR
#   define LIX_EXPR

#include <core/types/types.hxx>

#include <span>
#include <vector>

namespace lix::core::types
{
    class Expr
    {
    public:
        Expr ()                                 = default;
        Expr (const Expr& expr)                 = default;
        Expr (Expr&& expr)                      = default;
        Expr& operator= (const Expr& expr)      = default;
        Expr& operator= (Expr&& expr)           = default;

        std::vector<Value> cells;
    };

    class Sexpr
    : public Expr
    {};

    class Qexpr
    : public Expr
    {};
}

#endif  /// LIX_EXPR