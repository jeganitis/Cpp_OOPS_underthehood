#pragma once
#include <cstdint>

namespace autosar::bsw::someip::service
{
    // SOME/IP payload abstraction
    struct SpeedRequest
    {
        uint16_t vehicleId;
    };

    struct SpeedResponse
    {
        uint16_t speedKmph;
    };

    // Service interface
    void init();
    SpeedResponse getSpeed(const SpeedRequest& req);
}