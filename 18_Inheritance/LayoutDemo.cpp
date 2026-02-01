#include <iostream>
#include <iomanip>
#include <cstdint>

class Base {
public:
    virtual void foo() {
        std::cout << "Base::foo\n";
    }

    int baseData = 0x11111111;
};

class Derived : public Base {
public:
    int derivedData = 0x22222222;

    void foo() override {
        std::cout << "Derived::foo\n";
    }
};

int main() {
    Derived obj;

    Base* bptr = &obj;
    Derived* dptr = &obj;

    std::cout << std::hex << std::showbase;

    std::cout << "Address of obj        : " << &obj << '\n';
    std::cout << "Address via Base*     : " << bptr << '\n';
    std::cout << "Address via Derived*  : " << dptr << '\n';

    std::cout << "\n--- Data values ---\n";
    std::cout << "baseData              : " << obj.baseData << '\n';
    std::cout << "derivedData           : " << obj.derivedData << '\n';

    std::cout << "\n--- Virtual call ---\n";
    bptr->foo();   // runtime binding

    return 0;
}