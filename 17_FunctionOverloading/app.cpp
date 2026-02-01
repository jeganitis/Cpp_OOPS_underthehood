#include "can_wrapper.hpp"

int main() {
    uint8_t rawData[8] = {1,2,3,4,5,6,7,8};

    send(0x100, rawData, 8);   // overload #1

    CanFrame frame {0x200, {9,8,7,6}, 4};
    send(frame);               // overload #2

    return 0;
}

