#ifndef DAY11_H_
#define DAY11_H_

#define INPUT_FILE11 "data/day11_input.txt"

#include <vector>
#include <iostream>
#include "basic_parser.hpp"
using namespace std;


int main(int, char**) __attribute__((weak));

namespace day11 {

class Grid {
 public:
	int width;
	int height;
	vector<bool> seats;
	vector<bool> occupied;

	bool is_seat(int x, int y);
	bool is_occupied(int x, int y);
	int count_neighbors(int x, int y);
	int count_los(int x, int y);

	void print();
};

typedef int (Grid::*step_function)(int, int);

void setup();
int solve1();
int solve2();

bool step(step_function func, int max);

}  // namespace day11

#endif