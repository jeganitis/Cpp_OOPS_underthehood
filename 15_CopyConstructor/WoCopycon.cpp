#include <iostream>

class Buffer {
public:
    Buffer(int value)
    {
        data = new int;
        *data = value;
        std::cout << "Constructor: data = " << *data << '\n';
    }

    ~Buffer()
    {
        std::cout << "Destructor freeing data\n";
        delete data;
    }

private:
    int* data;   // owns heap memory
};

int main()
{
    Buffer b1(10);
    Buffer b2 = b1;   //shallow copy

    return 0;
}