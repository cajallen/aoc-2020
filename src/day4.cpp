#include "day4.hpp"


int main(int a, char** b) {
	day4::setup();
	cout << "#1: " << day4::solve1() << endl;
	cout << "#2: " << day4::solve2() << endl;
}


namespace day4 {


vector<string> lines;
map<Key, regex> regex_keys;
map<Key, regex> regex_rules;


void setup() {
	lines = parse_double_newline_delimited(INPUT_FILE4);
	regex_keys = map<Key, regex>{
		{byr, regex("byr:")},
		{eyr, regex("eyr:")},
		{iyr, regex("iyr:")},
		{hgt, regex("hgt:")},
		{pid, regex("pid:")},
		{ecl, regex("ecl:")},
		{hcl, regex("hcl:")},
		{hgt_unit, regex("hgt:")}
	};

	regex_rules = map<Key, regex>{
		{byr, regex("byr:(\\d{4})")},
		{eyr, regex("eyr:(\\d{4})")},
		{iyr, regex("iyr:(\\d{4})")},
		{hgt, regex("hgt:(\\d+)((cm)|(in))")},
		{pid, regex("pid:(\\d{9})(?!\\d)")},
		{ecl, regex("ecl:(amb|blu|brn|gry|grn|hzl|oth)")},
		{hcl, regex("hcl:(#[a-z0-9]{6})")},
		{hgt_unit, regex("hgt:\\d+((cm)|(in))")}
	};
}


int solve1() {
	int passports = 0;
	for (string line : lines) {
		Passport passport(line, 1);
		if (passport.valid_keys) {
			passports += 1;
		}
	}
	return passports;
}	


int solve2() {
	int passports = 0;
	for (string line : lines) {
		Passport passport(line, 2);
		if (passport.valid_values) {
			passports += 1;
		}
	}
	return passports;
}





Passport::Passport(const string line, int part) {
	smatch matches;
	for (pair<Key, regex> element : regex_keys) {
		if (!regex_search(line, regex(element.second))) { return; }
	}
	valid_keys = true;

	if (part == 1) { return; }

	for (pair<Key, regex> element : regex_rules) {
		if (regex_search(line, matches, element.second)) {
			Set(element.first, matches[1]);
		} else {
			return;
		}
	}
	validate();
}


void Passport::Set(const Key member, const string value) {
	switch (member) {
		case byr: byr_ = stol(value); break;
		case eyr: eyr_ = stol(value); break;
		case iyr: iyr_ = stol(value); break;
		case hgt: hgt_ = stol(value); break;
		case pid: pid_ = stol(value); break;
		case ecl: ecl_ = value; break;
		case hcl: hcl_ = value; break;
		case hgt_unit: hgt_unit_ = value; break;
	}
}


void Passport::validate() {
	valid_values = false;
	if (!valid_keys) { return; }
	if (!in_range(byr_, 1920, 2002)) { return; }
	if (!in_range(eyr_, 2020, 2030)) { return; }
	if (!in_range(iyr_, 2010, 2020)) { return; }
	if (hgt_unit_ == "cm" && !in_range(hgt_, 150, 193)) { return; }
	if (hgt_unit_ == "in" && !in_range(hgt_, 59, 76)) { return; }

	valid_values = true;
}


ostream& operator << (ostream& os, const Passport& passport) {
	os << "{cid:" << passport.cid_;
	os << ", byr:" << passport.byr_;
	os << ", eyr:" << passport.eyr_;
	os << ", iyr:" << passport.iyr_;
	os << ", hgt:" << passport.hgt_ << " " << passport.hgt_unit_;
	os << ", pid:" << passport.pid_;
	os << ", ecl:" << passport.ecl_;
	os << ", hcl:" << passport.hcl_;
	os << "}";
	return os;
}


}  // namespace day4
