#include <cstdint>
#include <iostream>

class CanDriver
{
public:
    CanDriver()
        : initCount(0)
    {
        std::cout << "CanDriver constructor\n";
    }

    void init()
    {
        initCount++;
        std::cout << "CanDriver init called, count = "
                  << initCount << '\n';
    }

private:
    uint32_t initCount;
};

void canInit()
{
    static CanDriver driver;   //static object (persistent)
    driver.init();
}

int main()
{
    std::cout << "First call\n";
    canInit();

    std::cout << "Second call\n";
    canInit();

    std::cout << "Third call\n";
    canInit();

    return 0;
}
