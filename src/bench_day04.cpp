#include <benchmark/benchmark.h>
#include "day04.hpp"

static void BM_day04setup(benchmark::State& state) {
	for (auto _ : state) { day04::setup(); }
}
static void BM_day04_1(benchmark::State& state) {
	day04::setup();
	for (auto _ : state) { day04::solve1(); }
}
static void BM_day04_2(benchmark::State& state) {
	day04::setup();
	for (auto _ : state) { day04::solve2(); }
}
BENCHMARK(BM_day04setup);
BENCHMARK(BM_day04_1);
BENCHMARK(BM_day04_2);

BENCHMARK_MAIN();
