#ifndef LIX_EXPR
#   define LIX_EXPR

#include <optional>
#include <vector>

#include <core/types/types.hxx>

namespace lix::core::types
{
    class Expr
    {
    public:

        enum class ExprType : short
        { Sexpr, Qexpr };

        using Children          = std::vector<Value>;

    public:
        Expr()                              = default;
        Expr(const Expr& expr)              = default;
        Expr(Expr&& expr)                   = default;
        Expr& operator= (const Expr& expr)  = default;
        Expr& operator= (Expr&& expr)       = default;
        ~Expr()                             = default;

    private:
        ExprType type;
        Value val;
        Children children;
        std::optional<Env> env;
    };
}

#endif  /// LIX_EXPR
