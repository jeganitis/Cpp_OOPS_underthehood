#include <iostream>

class Counter {
public:
    void increment() {
        value++;          // allowed
    }

    int get() const {
        return value;     // allowed
    }

private:
    int value = 0;        // hidden data
};

int main()
{
    Counter c;

    c.increment();        // allowed (public)
    int x = c.get();      // allowed (public)

    c.value = 10;      //ERROR (private)
}
