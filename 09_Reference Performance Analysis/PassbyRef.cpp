//Pass By Reference

#include <iostream>

struct Buffer {
    int data[5];
};

void processByRef(Buffer& buf)
{
    std::cout << "[processByRef]\n";
    std::cout << "  Address of buf        : " << &buf << '\n';
    std::cout << "  Address of buf.data[0]: " << &buf.data[0] << '\n';

    buf.data[0] = 99;
}

int main()
{
    Buffer b = {{1, 2, 3, 4, 5}};

    std::cout << "[main]\n";
    std::cout << "  Address of b          : " << &b << '\n';
    std::cout << "  Address of b.data[0]  : " << &b.data[0] << '\n';

    processByRef(b);

    std::cout << "After processByRef: " << b.data[0] << '\n';
    return 0;
}