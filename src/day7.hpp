#ifndef DAY2_H_
#define DAY2_H_

#define INPUT_FILE7 "data/day7_input.txt"

#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <set>
#include <map>
#include <exception>
#include "basic_parser.hpp"
using namespace std;


int main(int, char**) __attribute__((weak));

namespace day7 {

void setup();
int solve1();
int solve2();

void register_line(const string line);
void traverse_tree_up(string element_to_visit, set<string> &visited);
int traverse_tree_down(string element_to_visit, set<string> &visited);

}  // namespace day2


#endif
