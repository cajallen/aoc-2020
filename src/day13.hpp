#ifndef DAY13_H_
#define DAY13_H_

#define INPUT_FILE13 "data/day13_input.txt"

#include <vector>
#include <iostream>
#include <math.h>
#include "basic_parser.hpp"
using namespace std;


int main(int, char**) __attribute__((weak));

namespace day13 {

void setup();
long solve1();
long solve2();

int solve1_params(int, vector<int>);
long find_min(vector<int>, vector<int>);

int inv(int, int);

}  // namespace day13

#endif