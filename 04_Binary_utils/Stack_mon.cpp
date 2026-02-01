// example.cpp

// A small function with small stack usage
int add(int a, int b)
{
    int result = a + b;   // uses a small stack frame
    return result;
}

// Function with more stack usage
int computeSum()
{
    int arr[50];     // 50 * 4 = 200 bytes (on typical 32-bit CPUs)
    int total = 0;

    for(int i = 0; i < 50; ++i)
    {
        arr[i] = i;
        total += arr[i];
    }
    return total;
}

// Deeper stack because of recursion
int factorial(int n)
{
    if(n <= 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int x = add(3, 4);
    int y = computeSum();
    int z = factorial(5);
    return x + y + z;
}
