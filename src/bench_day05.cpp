#include <benchmark/benchmark.h>
#include "day05.hpp"

static void BM_day05setup(benchmark::State& state) {
	for (auto _ : state) { day05::setup(); }
}
static void BM_day05_1(benchmark::State& state) {
	day05::setup();
	for (auto _ : state) { day05::solve1(); }
}
static void BM_day05_2(benchmark::State& state) {
	day05::setup();
	for (auto _ : state) { day05::solve2(); }
}
BENCHMARK(BM_day05setup);
BENCHMARK(BM_day05_1);
BENCHMARK(BM_day05_2);

BENCHMARK_MAIN();
