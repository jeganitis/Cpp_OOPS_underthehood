#include <iostream>

void print(int&& x) {   // takes rvalue reference
    std::cout << "Rvalue received: " << x << std::endl;
}

int main() {
    print(100);   // rvalue

    int a = 50;
    print(a);  //error (lvalue)

    return 0;
}
