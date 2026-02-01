#include <cstdio>

volatile int sink;

void loop_with_volatile() {
    int sum = 0;

    for (int i = 0; i < 4; ++i) {
        sum += i;
        sink = sum;   // observable memory side effect
    }
}

int main() {
    loop_with_volatile();
    return 0;
}

