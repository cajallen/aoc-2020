#ifndef DAY2_H_
#define DAY2_H_

#define INPUT_FILE02 "data/day02_input.txt"
#define POS1_I 1
#define POS2_I 2
#define CHAR_I 3
#define PW_I 4

#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "basic_parser.hpp"
using namespace std;


int main(int, char**) __attribute__((weak));

namespace day02 {

class Line {
 public:
	uint int1;
	uint int2;
	char letter;
	string password;
};
ostream& operator << (ostream& os, const Line& line);

void setup();
int solve1();
int solve2();

void decode(const string inp, Line* line);
bool test_line1(const string inp, bool use_regex = false);
bool test_line2(const string inp, bool use_regex = false);

}  // namespace day02


#endif
