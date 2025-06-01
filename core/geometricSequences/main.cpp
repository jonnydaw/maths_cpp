#include <ginac/ginac.h>
#include <iostream>

using namespace GiNaC;

//  g++ main.cpp -o main `pkg-config --cflags --libs ginac`
int main() {
    symbol x("x");
    ex expr = pow(x, 3) + 2*pow(x,2) + x + 1;

    std::cout << "Expression: " << expr << std::endl;

    // Derivative
    ex d = expr.diff(x);
    std::cout << "Derivative: " << d << std::endl;

    return 0;
}
