class MathUtils {
public:
    MathUtils() = delete;  // no objects

    static int add(int a, int b) {
        return a + b;
    }

    static int square(int x) {
        return x * x;
    }
};


int main()
{
	int x = MathUtils::add(2, 3);   // OK
	MathUtils m;                  //Error
	
}
