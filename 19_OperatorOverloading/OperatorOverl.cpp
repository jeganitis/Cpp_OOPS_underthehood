#include <cstdint>
#include <cstring>
#include <iostream>

class CanFrame
{
public:
    uint32_t id;
    uint8_t  dlc;
    uint8_t  data[8];

    CanFrame(uint32_t canId, uint8_t len, const uint8_t* payload)
        : id(canId), dlc(len)
    {
        std::memcpy(data, payload, dlc);
    }

    // Operator overloading for filtering / comparison
    bool operator==(const CanFrame& other) const
    {
        if (id != other.id || dlc != other.dlc)
            return false;

        return std::memcmp(data, other.data, dlc) == 0;
    }
};

bool filterFrame(const CanFrame& rxFrame)
{
    uint8_t expectedPayload[8] = {10, 20, 30, 40, 0, 0, 0, 0};
    CanFrame expectedFrame(0x100, 4, expectedPayload);

    // Operator overload used here
    if (rxFrame == expectedFrame)
    {
        return true;   // Frame accepted
    }

    return false;      // Frame rejected
}

int main()
{
    uint8_t rxPayload1[8] = {10, 20, 30, 40, 0, 0, 0, 0};
    uint8_t rxPayload2[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    CanFrame rxFrame1(0x100, 4, rxPayload1);
    CanFrame rxFrame2(0x200, 8, rxPayload2);

    if (filterFrame(rxFrame1))
        std::cout << "Frame 1 accepted\n";
    else
        std::cout << "Frame 1 rejected\n";

    if (filterFrame(rxFrame2))
        std::cout << "Frame 2 accepted\n";
    else
        std::cout << "Frame 2 rejected\n";

    return 0;
}