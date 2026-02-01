#include <benchmark/benchmark.h>
#include <cstddef>
#include <cstring>

constexpr std::size_t ARRAY_SIZE = 1024 * 64; // 64K ints ≈ 256 KB

struct HeavyArray {
    int data[ARRAY_SIZE];
};


void processByValue(HeavyArray arr)
{
    benchmark::DoNotOptimize(arr.data[0]);
}

void processByRvalueRef(HeavyArray&& arr)
{
    benchmark::DoNotOptimize(arr.data[0]);
}

static void BM_Copy_Array(benchmark::State& state)
{
    for (auto _ : state)
    {
        HeavyArray arr{};
        processByValue(arr);   // copy happens here
    }
}
BENCHMARK(BM_Copy_Array);

static void BM_RvalueRef_Array(benchmark::State& state)
{
    for (auto _ : state)
    {
        HeavyArray arr{};
        processByRvalueRef(static_cast<HeavyArray&&>(arr)); // treat as rvalue
    }
}
BENCHMARK(BM_RvalueRef_Array);


