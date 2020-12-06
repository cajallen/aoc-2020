CC := g++
CXXFLAGS := -Werror

SRC := $(wildcard src/*.cpp)
OBJECTS := $(SRC:src/%.cpp=%)

all:
	@make $(sort $(OBJECTS)) --no-print-directory

debug: CXXFLAGS += -g
debug: all

release: CXXFLAGS += -O2
release: all

day%:
	@mkdir -p build
	@echo Compiling $@...
	@make build/$@.o --no-print-directory
	@echo Running $@...
	@./build/$@.o
	@echo 

build/%.o: src/%.cpp
	@$(CC) -o $@ $^ $(CFLAGS)

clean:
	@rm -rf build
