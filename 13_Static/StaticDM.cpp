#include <iostream>

class Driver
{
public:
    Driver()
    {
        instanceCount++;   // shared across all objects
    }

    static int getInstanceCount()
    {
        return instanceCount;
    }

private:
    static int instanceCount;  // shared data member
};

int Driver::instanceCount = 0;


int main()
{
    Driver d1;
    Driver d2;
    Driver d3;

    std::cout << "Number of Driver objects = "
              << Driver::getInstanceCount()
              << '\n';
	
	/*std::cout << "Number of Driver objects = "
              << d1.getInstanceCount()
              << '\n';*/

    return 0;
}
