int global_init = 42;        // .data
int global_uninit;           // .bss
const char msg[] = "VMA/LMA";

int add(int a, int b)
{
    return a + b + global_init + global_uninit;
}

int main()
{
    global_uninit = 1;
    return add(2, 3);
}

