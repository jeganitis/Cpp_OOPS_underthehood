// --- TEXT SECTION ---
int add(int a, int b) {      
    return a + b;
}

int mul(int a, int b) {
    return a * b;
}

// --- DATA SECTION (initialized global/static) ---
int globalInit1 = 10;
int globalInit2 = 20;

static int staticInit1 = 30;
static int staticInit2 = 40;

int arrData[1024]={1,2,3,4};


// --- BSS SECTION (uninitialized/global) ---
int globalBSS1;
int globalBSS2;

static int staticBSS1;
static int staticBSS2;

int arrBssData[1024];


// --- MAIN (adds some code to .text) ---
int main() {
    int x = add(globalInit1, globalInit2);
    int y = mul(x, globalInit1);
    return y;
}
