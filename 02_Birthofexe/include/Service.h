#ifndef SERVICE_HPP
#define SERVICE_HPP

#include <string>

// Simulates a hardware or network service
class Service {
public:
    Service();
    std::string handle(const std::string& message);
};

#endif
