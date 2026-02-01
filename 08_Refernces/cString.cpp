#include <iostream>
#include <cstring>
#include <cstdlib>

int main()
{
    // C-style string allocated on HEAP
    char* s1 = (char*)std::malloc(6);   // "Hello" + '\0'
    std::strcpy(s1, "Hello");

    char* s2 = (char*)std::malloc(50);
    std::strcpy(s2, "This string is definitely longer than fifteen");

    std::cout << "Address of s1 pointer  : " << &s1 << '\n';
    std::cout << "Address of s1 data     : " << static_cast<void*>(s1) << '\n';

    std::cout << "\n";

    std::cout << "Address of s2 pointer  : " << &s2 << '\n';
    std::cout << "Address of s2 data     : " << static_cast<void*>(s2) << '\n';

    std::free(s1);
    std::free(s2);
}