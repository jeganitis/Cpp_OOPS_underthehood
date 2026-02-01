#include <iostream>

class Counter
{
private:
    int count;   //internal state

public:
    Counter() : count(0) {}

    // Functor: function-call operator
    void operator()()
    {
        ++count;
    }

    int value() const
    {
        return count;
    }
};

int main()
{
    Counter c;   // Create Counter object

    // Call like a function
    c();  
    c();
    c();

    // Print current count
    std::cout << "Counter value: " << c.value() << std::endl;

    // More calls
    c();
    c();

    std::cout << "Counter value after more calls: " 
              << c.value() << std::endl;

    return 0;
}
