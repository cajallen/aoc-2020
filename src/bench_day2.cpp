#include <benchmark/benchmark.h>
#include "day2.hpp"

static void BM_day2setup(benchmark::State& state) {
	for (auto _ : state) { day2::setup(); }
}
static void BM_day2_1(benchmark::State& state) {
	day2::setup();
	for (auto _ : state) { day2::solve1(); }
}
static void BM_day2_2(benchmark::State& state) {
	day2::setup();
	for (auto _ : state) { day2::solve2(); }
}
BENCHMARK(BM_day2setup);
BENCHMARK(BM_day2_1);
BENCHMARK(BM_day2_2);

BENCHMARK_MAIN();
