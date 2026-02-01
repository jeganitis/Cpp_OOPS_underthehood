#include <iostream>
#include <cstdint>

// Forward declaration
struct Device;

// Function pointer typedefs
typedef void     (*InitFn)(struct Device*);
typedef uint32_t (*ReadFn)(struct Device*);
typedef void     (*WriteFn)(struct Device*, uint32_t);

// Struct acting like an object
struct Device {
    uint32_t id;
    uint32_t state;

    InitFn  init;
    ReadFn  read;
    WriteFn write;
};


void deviceInit(struct Device* dev)
{
    dev->state = 1;
    std::cout << "Device " << dev->id << " initialized\n";
}

uint32_t deviceRead(struct Device* dev)
{
    std::cout << "Reading device " << dev->id << '\n';
    return dev->state;
}

void deviceWrite(struct Device* dev, uint32_t value)
{
    dev->state = value;
    std::cout << "Writing " << value << " to device " << dev->id << '\n';
}


int main()
{
    struct Device dev1 = {
        1,               // id
        0,               // state
        deviceInit,      // init
        deviceRead,      // read
        deviceWrite      // write
    };

    dev1.init(&dev1);                 // like dev1.init()
    dev1.write(&dev1, 42);             // like dev1.write(42)
    uint32_t val = dev1.read(&dev1);   // like dev1.read()

    std::cout << "Value read = " << val << '\n';
    return 0;
}
