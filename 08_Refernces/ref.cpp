int var = 10;      // x is an lvalue
int& ref = var;


void update(int& x)
{
    x = 20;
}

int main()
{
    int a = 10;
    update(a);
}

