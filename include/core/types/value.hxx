#ifndef LIX_VALUE
#   define LIX_VALUE

#include <memory>
#include <optional>
#include <queue>
#include <variant>
#include <vector>

#include <core/types/types.hxx>
#include <core/types/expr.hxx>
#include <core/utils/match.hxx>

using lix::core::utils::match;

namespace lix::core::types
{
    class Value
    {
    public:
        using Type = std::variant<  
                                    std::monostate,
                                    Int,
                                    Float,
                                    String,
                                    Error, 
                                    Symbol,
                                    Comment,
                                    Builtin,
                                    Sexpr,
                                    Qexpr
                                  >;

    public:
        Value ()                               = delete;

        Value (const Value& value)             = default;
        Value (Value&& value)                  = default;
        Value& operator= (const Value& value)  = default;
        Value& operator= (Value&& value)       = default;

        explicit Value(std::monostate&& mon)
        : value{mon}
        {}

        explicit Value(Int&& num)
        : value{Int{num}}
        {}

        explicit Value(Float&& fnum)
        : value{Float{fnum}}
        {}

        explicit Value(String&& str)
        : value{String{str}}
        {}

        explicit Value(Error&& err)
        : value{Error{err}}
        {}

        explicit Value(Symbol&& sym)
        : value{Symbol{sym}}
        {}

        explicit Value(Comment&& com)
        : value{Comment{com}}
        {}

        explicit Value(Builtin&& fun)
        : value{Builtin{fun}}
        {}

        explicit Value(Sexpr&& expr)
        : value{Sexpr{expr}}
        {}

        explicit Value(Qexpr&& expr)
        : value{Qexpr{expr}}
        {}

        std::string name() const
        {
            using namespace std::literals;

            return std::visit(match {
                [](const Int& num){ return "Int"s; },
                [](const Float& num){ return "Float"s; },
                [](const String& num){ return "String"s; },
                [](const Error& num){ return "Error"s; },
                [](const Symbol& num){ return "Symbol"s; },
                [](const Builtin& num){ return "Function (built-in)"s; },
                [](const Sexpr& num){ return "S-expression"s; },
                [](const Qexpr& num){ return "Q-expression"s; }
            }, this->value);
        }

    public:
        Type value;
        std::optional<Env> env;
    };
}

#endif  /// LIX_VALUE
