#include <iostream>

void rxHandler(int id, int length)
{
    std::cout << "Msg ID: " << id << " Len: " << length << '\n';
}

void driverReceive(void (*cb)(int, int))
{
    // Simulate reception
    cb(0x123, 8);
}

int main()
{
    driverReceive(rxHandler);
}