#include <iostream>
#include <cstring>

/*--------------------------------------------------
  SHALLOW COPY EXAMPLE
  (Shared buffer, no data duplication)
--------------------------------------------------*/
class ShallowBuffer {
public:
    char* data;

    explicit ShallowBuffer(char* external)
        : data(external) {}

    // Shallow copy constructor
    ShallowBuffer(const ShallowBuffer& other)
        : data(other.data) {}   // pointer copied only

    void write(const char* msg) {
        std::strcpy(data, msg);
    }

    void print(const char* name) const {
        std::cout << name << ": " << data << '\n';
    }
};

/*--------------------------------------------------
  DEEP COPY EXAMPLE
  (Independent buffer per object)
--------------------------------------------------*/
class DeepBuffer {
public:
    char* data;

    explicit DeepBuffer(const char* msg) {
        data = new char[64];
        std::strcpy(data, msg);
    }

    // Deep copy constructor
    DeepBuffer(const DeepBuffer& other) {
        data = new char[64];
        std::strcpy(data, other.data);
    }

    void write(const char* msg) {
        std::strcpy(data, msg);
    }

    void print(const char* name) const {
        std::cout << name << ": " << data << '\n';
    }

    ~DeepBuffer() {
        delete[] data;
    }
};

/*--------------------------------------------------
  MAIN
--------------------------------------------------*/
int main() {
    std::cout << "=== SHALLOW COPY DEMO ===\n";

    char sharedMemory[64] = "Initial Data";
    ShallowBuffer s1(sharedMemory);
    ShallowBuffer s2 = s1;   // shallow copy

    s1.print("s1");
    s2.print("s2");

    std::cout << "Modify s1\n";
    s1.write("Modified via s1");

    s1.print("s1");
    s2.print("s2");   // affected!

    std::cout << "\n=== DEEP COPY DEMO ===\n";

    DeepBuffer d1("Initial Data");
    DeepBuffer d2 = d1;      // deep copy

    d1.print("d1");
    d2.print("d2");

    std::cout << "Modify d1\n";
    d1.write("Modified via d1");

    d1.print("d1");
    d2.print("d2");   // unchanged

    return 0;
}