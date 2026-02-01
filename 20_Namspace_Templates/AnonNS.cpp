#include <iostream>

//Anonymous namespace
namespace
{
    int helperCounter = 0;

    void helperFunction()
    {
        ++helperCounter;
        std::cout << "Helper called, count = "
                  << helperCounter << "\n";
    }
}

// Public function (visible outside this file)
void apiFunction()
{
    helperFunction();   // accessible here
}

int main()
{
    apiFunction();
    apiFunction();
    return 0;
}