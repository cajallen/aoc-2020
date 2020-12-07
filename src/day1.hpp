#ifndef DAY1_H_
#define DAY1_H_

#define INPUT_FILE1 "data/day1_input.txt"

#include <vector>
#include <iostream>
#include "basic_parser.hpp"
using namespace std;


int main(int, char**) __attribute__((weak));

namespace day1 {

void setup();
int solve1();
int solve2();

}  // namespace day1

#endif
