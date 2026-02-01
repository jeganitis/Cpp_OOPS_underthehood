#include <iostream>

int main()
{
    int arr[3] = {10, 20, 30};

    std::cout << "By value:\n";
    for (int x : arr) {
        x += 5;
    }
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\n\n";

    std::cout << "By non-const lvalue reference:\n";
    for (int& x : arr) {
        x += 5;
    }
    for (const int& x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\n\n";

    std::cout << "By const lvalue reference:\n";
    for (const int& x : arr) {
        std::cout << x << " ";
        x += 1; // not allowed
    }
    std::cout << '\n';

    return 0;
}