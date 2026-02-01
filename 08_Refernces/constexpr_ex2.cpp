#include <cstdint>
#include <iostream>

//#define SCALE_FACTOR 0.1

constexpr uint32_t SCALE_FACTOR{0.1};

int main()
{
    uint32_t delay = 33 * SCALE_FACTOR;

    std::cout << "Delay = " << delay << std::endl;
    return 0;
}