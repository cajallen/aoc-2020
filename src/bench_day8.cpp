#include <benchmark/benchmark.h>
#include "day8.hpp"

static void BM_day8setup(benchmark::State& state) {
	for (auto _ : state) { day8::setup(); }
}
static void BM_day8_1(benchmark::State& state) {
	day8::setup();
	for (auto _ : state) { day8::solve1(); }
}
static void BM_day8_2(benchmark::State& state) {
	day8::setup();
	for (auto _ : state) { day8::solve2(); }
}

BENCHMARK(BM_day8setup);
BENCHMARK(BM_day8_1);
BENCHMARK(BM_day8_2);

BENCHMARK_MAIN();
