#ifndef MATH_UTILS_HPP
#define MATH_UTILS_HPP

#include <iostream>

// Macro to control debug printing
#ifdef DEBUG
    #define DEBUG_PRINT(x) std::cout << "[DEBUG] " << x << std::endl;
#else
    #define DEBUG_PRINT(x)
#endif

// Simple inline function
inline double square(double x) {
    return x * x;
}

// Function declaration (defined in .cpp)
double heavyComputation(int n);

#endif // MATH_UTILS_HPP
