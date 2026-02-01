#include "SpeedService.hpp"
#include <iostream>

int main()
{
    autosar::bsw::someip::service::init();

    autosar::bsw::someip::service::SpeedRequest req{42};
    auto resp = autosar::bsw::someip::service::getSpeed(req);

    std::cout << "Vehicle speed = "
              << resp.speedKmph << " km/h\n";

    return 0;
}