#include <benchmark/benchmark.h>
#include "day6.hpp"

static void BM_day6setup(benchmark::State& state) {
	for (auto _ : state) { day6::setup(); }
}
static void BM_day6_1(benchmark::State& state) {
	day6::setup();
	for (auto _ : state) { day6::solve1(); }
}
static void BM_day6_2(benchmark::State& state) {
	day6::setup();
	for (auto _ : state) { day6::solve2(); }
}
BENCHMARK(BM_day6setup);
BENCHMARK(BM_day6_1);
BENCHMARK(BM_day6_2);

BENCHMARK_MAIN();
