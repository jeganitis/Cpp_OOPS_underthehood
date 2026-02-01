#include <cstdint>
#include <cstring>
#include <iostream>

class Buffer {
public:
    size_t size;
    uint8_t* data;

    // Constructor
    Buffer(size_t s) : size(s), data(new uint8_t[s]) {
        std::cout << "Constructor: allocate " << size << " bytes\n";
        memset(data, 0xAA, size);
    }

    // Copy constructor (deep copy)
    Buffer(const Buffer& other)
        : size(other.size), data(new uint8_t[other.size]) {
        std::cout << "Copy Constructor: deep copy " << size << " bytes\n";
        memcpy(data, other.data, size);
    }

    // Destructor
    ~Buffer() {
        std::cout << "Destructor: free buffer\n";
        delete[] data;
    }
};

// Middleware RX API
Buffer receiveFrame() {
    Buffer rxBuf(1024);   // simulate CAN / SOME/IP payload
    return rxBuf;        // COPY (if elision disabled)
}

int main() {
    std::cout << "=== WITHOUT MOVE CONSTRUCTOR ===\n";
    Buffer appBuf = receiveFrame();  // copy construction
    return 0;
}


