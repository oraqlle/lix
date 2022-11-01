#ifndef LIX_ENV
#   define LIX_ENV

#include <vector>

#include <types/expr.hxx>
#include <types/symbol.hxx>

namespace lix::core::types
{
    class Env 
    {
    private:
        std::vector<Symbol> syms;
        std::vector<Expr> exprs;
    };
}

#endif  // LIX_ENV