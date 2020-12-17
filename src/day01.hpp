#ifndef DAY1_H_
#define DAY1_H_

#define INPUT_FILE01 "data/day01_input.txt"

#include <vector>
#include <iostream>
#include <bitset>
#include "basic_parser.hpp"
using namespace std;


int main(int, char**) __attribute__((weak));

namespace day01 {

void setup();
int solve1();
int solve2();

}  // namespace day01

#endif
