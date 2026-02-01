#include <iostream>

int main() {
    int arr[3] = {1, 2, 3};

    for (auto x : arr) {   // copy (auto → int)
        x *= 10;
    }

    for (auto x : arr) {
        std::cout << x << " ";
    }
}
