#include <iostream>

class Simple {
public:
    Simple() {
        std::cout << "Simple constructor\n";
    }

    ~Simple() {
        std::cout << "Simple destructor\n";
    }
};

int main()
{
    Simple s;
}