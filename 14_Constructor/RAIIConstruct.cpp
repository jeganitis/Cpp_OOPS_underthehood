//Destructor and resource cleanup (RAII)
#include <iostream>

class Resource {
public:
    Resource() {
        data = new int[10];
        std::cout << "Resource acquired\n";
    }

    ~Resource() {
        delete[] data;
        std::cout << "Resource released\n";
    }

private:
    int* data;
};

int main()
{
    Resource r;
}