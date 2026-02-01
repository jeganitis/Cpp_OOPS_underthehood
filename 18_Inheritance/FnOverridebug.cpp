#include <iostream>

/*--------------------------------------------------
  Base class
--------------------------------------------------*/
class Base {
public:
    virtual void foo() const {
        std::cout << "Base::foo() const\n";
    }

    virtual ~Base() = default;
};

/*--------------------------------------------------
  Derived class (BUG HERE)
--------------------------------------------------*/
class Derived : public Base {
public:
    //Missing 'const' → signature mismatch
    void foo() override{
        std::cout << "Derived::foo()\n";
    }
};

/*--------------------------------------------------
  Main
--------------------------------------------------*/
int main() {
    Derived d;
    Base* b = &d;

    std::cout << "Calling via Derived object:\n";
    d.foo();   // calls Derived::foo()

    std::cout << "\nCalling via Base pointer:\n";
    b->foo();  //EXPECTED: Derived::foo()
    // ACTUAL:   Base::foo()

    return 0;
}