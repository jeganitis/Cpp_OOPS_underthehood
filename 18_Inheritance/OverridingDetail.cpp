#include <iostream>

/*--------------------------------------------------
  Base class (middleware abstraction)
--------------------------------------------------*/
class Transport {
public:
    int baseData = 0x10;

    virtual void send() const {
        std::cout << "Transport::send (generic)\n";
    }

    virtual ~Transport() = default;
};

/*--------------------------------------------------
  Derived class 1: CAN
--------------------------------------------------*/
class CanTransport : public Transport {
public:
    int canData = 0x20;

    void send() const override {
        std::cout << "CanTransport::send (CAN specific)\n";
    }
};

/*--------------------------------------------------
  Derived class 2: UART
--------------------------------------------------*/
class UartTransport : public Transport {
public:
    int uartData = 0x30;

    void send() const override {
        std::cout << "UartTransport::send (UART specific)\n";
    }
};

/*--------------------------------------------------
  Main
--------------------------------------------------*/
int main() {
    CanTransport can;
    UartTransport uart;

    Transport* t1 = &can;
    Transport* t2 = &uart;
	
	
    // Read vptr (first pointer in object)
    void** vptr1 = *(void***)&can;
    void** vptr2 = *(void***)&uart;

    std::cout << "CAN vptr  : " << vptr1 << "\n";
    std::cout << "UART vptr : " << vptr2 << "\n\n";

    std::cout << "Calling through base pointer (CAN):\n";
    t1->send();

    std::cout << "\nCalling through base pointer (UART):\n";
    t2->send();

    return 0;
}