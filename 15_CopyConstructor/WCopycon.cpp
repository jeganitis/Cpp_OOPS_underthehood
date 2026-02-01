#include <iostream>

class Buffer {
public:
    Buffer(int value)
    {
        data = new int;
        *data = value;
        std::cout << "Constructor: data = " << *data << '\n';
    }

    // Copy constructor
    Buffer(const Buffer& other)
    {
        data = new int;
        *data = *other.data;
        std::cout << "Copy constructor: data = " << *data << '\n';
    }

    ~Buffer()
    {
        std::cout << "Destructor freeing data\n";
        delete data;
    }

private:
    int* data;
};

int main()
{
    Buffer b1(10);
    Buffer b2 = b1;   // Calls CopyCon

    return 0;
}