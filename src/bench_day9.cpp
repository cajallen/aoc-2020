#include <benchmark/benchmark.h>
#include "day9.hpp"

static void BM_day9setup(benchmark::State& state) {
	for (auto _ : state) { day9::setup(); }
}
static void BM_day9_1(benchmark::State& state) {
	day9::setup();
	for (auto _ : state) { day9::solve1(); }
}
static void BM_day9_2(benchmark::State& state) {
	day9::setup();
	for (auto _ : state) { day9::solve2(); }
}

BENCHMARK(BM_day9setup);
BENCHMARK(BM_day9_1);
BENCHMARK(BM_day9_2);

BENCHMARK_MAIN();
