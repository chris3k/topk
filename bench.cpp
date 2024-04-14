#include <benchmark/benchmark.h>
#include <random>
#include "topk.h"

static void Top_k_base(benchmark::State& state) {
  std::vector<int> v;
  v.resize(state.range(0));
  std::mt19937 gen(state.range(0));
  for (size_t i = 0; i < v.size(); i++)
  {
    v[i] = gen();
  }
  // std::sort(v.begin(), v.end(), std::greater<>());

  for (auto _ : state) {
    auto top = base::topk(v.begin(), v.end(), state.range(1));
    benchmark::DoNotOptimize(top);
  }
}

static void Top_k_opt(benchmark::State& state) {
  std::vector<int> v;
  v.resize(state.range(0));
  std::mt19937 gen(state.range(0));
  for (size_t i = 0; i < v.size(); i++)
  {
    v[i] = gen();
  }
  // std::sort(v.begin(), v.end(), std::greater<>());

  for (auto _ : state) {
    auto top = opt::topk(v.begin(), v.end(), state.range(1));
    benchmark::DoNotOptimize(top);
  }
}

// BENCHMARK(Top_k_base)->Ranges({{1<<10, 8<<10}, {1<<1, 1<<10}});
BENCHMARK(Top_k_base)->Args({1'000'000, 1'000})->Args({1'000'000, 100'000});
// BENCHMARK(Top_k_opt)->Ranges({{1<<10, 8<<10}, {1<<1, 1<<10}});
BENCHMARK(Top_k_opt)->Args({1'000'000, 1'000})->Args({1'000'000, 100'000});
BENCHMARK_MAIN();
