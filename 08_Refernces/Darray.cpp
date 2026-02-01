#include <iostream>
#include <cstdint>

int main()
{
    std::cout << "Allocating dynamic array...\n";

    // Dynamic array allocated on heap
    uint32_t* arr = new uint32_t[5];

    // Initialize and print values + addresses
    for (int i = 0; i < 5; ++i)
    {
        arr[i] = (i + 1) * 10;
        std::cout << "arr[" << i << "] = "
                  << arr[i]
                  << "  address = "
                  << &arr[i]
                  << '\n';
    }

    std::cout << "\nReassigning pointer WITHOUT deleting old memory...\n";

    // MEMORY LEAK:
    // Original memory is lost — no pointer refers to it anymore
    arr = new uint32_t[3];

    for (int i = 0; i < 3; ++i)
    {
        arr[i] = (i + 1) * 100;
        std::cout << "new arr[" << i << "] = "
                  << arr[i]
                  << "  address = "
                  << &arr[i]
                  << '\n';
    }

    // Only deletes second allocation
    delete[] arr;

    std::cout << "\nProgram ends.\n";
    return 0;
}

