#include <benchmark/benchmark.h>
#include "day08.hpp"

static void BM_day08setup(benchmark::State& state) {
	for (auto _ : state) { day08::setup(); }
}
static void BM_day08_1(benchmark::State& state) {
	day08::setup();
	for (auto _ : state) { day08::solve1(); }
}
static void BM_day08_2(benchmark::State& state) {
	day08::setup();
	for (auto _ : state) { day08::solve2(); }
}

BENCHMARK(BM_day08setup);
BENCHMARK(BM_day08_1);
BENCHMARK(BM_day08_2);

BENCHMARK_MAIN();
