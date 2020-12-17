#include <benchmark/benchmark.h>
#include "day07.hpp"

static void BM_day07setup(benchmark::State& state) {
	for (auto _ : state) { day07::setup(); }
}
static void BM_day07_1(benchmark::State& state) {
	day07::setup();
	for (auto _ : state) { day07::solve1(); }
}
static void BM_day07_2(benchmark::State& state) {
	day07::setup();
	for (auto _ : state) { day07::solve2(); }
}
BENCHMARK(BM_day07setup);
BENCHMARK(BM_day07_1);
BENCHMARK(BM_day07_2);

BENCHMARK_MAIN();
