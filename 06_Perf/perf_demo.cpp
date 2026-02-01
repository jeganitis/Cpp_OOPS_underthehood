#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

constexpr size_t DATA_SIZE = 50 * 1024 * 1024; // ~50M integers

// CPU-bound workload
void cpu_bound_task() {
    volatile double result = 0.0;
    for (int i = 0; i < 100'000'000; ++i) {
        result += std::sin(i) * std::cos(i);
    }
}

// Memory-bound workload
void memory_bound_task() {
    std::vector<int> data(DATA_SIZE, 1);
    long long sum = 0;
    for (size_t i = 0; i < data.size(); ++i) {
        sum += data[i];
    }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    cpu_bound_task();
    memory_bound_task();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Execution time: " << elapsed.count() << " seconds\n";
    return 0;
}

