#include <benchmark/benchmark.h>
#include "day13.hpp"

static void BM_day13setup(benchmark::State& state) {
	for (auto _ : state) { day13::setup(); }
}
static void BM_day13_1(benchmark::State& state) {
	day13::setup();
	for (auto _ : state) { day13::solve1(); }
}
static void BM_day13_2(benchmark::State& state) {
	day13::setup();
	for (auto _ : state) { day13::solve2(); }
}

BENCHMARK(BM_day13setup);
BENCHMARK(BM_day13_1);
//BENCHMARK(BM_day13_2);

BENCHMARK_MAIN();
