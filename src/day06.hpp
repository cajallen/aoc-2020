#ifndef DAY6_H_
#define DAY6_H_

#define INPUT_FILE06 "data/day06_input.txt"
#define CHAR_TO_INDEX(c) (int) c - 97

#include <vector>
#include <string>
#include <iostream>
#include "basic_parser.hpp"
#include "util_functions.hpp"
using namespace std;


int main(int, char**) __attribute__((weak));

namespace day06 {

void setup();
int solve1();
int solve2();

int count_line_any(const string line);
int count_line_every(const string line);

}  // namespace day06

#endif