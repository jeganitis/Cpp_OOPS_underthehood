#include <iostream>

/*--------------------------------------------------
  Base interface (middleware abstraction)
--------------------------------------------------*/
class Transport {
public:
    virtual void send() const {
        std::cout << "Transport::send (generic)\n";
    }

    virtual ~Transport() = default;
};

/*--------------------------------------------------
  Derived implementation (CAN transport)
--------------------------------------------------*/
class CanTransport : public Transport {
public:
    void send() const override {
        std::cout << "CanTransport::send (CAN specific)\n";
    }
};

/*--------------------------------------------------
  BAD middleware API (takes base BY VALUE)
--------------------------------------------------*/
void transmit_bad(Transport t) {   // <-- object slicing happens here
    t.send();
}

/*--------------------------------------------------
  GOOD middleware API (takes base BY REFERENCE)
--------------------------------------------------*/
void transmit_good(const Transport& t) {
    t.send();
}

/*--------------------------------------------------
  Main
--------------------------------------------------*/
int main() {
    CanTransport can;

    std::cout << "Direct call:\n";
    can.send();

    std::cout << "\nPassing to bad middleware API:\n";
    transmit_bad(can);   // slicing

    std::cout << "\nPassing to good middleware API:\n";
    transmit_good(can);  // polymorphism preserved

    return 0;
}

