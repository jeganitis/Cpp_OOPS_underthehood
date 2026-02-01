//Deleted constructor / destructor
/*
class NonCreatable {
public:
    NonCreatable() = delete;   // No default construction
    ~NonCreatable() = delete;  // No destruction either
};

int main()
{
	NonCreatable obj;   //Compile-time error
}*/

//=============================================================================
//Private destructor (controlled lifetime)

#include <iostream>

class Manager {
private:
    ~Manager() {}

public:
    static Manager* create() {
        return new Manager();
    }

    static void destroy(Manager* m) {
        delete m;
    }
};

int main() {
    // Create object using factory
    Manager* mgr = Manager::create();

    std::cout << "Manager created\n";

    // Destroy using controlled interface
    //Manager::destroy(mgr);

    delete mgr;// private constructor prevents this deletion
	std::cout << "Manager destroyed\n";

    return 0;
}