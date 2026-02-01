#include <iostream>
#include <cstring>

class Buffer
{
private:
    int* data;
    size_t size;

public:
    // Constructor
    explicit Buffer(size_t s)
        : data(new int[s]), size(s)
    {
        std::cout << "Constructor\n";
    }

    // Destructor
    ~Buffer()
    {
        delete[] data;
        std::cout << "Destructor\n";
    }

    // Copy constructor
    Buffer(const Buffer& other)
        : data(new int[other.size]), size(other.size)
    {
        std::memcpy(data, other.data, size * sizeof(int));
        std::cout << "Copy Constructor\n";
    }

    // Copy assignment operator
    Buffer& operator=(const Buffer& other)
    {
        std::cout << "Copy Assignment\n";

        if (this != &other)
        {
            delete[] data;

            size = other.size;
            data = new int[size];
            std::memcpy(data, other.data, size * sizeof(int));
        }
        return *this;
    }

    // Move assignment operator
    Buffer& operator=(Buffer&& other) noexcept
    {
        std::cout << "Move Assignment\n";

        if (this != &other)
        {
            // Release current resource
            delete[] data;

            // Steal resource
            data = other.data;
            size = other.size;

            // Leave source in valid state
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }
};

int main()
{
    std::cout << "---- Constructor ----\n";
    Buffer a(5);                     // Constructor

    std::cout << "\n---- Copy Constructor ----\n";
    Buffer b = a;                    // Copy Constructor

    std::cout << "\n---- Copy Assignment ----\n";
    Buffer c(3);                     // Constructor
    c = a;                           // Copy Assignment

    std::cout << "\n---- Move Assignment ----\n";
    Buffer d(2);                     // Constructor
    d = Buffer(10);                  // Move Assignment

    std::cout << "\n---- End of main ----\n";
    return 0;
}