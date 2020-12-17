#include <benchmark/benchmark.h>
#include "day09.hpp"

static void BM_day09setup(benchmark::State& state) {
	for (auto _ : state) { day09::setup(); }
}
static void BM_day09_1(benchmark::State& state) {
	day09::setup();
	for (auto _ : state) { day09::solve1(); }
}
static void BM_day09_2(benchmark::State& state) {
	day09::setup();
	for (auto _ : state) { day09::solve2(); }
}

BENCHMARK(BM_day09setup);
BENCHMARK(BM_day09_1);
BENCHMARK(BM_day09_2);

BENCHMARK_MAIN();
