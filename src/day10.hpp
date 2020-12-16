#ifndef DAY10_H_
#define DAY10_H_

#define INPUT_FILE10 "data/day10_input.txt"

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include "basic_parser.hpp"

using namespace std;


int main(int, char**) __attribute__((weak));

namespace day10 {

void setup();
int solve1();
long solve2();

int seq_ones_combinations(int amt);
int count_list_possibilities(vector<int>::iterator start, vector<int>::iterator end);

}  // namespace day10

#endif
