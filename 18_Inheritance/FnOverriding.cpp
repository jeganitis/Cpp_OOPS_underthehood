#include <iostream>

/*--------------------------------------------------
  Base class (interface / abstraction)
--------------------------------------------------*/
class Transport {
public:
    // Virtual function
    virtual void send() {
        std::cout << "Transport::send (generic)\n";
    }

    // Always make base destructor virtual
    virtual ~Transport() = default;
};

/*--------------------------------------------------
  Derived class (specific implementation)
--------------------------------------------------*/
class CanTransport : public Transport {
public:
    // Override base class function
    void send() override {
        std::cout << "CanTransport::send (CAN specific)\n";
    }
};

/*--------------------------------------------------
  Another derived class
--------------------------------------------------*/
class UartTransport : public Transport {
public:
    void send() override {
        std::cout << "UartTransport::send (UART specific)\n";
    }
};

/*--------------------------------------------------
  Application / Middleware usage
--------------------------------------------------*/
int main() {
    Transport* t1 = new CanTransport();
    Transport* t2 = new UartTransport();

    t1->send();   // runtime binding → CanTransport::send
    t2->send();   // runtime binding → UartTransport::send

    delete t1;
    delete t2;

    return 0;
}

