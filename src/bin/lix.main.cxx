#include <lix/lix.hxx>

#include <iostream>
#include <string>

using namespace lix::core;

int main(int argc, char* argv[])
{
    types::Env env = types::Env{};
    env::add_builtins(e);
    // lval* p = load_prelude(e);

    if (argc == 1)
    {

        std::cout << "Lix v0.3.1\n";
        std::cout << "Press Ctrl+C to exit.\n";
        std::string input;

        while(std::getline(std::cin, input) && input != "quit")
        {
            Value expr = parser::read_expr(input);
            Value x = env::eval(env, expr);
            io::println(x);
        }
    }

    return 0;
}
