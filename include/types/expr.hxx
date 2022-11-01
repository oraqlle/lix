#ifndef LIX_EXPR
#   define LIX_EXPR

#include <memory>
#include <optional>
#include <variant>
#include <vector>

#include <types/data.hxx>
// #include <types/env.hxx>
#include <types/error.hxx>
// #include <types/function.hxx>
#include <types/qexpr.hxx>
#include <types/sexpr.hxx>
#include <types/symbol.hxx>

namespace lix::core::types
{
    class Expr
    {
    public:
        using Cell = typename std::variant<std::monostate,
                                           Data, 
                                           Error, 
                                           Symbol, 
                                           Qexpr,
                                           Sexpr>;


        Expr() = delete;

        Expr(const Expr& other) = default;

        Expr(Expr&& other) = default;

        explicit Expr(Data data)
        : cell{ Data{ data } }
        // , env{ std::nullopt }
        , children{ std::nullopt }
        {};

    private:
        Cell cell;
        // std::optional<Env> env;
        std::optional<std::vector<Cell>> children;
    };
}

#endif  // LIX_EXPR
