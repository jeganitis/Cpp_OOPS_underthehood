#include <iostream>
#include <string>
#include <cstdint>

int main()
{
    std::string s1 = "Hello";
    std::string s2 = "This string is definitely longer than fifteen";

    std::cout << "Address of s1 object     : " << &s1 << '\n';
    std::cout << "Address of s1 data()     : " << static_cast<const void*>(s1.data()) << '\n';

    std::cout << "\n";

    std::cout << "Address of s2 object     : " << &s2 << '\n';
    std::cout << "Address of s2 data()     : " << static_cast<const void*>(s2.data()) << '\n';

    return 0;
}