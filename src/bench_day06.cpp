#include <benchmark/benchmark.h>
#include "day06.hpp"

static void BM_day06setup(benchmark::State& state) {
	for (auto _ : state) { day06::setup(); }
}
static void BM_day06_1(benchmark::State& state) {
	day06::setup();
	for (auto _ : state) { day06::solve1(); }
}
static void BM_day06_2(benchmark::State& state) {
	day06::setup();
	for (auto _ : state) { day06::solve2(); }
}
BENCHMARK(BM_day06setup);
BENCHMARK(BM_day06_1);
BENCHMARK(BM_day06_2);

BENCHMARK_MAIN();
