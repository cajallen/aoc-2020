#ifndef DAY6_H_
#define DAY6_H_

#define INPUT_FILE6 "data/day6_input.txt"
#define CHAR_TO_INDEX(c) (int) c - 97

#include <vector>
#include <string>
#include <iostream>
#include "basic_parser.hpp"
#include "util_functions.hpp"
using namespace std;


int main(int, char**) __attribute__((weak));

namespace day6 {

void setup();
int solve1();
int solve2();

int count_line_any(const string line);
int count_line_every(const string line);

}  // namespace day6

#endif