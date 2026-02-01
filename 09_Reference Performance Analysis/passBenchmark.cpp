#include <benchmark/benchmark.h>

struct Buffer {
    int data[1024];
};

// Prevent compiler from optimizing away work
volatile int sink;

// Pass-by-value (copy)
void processByValue(Buffer buf)
{
    sink = buf.data[0];
}

// Pass-by-reference (no copy)
void processByRef(Buffer& buf)
{
    sink = buf.data[0];
}

// Benchmark: pass by value
static void BM_ProcessByValue(benchmark::State& state)
{
    Buffer buf{};
    buf.data[0] = 42;

    for (auto _ : state)
    {
        processByValue(buf);
    }
}
BENCHMARK(BM_ProcessByValue);

// Benchmark: pass by reference
static void BM_ProcessByRef(benchmark::State& state)
{
    Buffer buf{};
    buf.data[0] = 42;

    for (auto _ : state)
    {
        processByRef(buf);
    }
}
BENCHMARK(BM_ProcessByRef);