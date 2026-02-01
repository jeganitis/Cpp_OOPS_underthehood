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
        memset(data, 0xBB, size);
    }

    // Copy constructor (fallback)
    Buffer(const Buffer& other)
        : size(other.size), data(new uint8_t[other.size]) {
        std::cout << "Copy Constructor: deep copy " << size << " bytes\n";
        memcpy(data, other.data, size);
    }

    // Move constructor (ZERO COPY)
    Buffer(Buffer&& other) noexcept
        : size(other.size), data(other.data) {
        std::cout << "Move Constructor: steal buffer\n";
        other.size = 0;
        other.data = nullptr;
    }

    // Destructor
    ~Buffer() {
        std::cout << "Destructor: free buffer\n";
        delete[] data;
    }
};

// Middleware RX API
Buffer receiveFrame() {
    Buffer rxBuf(1024);
    return rxBuf;   // MOVE or elided
}

int main() {
    std::cout << "=== WITH MOVE CONSTRUCTOR ===\n";
    Buffer appBuf = receiveFrame();  // move construction
    return 0;
}