#include <iostream>

/*--------------------------------------------------
  Base class
--------------------------------------------------*/
class Transport {
public:
    Transport() {
        std::cout << "Transport constructed\n";
    }

    // Virtual destructor
    virtual ~Transport() {
        std::cout << "Transport destroyed\n";
    }
};

/*--------------------------------------------------
  Derived class
--------------------------------------------------*/
class CanTransport : public Transport {
public:
    CanTransport() {
        std::cout << "CanTransport constructed\n";
    }

    ~CanTransport() {
        std::cout << "CanTransport destroyed\n";
    }
};

/*--------------------------------------------------
  Main
--------------------------------------------------*/
int main() {
    Transport* t = new CanTransport();
    delete t;   // correct destruction
    return 0;
}

