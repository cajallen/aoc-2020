#include "day4.hpp"

int main() {
	vector<string> lines = parse_double_newline_delimited(INPUT_FILE);

	int part1_passports = 0;
	int part2_passports = 0;
	for (string line : lines) {
		Passport passport(line);
		if (passport.valid_keys) {
			part1_passports += 1;
			if (passport.valid_values) {
				part2_passports += 1;
			}
		}
	}
	cout << "#1: Valid passports: " << part1_passports << endl;
	cout << "#2: Valid passports: " << part2_passports << endl;
}

Passport::Passport(const string line) {
	smatch matches;
	for (pair<Key, regex> element : regex_keys) {
		if (!regex_search(line, regex(element.second))) { return; }
	}
	valid_keys = true;

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
