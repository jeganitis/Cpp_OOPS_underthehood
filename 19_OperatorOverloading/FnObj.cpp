#include <iostream>

class ThresholdChecker
{
private:
    int threshold;

public:
    explicit ThresholdChecker(int t)
        : threshold(t)
    {}

    // Functor: overload function-call operator
    bool operator()(int value) const
    {
        return value > threshold;
    }
};

int main()
{
    ThresholdChecker isAbove10(10);  // configure object

    int a = 5;
    int b = 20;

    if (isAbove10(a))
        std::cout << "a is above threshold\n";
    else
        std::cout << "a is NOT above threshold\n";

    if (isAbove10(b))
        std::cout << "b is above threshold\n";
    else
        std::cout << "b is NOT above threshold\n";

    return 0;
}