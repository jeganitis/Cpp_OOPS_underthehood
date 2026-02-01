#include <iostream>

class Demo {
public:
    Demo(int v) : x(v) {}

    /*Demo(const Demo& d) : x(d.x) {
        std::cout << "Copy constructor called\n";
    }*/

private:
    int x;
};

int main()
{
    Demo a(10);
    Demo b = a;   // copy constructor
}

