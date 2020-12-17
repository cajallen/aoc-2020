#include <benchmark/benchmark.h>
#include "day03.hpp"

static void BM_day03setup(benchmark::State& state) {
	for (auto _ : state) { day03::setup(); }
}
static void BM_day03_1(benchmark::State& state) {
	day03::setup();
	for (auto _ : state) { day03::solve1(); }
}
static void BM_day03_2(benchmark::State& state) {
	day03::setup();
	for (auto _ : state) { day03::solve2(); }
}
BENCHMARK(BM_day03setup);
BENCHMARK(BM_day03_1);
BENCHMARK(BM_day03_2);

BENCHMARK_MAIN();
