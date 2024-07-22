#include <benchmark/benchmark.h>
#include "sorting.h"

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <random>
#include <string_view>
#include <vector>

std::vector<int> fill_vector(int size)
{
    std::vector<int>           data;
    std::random_device         rd;
    std::default_random_engine rng(rd());
    std::uniform_int_distribution<int> distribution(0, 100);

    auto gen = [&](){
        return distribution(rng);
    };

    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), gen);

    return vec;
}

void print_ints(const std::vector<int>& ints) 
{
    for (const auto n : ints) {
        std::cout << n << std::endl;
    }
}

// -------------------------
// benchmark: std::sort
// -------------------------

static void BM_std_sort(benchmark::State& s)
{
    auto data = fill_vector(s.range(0));

    for (auto _ : s) {
        std::sort(data.begin(), data.end(), std::greater());
    }
}
BENCHMARK(BM_std_sort)->Unit(benchmark::kNanosecond)->RangeMultiplier(2)->Range(8, 8<<10);

// -------------------------
// benchmark: std::qsort
// -------------------------

static void BM_std_qsort(benchmark::State& s)
{
    auto data = fill_vector(s.range(0));

    for (auto _ : s) {
        std::qsort(
            data.data(), 
            data.size(),
            sizeof(decltype(data)::value_type),
            [](const void* a, const void* b)
            {
                return (*(int*)b - *(int*)a);
            });
    }
}
BENCHMARK(BM_std_qsort)->Unit(benchmark::kNanosecond)->RangeMultiplier(2)->Range(8, 8<<10);

// -------------------------
// benchmark: insertion sort
// -------------------------

static void BM_insertion_sort(benchmark::State& s)
{
    auto data = fill_vector(s.range(0));

    for (auto _ : s) {
        sorting::insertion_sort(data.data(), data.size(), std::greater());
    }
}
BENCHMARK(BM_insertion_sort)->Unit(benchmark::kNanosecond)->RangeMultiplier(2)->Range(8, 8<<10);

// -------------------------
// benchmark: insertion sort (range based)
// -------------------------

static void BM_insertion_sort_cpp(benchmark::State& s)
{
    auto data = fill_vector(s.range(0));

    for (auto _ : s) {
        sorting::insertion_sort(data.begin(), data.end(), std::greater());
    }
}
BENCHMARK(BM_insertion_sort_cpp)->Unit(benchmark::kNanosecond)->RangeMultiplier(2)->Range(8, 8<<10);

BENCHMARK_MAIN();
