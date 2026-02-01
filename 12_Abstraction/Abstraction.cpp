#include <iostream>
#include <cstdint>

class Device {
public:
    explicit Device(uint32_t id) : id_(id), state_(0) {}

    void init()
    {
        state_ = 1;
        std::cout << "Device " << id_ << " initialized\n";
    }

    uint32_t read() const
    {
        std::cout << "Reading device " << id_ << '\n';
        return state_;
    }

    void write(uint32_t value)
    {
        state_ = value;
        std::cout << "Writing " << value << " to device " << id_ << '\n';
    }

private:
    uint32_t id_;
    uint32_t state_;
};


int main()
{
    Device dev1(1);

    dev1.init();
    dev1.write(42);
    uint32_t val = dev1.read();

    std::cout << "Value read = " << val << '\n';
}

