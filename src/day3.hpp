#ifndef DAY3_H_
#define DAY3_H_

#define INPUT_FILE3 "data/day3_input.txt"

#include <vector>
#include <iostream>
#include "basic_parser.hpp"
using namespace std;


int main(int, char**) __attribute__((weak));

namespace day3 {

void setup();
int solve1();
int solve2();

int count_trees(const vector<vector<bool>> grid, const int x_increment, const int y_increment);

}  // namespace day3


#endif