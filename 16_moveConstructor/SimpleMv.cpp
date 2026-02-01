#include <iostream>
#include <utility>

void func(int& x) {
    std::cout << "lvalue overload\n";
}

void func(int&& x) {
    std::cout << "rvalue overload\n";
}

int main() {
    int a = 10;

    func(a);             // a is lvalue
    func(std::move(a));  // a cast to rvalue

    return 0;
}

