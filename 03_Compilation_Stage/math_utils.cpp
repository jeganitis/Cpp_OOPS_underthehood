
#include "math_utils.hpp"
#include <cmath>

// A function that can be optimized differently based on compiler level
double heavyComputation(int n) {
    double result = 0.0;
    for (int i = 0; i < n * 1000; ++i) {
        result += std::sin(i) * std::cos(i / 2.0);
    }
    DEBUG_PRINT("Computation done with n = " << n);
    return result;
}
