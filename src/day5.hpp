#ifndef DAY5_H_
#define DAY5_H_

#define INPUT_FILE5 "data/day5_input.txt"

#include <vector>
#include <string>
#include <iostream>
#include <bitset>
#include <cmath>
#include "basic_parser.hpp"
using namespace std;


int main(int, char**) __attribute__((weak));

namespace day5 {

class Seat {
 public:
	Seat(const string line);

	int GetRow() const;
	int GetColumn() const;

	int id = 0;
	int rows = 0;
	int columns = 0;
};
ostream& operator << (ostream& os, const Seat& seat);

void setup();
int solve1();
int solve2();

}  // namespace day5

#endif