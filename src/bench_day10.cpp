#include <benchmark/benchmark.h>
#include "day10.hpp"

static void BM_day10setup(benchmark::State& state) {
	for (auto _ : state) { day10::setup(); }
}
static void BM_day10_1(benchmark::State& state) {
	day10::setup();
	for (auto _ : state) { day10::solve1(); }
}
static void BM_day10_2(benchmark::State& state) {
	day10::setup();
	for (auto _ : state) { day10::solve2(); }
}

BENCHMARK(BM_day10setup);
BENCHMARK(BM_day10_1);
BENCHMARK(BM_day10_2);


BENCHMARK_MAIN();
