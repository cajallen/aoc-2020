#include <benchmark/benchmark.h>
#include "day11.hpp"

static void BM_day11setup(benchmark::State& state) {
	for (auto _ : state) { day11::setup(); }
}
static void BM_day11_1(benchmark::State& state) {
	day11::setup();
	for (auto _ : state) { day11::solve1(); }
}
static void BM_day11_2(benchmark::State& state) {
	day11::setup();
	for (auto _ : state) { day11::solve2(); }
}

BENCHMARK(BM_day11setup);
BENCHMARK(BM_day11_1);
BENCHMARK(BM_day11_2);


BENCHMARK_MAIN();
