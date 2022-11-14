#include <lix/lix.hxx>

#include <iostream>
#include <string>

using namespace lix::core;

int main(int argc, char* argv[])
{
    types::Env env = types::Env{};
    // lenv_add_builtins(e);
    // lval* p = load_prelude(e);

    if (argc == 1)
    {

        std::cout << "Lix v0.3.1\n";
        std::cout << "Press Ctrl+C to exit.\n";

        while(1)
        {
            char* input = readline("lix> ");

            add_history(input);

            int pos = 0;
            Value expr = read_expr(std::string{input}, pos, '\0');
            Value x = lval_eval(env, expr);
            io::println(x);

            free(input);
        }
    }

    return 0;
}
