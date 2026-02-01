#include <iostream>

/*--------------------------------------------------
  Base class (Middleware device abstraction)
--------------------------------------------------*/
class Device {
public:
    void start() {
        status = 1;
        std::cout << "Device started\n";
    }

    int getStatus() const {
        return status;
    }

protected:
    // Accessible only to derived classes
    int status = 0;

    void updateStatus(int s) {
        status = s;
    }

private:
    int errorCount = 0;

    void resetErrors() {
        errorCount = 0;
        std::cout << "Errors reset\n";
    }

    // Friend gives full access (private + protected)
    friend class DeviceManager;
};

/*--------------------------------------------------
  Derived class (uses protected, no overriding)
--------------------------------------------------*/
class CanDevice : public Device {
public:
    void sendFrame() {
        // Accessing protected member
        updateStatus(2);
        std::cout << "CAN frame sent, status = " << status << "\n";
    }
};

/*--------------------------------------------------
  Friend class (trusted middleware component)
--------------------------------------------------*/
class DeviceManager {
public:
    void recover(Device& dev) {
        // Accessing private members via friendship
        dev.resetErrors();
        dev.status = 0;
        std::cout << "Device recovered by manager\n";
    }
};

/*--------------------------------------------------
  Application
--------------------------------------------------*/
int main() {
    DeviceManager manager;
    CanDevice can;

    can.start();
    can.sendFrame();

    std::cout << "Status before recovery: " << can.getStatus() << "\n";

    manager.recover(can);

    std::cout << "Status after recovery: " << can.getStatus() << "\n";
    return 0;
}