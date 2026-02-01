// override.cpp
// If linked, these strong symbols override the weak defaults.

int weakVar = 99;          // strong data: overrides weakVar
int weakFunc() { return 7; } // strong function: overrides weakFunc
