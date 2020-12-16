#ifndef DAY9_H_
#define DAY9_H_

#define INPUT_FILE9 "data/day9_input.txt"

#include <vector>
#include <iostream>
#include <algorithm>
#include "basic_parser.hpp"
using namespace std;


int main(int, char**) __attribute__((weak));

namespace day9 {

void setup();
int solve1();
int solve2();

bool sums(int i);

}  // namespace day9

#endif
