#include <cstdint>
#include <iostream>

constexpr uint32_t TIMEOUT_MS {1};

//#define TIMEOUT_MS -1

uint32_t startTimer(uint32_t timeout)
{
    return timeout;
}

int main()
{
    uint32_t value = startTimer(TIMEOUT_MS);

    std::cout << "Timeout value = " << value << std::endl;
    return 0;
}


