//pass By Value

#include <iostream>

struct Buffer {
    int data[5];
};

void processByValue(Buffer buf)
{
    std::cout << "[processByValue]\n";
    std::cout << "  Address of buf        : " << &buf << '\n';
    std::cout << "  Address of buf.data[0]: " << &buf.data[0] << '\n';

    buf.data[0] = 77;   // modifies copy only
}

int main()
{
    Buffer b = {{1, 2, 3, 4, 5}};

    std::cout << "[main]\n";
    std::cout << "  Address of b          : " << &b << '\n';

    processByValue(b);

    std::cout << "After processByValue: " << b.data[0] << '\n';
    return 0;
}