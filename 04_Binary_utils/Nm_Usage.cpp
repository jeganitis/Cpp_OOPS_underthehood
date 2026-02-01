// ---- TEXT SYMBOLS ----
int func() {     // T - global text symbol
    return 42;
}

static int staticFunc() {  // t - local text symbol
    return 24;
}


// ---- INITIALIZED DATA ----
int globalInit = 100;       // D - initialized data
static int staticInit = 200; // d - local initialized data


// ---- UNINITIALIZED DATA (BSS) ----
int globalBSS;               // B - uninitialized
static int staticBSS;        // b - local uninitialized


// ---- UNDEFINED SYMBOL ----
extern int extVar;           // U - undefined (resolved at link)


// ---- WEAK SYMBOL ----
__attribute__((weak)) int weakVar = 10;      // W - weak data
__attribute__((weak)) int weakFunc() {       // w - weak function
    return 1;
}

// ---- MAIN ----
int main() {
    globalBSS = staticFunc();
    return func() + weakFunc();
}
