#include "c_driver.h"
#include <stdio.h>
#include <stdint.h>

void Can_Send(uint32_t id, const uint8_t* data, uint8_t len) {
    printf("C Driver: ID=%u, LEN=%u\n", id, len);
}