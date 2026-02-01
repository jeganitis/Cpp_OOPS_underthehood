#include <iostream>

int main()
{
    int arr[5]{10, 20, 30, 40, 50};

    std::cout << "Array values and addresses:\n\n";

    for (int i = 0; i < 5; i++)
    {
        std::cout << "arr[" << i << "] = "
                  << arr[i]
                  << "  address = "
                  << &arr[i]
                  << '\n';
    }

    return 0;
}