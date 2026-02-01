//Constructor initializer list

#include <iostream>

class Config {
public:
    Config(int v) : value(v) {
        std::cout << "Config constructed\n";
    }

    ~Config() {
        std::cout << "Config destroyed\n";
    }

private:
    int value;
};

int main()
{
    Config c(5);
}