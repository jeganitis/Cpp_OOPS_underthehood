#include "SpeedService.hpp"
#include <iostream>

namespace autosar::bsw::someip::service
{
    void init()
    {
        std::cout << "[SOME/IP] Speed Service initialized\n";
    }

    SpeedResponse getSpeed(const SpeedRequest& req)
    {
        std::cout << "[SOME/IP] Request for Vehicle ID = "
                  << req.vehicleId << "\n";

        // Dummy response (simulating middleware logic)
        SpeedResponse resp;
        resp.speedKmph = 80;

        return resp;
    }
}