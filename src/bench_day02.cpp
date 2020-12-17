#include <benchmark/benchmark.h>
#include "day02.hpp"

static void BM_day02setup(benchmark::State& state) {
	for (auto _ : state) { day02::setup(); }
}
static void BM_day02_1(benchmark::State& state) {
	day02::setup();
	for (auto _ : state) { day02::solve1(); }
}
static void BM_day02_2(benchmark::State& state) {
	day02::setup();
	for (auto _ : state) { day02::solve2(); }
}
BENCHMARK(BM_day02setup);
BENCHMARK(BM_day02_1);
BENCHMARK(BM_day02_2);

BENCHMARK_MAIN();
