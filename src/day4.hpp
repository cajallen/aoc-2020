#ifndef DAY4_H_
#define DAY4_H_

#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <map>
#include <algorithm>
#include "basic_parser.hpp"
#include "util_functions.hpp"

#define INPUT_FILE "data/day4_input.txt"

using namespace std;

enum key { 
	byr, 
	eyr, 
	iyr, 
	hgt,
	ecl, 
	hcl,
	pid,
	hgt_unit
};

const map<key, regex> regexes{
	{byr, regex("byr:(\\d{4})")},
	{eyr, regex("eyr:(\\d{4})")},
	{iyr, regex("iyr:(\\d{4})")},
	{hgt, regex("hgt:(\\d+)((cm)|(in))")},
	{ecl, regex("ecl:(amb|blu|brn|gry|grn|hzl|oth)")},
	{hcl, regex("hcl:(#[a-z0-9]{6})")},
	{pid, regex("pid:(\\d{9})(?!\\d)")},
	{hgt_unit, regex("hgt:\\d+((cm)|(in))")}
};

class Passport {
 public:
	Passport(string line);

	void Set(key member, string value);

	int byr_, cid_, eyr_, iyr_, hgt_;
	string ecl_, hcl_, pid_, hgt_unit_;
	bool valid = false;

 private:
	void initialize();
	bool validate();
};

ostream& operator << (ostream& os, const Passport& passport);

vector<string> parse_to_lines(string input);

#endif
