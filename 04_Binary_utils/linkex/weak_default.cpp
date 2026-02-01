// weak_default.cpp
// Weak data and weak function (defaults that can be overridden)

__attribute__((weak)) int weakVar = 42;            // weak data symbol
__attribute__((weak)) int weakFunc() { return 1; } // weak function symbol
