#include "solver.h"
#include <cmath>
double solve(double a, double b, double c) {
    return (-b + std::sqrt(b*b - 4*a*c)) / (2*a);
}
