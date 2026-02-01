#include <iostream>

void cmdStart()  { std::cout << "Start\n"; }
void cmdStop()   { std::cout << "Stop\n"; }
void cmdReset()  { std::cout << "Reset\n"; }

int main()
{
    // Array of function pointers
    void (*commandTable[3])() = {
        cmdStart,
        cmdStop,
        cmdReset
    };

    int cmd = 2;  // runtime decision
    commandTable[cmd]();  // calls cmdStop()
}
