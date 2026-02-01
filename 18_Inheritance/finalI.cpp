#include <iostream>

/*--------------------------------------------------
  Base class
--------------------------------------------------*/
class Transport {
public:
    virtual void send() const {
        std::cout << "Transport::send\n";
    }

    virtual ~Transport() = default;
};

/*--------------------------------------------------
  Derived class with FINAL virtual function
--------------------------------------------------*/
class CanTransport final : public Transport {
public:
    void send() const override final {
        std::cout << "CanTransport::send\n";
    }
};

//Further Override
class CanMgr : public CanTransport {
public:
    void send() const override final {
        std::cout << "CanMgr::send\n";
    }
};

/*--------------------------------------------------
  Function that uses base pointer
--------------------------------------------------*/
void process(const Transport* t) {
    t->send();   // candidate for devirtualization
}

/*--------------------------------------------------
  Main
--------------------------------------------------*/
int main() {
    CanTransport can;
    process(&can);
    return 0;
}