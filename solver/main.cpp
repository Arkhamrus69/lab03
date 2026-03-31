#include "formatter_ex.h"
#include "solver.h"
#include <iostream>
int main() {
    double result = solve(1, -3, 2);
    formatter(std::cout, "Root: " + std::to_string(result));
    return 0;
}
