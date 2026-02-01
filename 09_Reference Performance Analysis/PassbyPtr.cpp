//pass by pointers

#include <iostream>

struct Buffer {
    int data[5];
};

void processByPointer(Buffer* buf)
{
    std::cout << "[processByPointer]\n";

    // Mandatory null check
    if (buf == nullptr) {
        std::cout << "  ERROR: buf is null!\n";
        return;
    }

    std::cout << "  Address stored in buf : " << buf << '\n';
    std::cout << "  Address of buf->data[0]: " << &buf->data[0] << '\n';

    buf->data[0] = 55;
}

int main()
{
    Buffer b = {{1, 2, 3, 4, 5}};

    processByPointer(&b);
    std::cout << "After processByPointer: " << b.data[0] << '\n';

    // Demonstrate null case
    processByPointer(nullptr);

    return 0;
}