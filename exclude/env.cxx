#include <core/builtins/arithmetic.hxx>

#include <core/env/env.hxx>

#include <core/types/expr.hxx>
#include <core/types/types.hxx>
#include <core/types/value.hxx>

#include <map>

using lix::core::types::Builtin;
using lix::core::types::Error;
using lix::core::types::Sexpr;
using lix::core::types::Symbol;
using lix::core::types::Value;

using lix::core::utils::match;

using namespace std::literals;

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

namespace lix::core::env
{
    Value eval(const Env& env, const Value& val)
    {
        return std::visit(match {
            [&](const Symbol& sym){ return env.syms.at(val); },
            [&](const Sexpr& expr){ return sexpr_eval(env, Value{expr}); },
            [](const auto& other){ return other; }
        }, val.value);
    }

    Value sexpr_eval(const Env& env, const Value& val)
    {
        for (auto& cell : val.value->cells)
            cell = eval(env, cell);

        for (auto& cell : val.value->cells)
        {
            std::optional<Value> opt = std::visit(match {
                [](const Error& err){ return err; },
                [](const auto& other){ return std::nullopt; }
            }, cell);

            if (opt.has_value())
                return *opt;
        }

        if (val.value->cells.size() == 0)
            return val;

        if (val.value->cells.size() == 1)
            return val.value->cells.pop(0);

        Value f = val.value->cells.pop(0);

        std::optional<Value> opt = std::visit(match {
            [](const Builtin& func){ return fun; },
            [](const auto& other){ return std::nullopt; }
        }, f.value);

        if (opt.has_value())
            return f.val(env, val);
        else
            return Error{"S-Expression starts with incorrect type.\nGot "s + f.value.name()
                                                                           + " Expected "s 
                                                                           + Value{Builtin{}}.name()
                                                                           + ". "};
    }

    void add_builtin(Env& env, std::string name, Builting func)
    {
        env.syms.insert(Symbol{name}, func)
    }

    void add_builtins(Env& env)
    {
        add_builtin(env, "+"s, func::add);
    }
}
