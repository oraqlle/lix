#include <core/utils/match.hxx>
#include <core/parser/parser.hxx>

#include <core/types/types.hxx>
#include <core/types/value.hxx>

#include <errno.h>
#include <optional>
#include <string>
#include <variant>

using namespace std::literals;

using lix::core::types::Value;
using lix::core::types::Error;
using lix::core::types::Sexpr;
using lix::core::types::Qexpr;

using lix::core::utils::match;

namespace lix::core::parser
{
    Value read_expr(const std::string& str, int& i, char endl)
    {
        Value x = (endl == '}') ? Qexpr{} : Sexpr{};

        while (str[i] != endl)
        {
            Value y = read(str, i);

            std::optional<Value> opt = std::visit(match{
                [](const Error& err){ return err; },
                [&](const Sexpr& expr)
                {
                    std::get<Sexpr>(x.value).cells.push_back(std::move(y));
                    return std::nullopt;
                },
                [&](const Qexpr& expr)
                {
                    std::get<Qexpr>(x.value).cells.push_back(std::move(y));
                    return std::nullopt;
                },
                [](const auto& other){ return std::nullopt; }
            });

            if (opt.has_value())
                return opt.value();            
        }

        i++;

        return x;
    }


    Value read(std::string str, int& i)
    {
        while (strchr(" \t\v\r\n;", s[i]) && s[i] != '\0')
        {
            if (s[i] == ';')
                while (s[i] != '\n' && s[i] != '\0')
                    i++;

            i++;
        }

        Value x = std::monostate;

        if (s[i] == '\0')
            return Error{"Unexpected end of input"};
        else if (s[i] == '(')
        {
            (i)++;
            x = read_expr(s, i, ')');
        }
        else if (s[i] == '{')
        {
            (i)++;
            x = read_expr(s, i, '}');
        }
        else if (strchr(
                "abcdefghijklmnopqrstuvwxyz"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "0123456789_+-*\\/=<>!&", s[i]))
            x = read_sym(s, i);
        else if (strchr("\"", s[i]))
            x = read_str(s, i);
        else
            x = Error{"Unexpected character "s + s[i]};

        while (strchr(" \t\v\r\n", s[i]) && s[i] != '\0')
        {
            if (s[i] == ';')
                while (s[i] != '\n' && s[i] != '\0')
                    (i)++;

            (i)++;
        }

        return x;
    }


    Value read_str(std::string str, int& i)
    {
        std::string part = {""};

        (i)++;

        while (s[i] != '"')
        {
            char c = s[i];

            if (c == '\0')
            {
                return Error{"Unexpected end of input"};
            }

            if (c == '\\')
            {
                (i)++;

                if (strchr("abfnrtv\\\'\"", s[i]))
                    c = str_unescape(s[i]);
                else
                {
                    return Error{"Invalid escape sequence \\"s + s[i]};
                }
            }

            
            part += c;
            part += '\0';
            (i)++;
        }

        (i)++;

        Value x = String{part};

        return x;
    }


    Value read_sym(std::string str, int& i)
    {
        std::string part = {""};

        while (strchr(
            "abcdefghijklmnopqrstuvwxyz"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "0123456789_+-*\\/=<>!&", s[i]) && s[i] != '\0')
        {
            
            part += s[i];
            part += '\0';
            i++;
        }

        int is_num = strchr("-0123456789", part[0]) != NULL;

        for (int j = 1; j < strlen(part); j++)
            if (strchr("0123456789", part[j]) == NULL)
            {
                is_num = 0;
                break;
            }

        if (strlen(part) == 1 && part[0] == '-')
            is_num = 0;

        Value x = std::monostate;

        if (is_num)
        {
            errno = 0;
            long v = strtoi(part, NULL, 10);
            x = (errno != ERANGE) ? Int{v} : Error{"Invalid Number "s + part};
        }
        else
            x = Symbol{part};

        return x;
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
