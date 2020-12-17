#include <benchmark/benchmark.h>
#include "day01.hpp"

static void BM_day01setup(benchmark::State& state) {
	for (auto _ : state) { day01::setup(); }
}
static void BM_day01_1(benchmark::State& state) {
	day01::setup();
	for (auto _ : state) { day01::solve1(); }
}
static void BM_day01_2(benchmark::State& state) {
	day01::setup();
	for (auto _ : state) { day01::solve2(); }
}
BENCHMARK(BM_day01setup);
BENCHMARK(BM_day01_1);
BENCHMARK(BM_day01_2);

BENCHMARK_MAIN();
