#include <core/io/parser.hxx>
#include <core/types/types.hxx>
#include <core/types/expr.hxx>
#include <core/utils/match.hxx>

#include <optional>
#include <string_view>
#include <tuple>
#include <utility>
#include <variant>

using namespace std::literals;

using lix::core::types::Cell;
using lix::core::types::Error;
using lix::core::types::Expr;
using lix::core::types::None;
using lix::core::types::Sexpr;
using lix::core::types::Symbol;

using lix::core::utils::match;

namespace lix::core::io
{
    std::pair<Expr, std::size_t> read_expr(std::string_view str, char endl)
    {
        Expr xexpr = Sexpr{};
        auto i = {0uL};

        while (str[i] != endl)
        {
            std::tie(yexpr, i) = read(s.substr(i));
            i = ni;

            if (std::holds_alternative<Error>(yexpr.cell))
                return std::make_pair(yexpr, i);
            else
                std::get<Sexpr>(xexpr.cell).push_pack(std::move(yexpr));
        }

        i++;

        return std::make_pair(xexpr, i);
    }


    std::pair<Expr, std::size_t> read(std::string_view str)
    {
        auto i = {0uL};
        while (strchr(" \t\v\r\n;", str[i]) && str[i] != '\0')
        {
            if (str[i] == ';')
                while (str[i] != '\n' && str[i] != '\0')
                    i++;
            i++;
        }

        Expr xexpr = None{};

        if (str[i] == '\0')
            return std::make_pair(Error{"Unexpected end of input"}, i);
        else if (str[i] == '(')
        {
            i++;
            std::tie(xexpr, i) = read_expr(str.substr(i), ')');
        }
        else if (strchr(
                "abcdefghijklmnopqrstuvwxyz"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "0123456789_+-*\\/=<>!&", str[i]))
            std::tie(xexpr, i) = read_sym(str.substr(i));
        else
            std::tie(xexpr, i) = Error{"Unexpected character "s + str[i]};

        while (strchr(" \t\v\r\n", str[i]) && str[i] != '\0')
        {
            if (str[i] == ';')
                while (str[i] != '\n' && str[i] != '\0')
                    i++;
            i++;
        }

        return std::make_pair(xexpr, i);
    }


    std::pair<Expr, std::size_t> read_sym(std::string_view str)
    {
        std::string part = "";
        auto i = {0uL};

        while (strchr(
            "abcdefghijklmnopqrstuvwxyz"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "0123456789_+-*\\/=<>!&", str[i]) && str[i] != '\0')
        {
            
            part += str[i];
            part += '\0';
            i++;
        }

        int is_num = strchr("-0123456789", part[0]) != NULL;

        for (char& chr : part)
            if (strchr("0123456789", chr) == NULL)
            {
                is_num = 0;
                break;
            }

        if (part.size() == 1 && part[0] == '-')
            is_num = 0;

        Expr xexpr = None{};

        if (is_num)
        {
            errno = 0;
            auto v = strtoi(part, NULL, 10);
            xexpr = (errno != ERANGE) ? Int{v} : Error{"Invalid Number "s + part};
        }
        else
            xexpr = Symbol{part};

        return std::make_pair(xexpr, i);
    }


    char str_unescape(char x) 
    {
        switch (x) 
        {
            case 'a':
                return '\a';
            case 'b':
                return '\b';
            case 'f':
                return '\f';
            case 'n':
                return '\n';
            case 'r':
                return '\r';
            case 't':
                return '\t';
            case 'v':
                return '\v';
            case '\\':
                return '\\';
            case '\'':
                return '\'';
            case '\"':
                return '\"';
        }

        return '\0';
    }


    std::string str_escape(char x)
    {
        switch (x) 
        {
            case '\a':
                return "\\a";
            case '\b':
                return "\\b";
            case '\f':
                return "\\f";
            case '\n':
                return "\\n";
            case '\r':
                return "\\r";
            case '\t':
                return "\\t";
            case '\v':
                return "\\v";
            case '\\':
                return "\\\\";
            case '\'':
                return "\\\'";
            case '\"':
                return "\\\"";
        }

        return "";
    }
}
