#include <iostream>
#include <string>
#include <variant>
#include <utility>

#include <catch2/catch.hpp>
#include <types/data.hxx>

using namespace std::literals;
using lix::core::types::Data;

TEST_CASE()
{
    int a = 1;
    double b = 3.14;
    std::string c {"hi"};

    Data d {a};
    std::cout << std::get<0>(d) << std::endl;

    d = b;
    std::cout << std::get<1>(d) << std::endl;

    d = c;
    std::cout << std::get<2>(d).c_str() << std::endl;

    using Var = std::variant<Data, char, float>;

    Var v { Data {b} };

    std::cout << std::get<1>(std::get<0>(v)) << std::endl;
}