#ifndef DAY4_H_
#define DAY4_H_

#define INPUT_FILE04 "data/day04_input.txt"

#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <map>
#include <algorithm>
#include "basic_parser.hpp"
#include "util_functions.hpp"
using namespace std;


int main(int, char**) __attribute__((weak));

namespace day04 {

enum Key { 
	byr, 
	eyr, 
	iyr, 
	hgt,
	pid,
	ecl, 
	hcl,
	hgt_unit
};

class Passport {
 public:
	Passport(const string line, const int part);

	void Set(const Key member, const string value);

	long cid_ = -1;
	long byr_ = -1;
	long eyr_ = -1;
	long iyr_ = -1;
	long hgt_ = -1;
	long pid_ = -1;
	string ecl_ = "";
	string hcl_ = "";
	string hgt_unit_ = "";
	bool valid_keys = false;
	bool valid_values = false;

 private:
	void validate();
};
ostream& operator << (ostream& os, const Passport& passport);

void setup();
int solve1();
int solve2();

}  // namespace day04

#endif
