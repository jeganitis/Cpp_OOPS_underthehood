//Parameterized constructor


#include <iostream>

class Device {
public:
    Device(int id) {
        deviceId = id;
        std::cout << "Device constructed, id=" << deviceId << '\n';
    }

    ~Device() {
        std::cout << "Device destroyed, id=" << deviceId << '\n';
    }

private:
    int deviceId;
};

int main()
{
    Device d1(10);
}