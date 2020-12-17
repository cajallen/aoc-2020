#ifndef DAY9_H_
#define DAY9_H_

#define INPUT_FILE09 "data/day09_input.txt"

#include <vector>
#include <iostream>
#include <algorithm>
#include "basic_parser.hpp"
using namespace std;


int main(int, char**) __attribute__((weak));

namespace day09 {

void setup();
int solve1();
int solve2();

bool sums(int i);

}  // namespace day09

#endif
