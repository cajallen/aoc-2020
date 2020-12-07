#include <benchmark/benchmark.h>
#include "day3.hpp"

static void BM_day3setup(benchmark::State& state) {
	for (auto _ : state) { day3::setup(); }
}
static void BM_day3_1(benchmark::State& state) {
	day3::setup();
	for (auto _ : state) { day3::solve1(); }
}
static void BM_day3_2(benchmark::State& state) {
	day3::setup();
	for (auto _ : state) { day3::solve2(); }
}
BENCHMARK(BM_day3setup);
BENCHMARK(BM_day3_1);
BENCHMARK(BM_day3_2);

BENCHMARK_MAIN();
