
#include <iostream>
#include "Middleware.h"
int main() {
    std::cout << "--- C++ Middleware Example ---\n";
    Middleware mw;
    mw.processRequest("SensorDataRequest");
    return 0;
}
