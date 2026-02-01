#include <iostream>

class Settings {
public:
    Settings(int& ref, int val)
        : refValue(ref), constant(val)
    {
        std::cout << "Settings constructed\n";
    }

    ~Settings() {
        std::cout << "Settings destroyed\n";
    }

private:
    int& refValue;
    const int constant;
};


int main()
{
    int x = 10;   // Variable to bind the reference

    std::cout << "Before creating Settings\n";

    {
        Settings s(x, 42);   // refValue -> x, constant = 42

        std::cout << "Inside scope\n";
        std::cout << "x = " << x << "\n";
    } // Destructor called here (end of scope)

    std::cout << "After Settings destroyed\n";

    return 0;
}