#include <stdint.h>

#ifndef C_DRIVER_H
#define C_DRIVER_H


#ifdef __cplusplus
extern "C" {
#endif

void Can_Send(uint32_t id, const uint8_t* data, uint8_t len);

#ifdef __cplusplus
}
#endif

#endif