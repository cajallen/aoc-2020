#include <benchmark/benchmark.h>
#include "day1.hpp"

static void BM_day1setup(benchmark::State& state) {
	for (auto _ : state) { day1::setup(); }
}
static void BM_day1_1(benchmark::State& state) {
	day1::setup();
	for (auto _ : state) { day1::solve1(); }
}
static void BM_day1_2(benchmark::State& state) {
	day1::setup();
	for (auto _ : state) { day1::solve2(); }
}
BENCHMARK(BM_day1setup);
BENCHMARK(BM_day1_1);
BENCHMARK(BM_day1_2);

BENCHMARK_MAIN();
