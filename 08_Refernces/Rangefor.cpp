#include <iostream>

int main() {
    int arr[4] = {10, 20, 30, 40};

    for (int x : arr) {   // copy
        x += 5;           // modifies only local copy
    }

    // Original array unchanged
    for (int x : arr) {
        std::cout << x << " ";
    }
}
