#include<iostream>
#include "math_utils.hpp"

int main() {
    int N = 1000;
    double val = heavyComputation(N);
    double sq = square(val);

    std::cout << "Result: " << val << std::endl;
    std::cout << "Squared result: " << sq << std::endl;
    return 0;
}
