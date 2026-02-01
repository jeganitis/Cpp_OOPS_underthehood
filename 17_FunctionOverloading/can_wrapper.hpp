#include <cstdint>
#include "c_driver.h"

// C++ middleware-friendly type
struct CanFrame {
    uint32_t id;
    uint8_t  data[8];
    uint8_t  len;
};

// Overload #1: raw parameters
inline void send(uint32_t id,
                 const uint8_t* data,
                 uint8_t len)
{
    Can_Send(id, data, len);
}

// Overload #2: strongly typed frame
inline void send(const CanFrame& frame)
{
    Can_Send(frame.id, frame.data, frame.len);
}