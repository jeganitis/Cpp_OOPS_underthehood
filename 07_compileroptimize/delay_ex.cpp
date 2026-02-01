#include <cstdint>

void delay_1ms() {
    
    for (uint64_t i = 0; i < 1'000'000ULL; ++i) {
       
    }
}

int main() {
    delay_1ms();
    return 0;
}
