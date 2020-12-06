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

map<Key, regex> regex_keys {
	{byr, regex("byr:")},
	{eyr, regex("eyr:")},
	{iyr, regex("iyr:")},
	{hgt, regex("hgt:")},
	{pid, regex("pid:")},
	{ecl, regex("ecl:")},
	{hcl, regex("hcl:")},
	{hgt_unit, regex("hgt:")}
};

map<Key, regex> regex_rules {
	{byr, regex("byr:(\\d{4})")},
	{eyr, regex("eyr:(\\d{4})")},
	{iyr, regex("iyr:(\\d{4})")},
	{hgt, regex("hgt:(\\d+)((cm)|(in))")},
	{pid, regex("pid:(\\d{9})(?!\\d)")},
	{ecl, regex("ecl:(amb|blu|brn|gry|grn|hzl|oth)")},
	{hcl, regex("hcl:(#[a-z0-9]{6})")},
	{hgt_unit, regex("hgt:\\d+((cm)|(in))")}
};

class Passport {
 public:
	Passport(string line);

	void Set(Key member, string value);

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

vector<string> parse_to_lines(string input);

#endif
