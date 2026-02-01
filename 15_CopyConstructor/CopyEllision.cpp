#include <iostream>

class Obj {
public:
    Obj() {
        std::cout << "Default Constructor\n";
    }

    Obj(const Obj&) {
        std::cout << "Copy Constructor\n";
    }

    ~Obj() {
        std::cout << "Destructor\n";
    }
};

Obj makeObj()
{
    Obj o;        // candidate for RVO
    return o;     // RVO may apply here
}

int main()
{
    Obj x = makeObj();
    return 0;
}

