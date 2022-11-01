#ifndef LIX_FUNCTION
#   define LIX_FUNCTION

#include <functional>
#include <vector>

#include <types/env.hxx>
#include <types/qexpr.hxx>
#include <types/expr.hxx>

namespace lix::core::types
{
    using BuiltinFunction = std::function<Expr(Env, Expr)>;

    class Lambda 
    {
    public:
        using Parameter         = typename Expr;
        using Body              = typename Expr;


        Expr operator() (Parameter params)
        {
            /// assert that params.cell == Qexpr
        }
    
    private:
        Parameter formals;
        Body body;
    };
}

#endif  /// LIX_FUNCTION