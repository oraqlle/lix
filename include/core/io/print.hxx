#ifndef LIX_PRINT
#   define LIX_PRINT

#include <core/types/types.hxx>
#include <core/utils/match.hxx>

using lix::core::types::None;
using lix::core::types::Expr;
using lix::core::types::Symbol;
using lix::core::types::Sexpr;
using lix::core::types::Function;
using lix::core::types::Cell;

using lix::core::utils::match;

using namespace std::literals;

namespace lix::core::io
{   
    template<typename Stream>
    Stream& operator<< (Stream& os, const Expr& expr)
    {
        std::visit(match {
            [&](const None& none){ os << "None"; },
            [&](const Int& num){ os << num; },
            [&](const Symbol& sym){ os << sym; },
            [&](const Sexpr& exp){ os << expr; },
        }, expr.cell)
        return os;
    }

    template<typename Stream>
    Stream& operator<< (Stream& os, const Sexpr& sexpr)
    {
        os << "( "
        for (const auto& expr : sexp)
            os << expr->cell << ' ';
        os << ")"
        return os;
    }
}

#endif  /// LIX_PRINT
