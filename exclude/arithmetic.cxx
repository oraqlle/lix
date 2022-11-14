#include <core/builtins/arithmetic.hxx>
#include <core/types/types.hxx>
#include <core/types/value.hxx>

#include <core/utils/match.hxx>

#include <optional>
#include <string>
#include <variant>

using lix::core::types::Builtin;
using lix::core::types::Env;
using lix::core::types::Error;
using lix::core::types::Int;
using lix::core::types::Symbol;
using lix::core::types::Sexpr;
using lix::core::types::Value;

using lix::core::utils::match;

using namespace std::literals;

namespace lix::core::func
{
    Value builtin_op(const Env& env, Value& arg, const Value& op)
    {
        for (auto& cell : std::get<Sexpr>(arg.value).cells)
        {
            static_assert(decltype(std::get<Int>(cell.value)) == Int,
                          "Function "s + op.name()
                                       + " passed incorrect type for for argument. Got "s
                                       + cell.name()
                                       + " , Expected "
                                       + Value{Int}.name()
                                       +"."s);
        }

        Value x = std::get<Sexpr>(arg.value).cells.pop_front();

        if (std::get<Symbol>(op.value) == "-" && std::get<Sexpr>(arg.value).cells.size() == 0)
            arg = Value{Int{-std::get<Symbol>(op.value)}};

        while (std::get<Sexpr>(arg.value).cells.size() > 0)
        {
            Value y = std::get<Sexpr>(arg.value).cells.pop_front();

            switch (std::get<Symbol>(op.value))
            {
            case "+"s:
                x.value += y.value;
                break;
            
            case "-"s:
                x.value -= y.value;
                break;

            case "*"s:
                x.value *= y.value;
                break;

            case "/"s:
                if (y.value == 0)
                    x.value = Error{"Division by Zero"};
                else
                    x.value /= y.value;

                break;
            
            default:
                break;
            }
        }

        return x;
    }

    Value add(const Env& env, Value& val)
    { return builtin_op(env, val, Symbol{"+"}); }
}