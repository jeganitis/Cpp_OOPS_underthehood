#include <iostream>

int* createArray(int n)
{
    // heap allocation
    int* p = new int[n];

    // write some values
    for(int i = 0; i < n; ++i)
        p[i] = i;

    return p;  // memory returned, but not deleted by caller: leak
}

int main()
{
    int* arr = createArray(10);

    // use some values
    std::cout << "arr[5] = " << arr[5] << std::endl;

    // intentionally forget to free/delete memory
    // delete[] arr;   // <-- commented to trigger leak

    return 0;  // leak happens here
}


