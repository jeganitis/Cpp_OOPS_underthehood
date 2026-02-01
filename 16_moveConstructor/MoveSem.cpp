#include <iostream>
#include <cstring>
#include <utility>

class Buffer {
public:
    char* data;

    // Constructor
    Buffer(const char* msg) {
        data = new char[std::strlen(msg) + 1];
        std::strcpy(data, msg);
        std::cout << "Constructor\n";
    }

    // Copy constructor (deep copy)
    Buffer(const Buffer& other) {
        data = new char[std::strlen(other.data) + 1];
        std::strcpy(data, other.data);
        std::cout << "Copy Constructor\n";
    }

    // Move constructor (steal resource)
    Buffer(Buffer&& other) noexcept {
        data = other.data;
        other.data = nullptr;
        std::cout << "Move Constructor\n";
    }

    // Destructor
    ~Buffer() {
        delete[] data;
        std::cout << "Destructor\n";
    }
};

int main() {
    Buffer a("Hello");

    Buffer b = a;              // COPY (a is an lvalue)
    Buffer c = std::move(a);   // MOVE (a is cast to rvalue)

    return 0;
}