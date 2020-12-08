#include <benchmark/benchmark.h>
#include "day7.hpp"

static void BM_day7setup(benchmark::State& state) {
	for (auto _ : state) { day7::setup(); }
}
static void BM_day7_1(benchmark::State& state) {
	day7::setup();
	for (auto _ : state) { day7::solve1(); }
}
static void BM_day7_2(benchmark::State& state) {
	day7::setup();
	for (auto _ : state) { day7::solve2(); }
}
BENCHMARK(BM_day7setup);
BENCHMARK(BM_day7_1);
BENCHMARK(BM_day7_2);

BENCHMARK_MAIN();
