#include "day4.hpp"

int main() {
	vector<string> lines = parse_double_newline_delimited(INPUT_FILE);

	int valid_passports = 0;
	for (string line : lines) {
		Passport passport(line);
		if (passport.valid) {
			valid_passports += 1;
		}
	}
	cout << "Valid passports: " << valid_passports << endl;
}


Passport::Passport(string line) {
	initialize();
	smatch matches;

	for (pair<key, regex> element : regexes) {
		if (regex_search(line, matches, element.second)) {
			Set(element.first, matches[1]);
		} else {
			if (!valid) {
				continue;
			}
			valid = false;
		}
	}
	if (valid && !validate()) {
		valid = false;
	}
}


void Passport::Set(key member, string value) {
	switch (member) {
		case byr: byr_ = stol(value);
		case eyr: eyr_ = stol(value);
		case iyr: iyr_ = stol(value);
		case hgt: hgt_ = stol(value);
		case ecl: ecl_ = value;
		case hcl: hcl_ = value;
		case pid: pid_ = value;
		case hgt_unit: hgt_unit_ = value;
	}
}


void Passport::initialize() {
	byr_ = 0;
	eyr_ = 0;
	iyr_ = 0;
	hgt_ = 0;
	cid_ = 0;
	ecl_ = "";
	hcl_ = "";
	pid_ = "";
	hgt_unit_ = "";
	valid = true;
}

bool Passport::validate() {
	// height
	if ((hgt_unit_ == "cm") && !in_range(hgt_, 150, 193)) {
		return false;
	}
	if ((hgt_unit_ == "in") && !in_range(hgt_, 59, 76)) {
		return false;
	}

	// years
	if (!in_range(byr_, 1920, 2002)) {
		return false;
	}
	if (!in_range(eyr_, 2020, 2030)) {
		return false;
	}
	if (!in_range(iyr_, 2010, 2020)) {
		return false;
	}
	return true;
}


ostream& operator << (ostream& os, const Passport& passport) {
	os << "{byr:" << passport.byr_;
	os << ", iyr:" << passport.iyr_;
	os << ", eyr:" << passport.eyr_;
	os << ", hgt:" << passport.hgt_ << " " << passport.hgt_unit_;
	os << ", pid:" << passport.pid_;
	os << ", cid:" << passport.cid_;
	os << ", hcl:" << passport.hcl_;
	os << ", ecl:" << passport.ecl_;
	os << "}";
	return os;
}
