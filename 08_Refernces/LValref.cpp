
#include <iostream>

int main()
{
    int x = 10;      // x is an lvalue
    int& ref = x;    // ref is an lvalue reference to x

    std::cout << "Before change:\n";
    std::cout << "x   = " << x << '\n';
    std::cout << "ref = " << ref << '\n';

    // Modify through the reference
    ref = 20;

    std::cout << "\nAfter changing ref:\n";
    std::cout << "x   = " << x << '\n';
    std::cout << "ref = " << ref << '\n';

    std::cout << "\nAddresses:\n";
    std::cout << "&x   = " << &x << '\n';
    std::cout << "&ref = " << &ref << '\n';

    return 0;
}
