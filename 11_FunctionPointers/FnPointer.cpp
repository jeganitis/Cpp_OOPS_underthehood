#include <iostream>

int add(int a, int b)
{
    return a + b;
}

int main()
{
    int (*funcPtr)(int, int) = add;

    int result = funcPtr(2, 3);   // indirect call
    std::cout << result << '\n';  // 5
}