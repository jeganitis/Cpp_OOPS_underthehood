#include <cstddef>

float sum_array(const float* data, size_t n) {
    float sum0 = 0, sum1 = 0, sum2 = 0, sum3 = 0;
    for (size_t i = 0; i < n; i += 4) {
        sum0 += data[i];
        sum1 += data[i+1];
        sum2 += data[i+2];
        sum3 += data[i+3];
    }
    return sum0 + sum1 + sum2 + sum3;
}