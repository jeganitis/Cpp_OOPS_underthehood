#include <iostream>

// Overloaded functions
void send(int id) {
    std::cout << "send(int)\n";
}

void send(int id, int priority) {
    std::cout << "send(int, int)\n";
}

int main() {
    send(10);        // calls send(int)
    send(10, 5);     // calls send(int, int)
}