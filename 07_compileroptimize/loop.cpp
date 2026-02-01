int loop_no_printf() {
    int sum = 0;

    for (int i = 0; i < 4; ++i) {
        sum += i;
    }

    return sum;
}

int main() {
    return loop_no_printf();
}

