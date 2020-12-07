CXXFLAGS :=
DEP := build/basic_parser.o build/util_functions.o
DAYS = $(wildcard src/day*.cpp)
BENCHES = $(wildcard src/bench_day*.cpp)

all:
	@make $(sort $(DAYS:src/day%.cpp=day%_build)) --no-print-directory
	@make $(sort $(DAYS:src/day%.cpp=day%_run)) --no-print-directory

all_bench:
	@make $(sort $(BENCHES:src/bench_day%.cpp=bench_day%)) --no-print-directory

bench_day%: $(DEP) build/day%.o
	@make build/$@ --no-print-directory
	@./build/$@

day%_build:
	@echo Compiling day$*_...
	@make build/day$*_ --no-print-directory

day%_run:
	@echo Running day$*_...
	@./build/day$*_


day%_x:
	@make day$*_build --no-print-directory
	@make day$*_run --no-print-directory


build/bench_day%: $(DEP) build/day%.o
	@mkdir -p build
	@g++ src/bench_day$*.cpp $(CXXFLAGS) -isystem benchmark/include -Lbenchmark/build/src -lbenchmark -pthread -o $@ $^


build/day%_: $(DEP) build/day%.o
	@g++ $(CXXFLAGS) -o $@ $^

build/%.o: src/%.cpp src/%.hpp
	@mkdir -p build
	@g++ $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf build
