#include <benchmark/benchmark.h>
#include "day5.hpp"

static void BM_day5setup(benchmark::State& state) {
	for (auto _ : state) { day5::setup(); }
}
static void BM_day5_1(benchmark::State& state) {
	day5::setup();
	for (auto _ : state) { day5::solve1(); }
}
static void BM_day5_2(benchmark::State& state) {
	day5::setup();
	for (auto _ : state) { day5::solve2(); }
}
BENCHMARK(BM_day5setup);
BENCHMARK(BM_day5_1);
BENCHMARK(BM_day5_2);

BENCHMARK_MAIN();
