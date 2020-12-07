#include <benchmark/benchmark.h>
#include "day4.hpp"

static void BM_day4setup(benchmark::State& state) {
	for (auto _ : state) { day4::setup(); }
}
static void BM_day4_1(benchmark::State& state) {
	day4::setup();
	for (auto _ : state) { day4::solve1(); }
}
static void BM_day4_2(benchmark::State& state) {
	day4::setup();
	for (auto _ : state) { day4::solve2(); }
}
BENCHMARK(BM_day4setup);
BENCHMARK(BM_day4_1);
BENCHMARK(BM_day4_2);

BENCHMARK_MAIN();
