#include <benchmark/benchmark.h>
#include "day12.hpp"

static void BM_day12setup(benchmark::State& state) {
	for (auto _ : state) { day12::setup(); }
}
static void BM_day12_1(benchmark::State& state) {
	day12::setup();
	for (auto _ : state) { day12::solve1(); }
}
static void BM_day12_2(benchmark::State& state) {
	day12::setup();
	for (auto _ : state) { day12::solve2(); }
}

BENCHMARK(BM_day12setup);
BENCHMARK(BM_day12_1);
BENCHMARK(BM_day12_2);


BENCHMARK_MAIN();
