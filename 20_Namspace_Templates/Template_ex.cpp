#include <iostream>
#include <cstdint>

// CAN message
struct CanMessage
{
    uint32_t id;
};

// SOME/IP message
struct SomeIpMessage
{
    uint16_t serviceId;
};


// Generic middleware utility
template <typename MessageT>
void forwardMessage(const MessageT&)
{
    std::cout << "Forwarding middleware message\n";
}


int main()
{
    CanMessage canMsg{0x123};
    SomeIpMessage someIpMsg{1001};

    forwardMessage(canMsg);     // works
    forwardMessage(someIpMsg);  // works

    return 0;
}