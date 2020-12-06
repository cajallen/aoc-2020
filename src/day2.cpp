#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "basic_parser.hpp"

#define INPUT_FILE "data/day2_input.txt"

using namespace std;

#define POS1_I 1
#define POS2_I 2
#define CHAR_I 3
#define PW_I 4

class Line {
 public:
	int int1;
	int int2;
	char letter;
	string password;
};

ostream& operator << (ostream& os, const Line& line) {
	os << line.int1 << '-' << line.int2 << ' ' << line.letter << ": " << line.password;
	return os;
}

bool decode(const string inp, Line* line) {
	regex pattern("([0-9]+)-([0-9]+) ([a-z]): ([a-z]+)\r?");
	smatch matches;
	if (regex_match(inp, matches, pattern)) {
		line->int1 = stoi(matches[POS1_I]);
		line->int2 = stoi(matches[POS2_I]);
		line->letter = ((string) matches[CHAR_I]).front();
		line->password = matches[PW_I];
		return true;
	}
	return false;
}

bool test_line1(const string inp) {
	Line line;
	if (decode(inp, &line)) {
		int char_in_password = count(line.password.begin(), line.password.end(), line.letter);
		return line.int1 <= char_in_password && char_in_password <= line.int2;
	} else {
		cout << inp << " doesn't match pattern... Returning false" << endl;
		return false;
	}
}

bool test_line2(const string inp) {
	Line line;
	if (decode(inp, &line)) {
		if (line.password.size() < line.int1 || line.password.size() < line.int2) {
			throw out_of_range("pos1 or pos2 out of password index");
		}
		bool pos1_is_letter = line.password.at(line.int1 - 1) == line.letter;
		bool pos2_is_letter = line.password.at(line.int2 - 1) == line.letter;
		return pos1_is_letter != pos2_is_letter;
	} else {
		cout << inp << " doesn't match pattern... Returning false" << endl;
		return false;
	}
}


int main() {
	vector<string> lines = parse_list(INPUT_FILE);
	int count1 = 0;
	int count2 = 0;
	for (string line : lines) {
		if (test_line1(line)) {
			count1 += 1;
		}
	}
	cout << "#1: Passwords passing: " << count1 << endl;

	for (string line : lines) {
		if (test_line2(line)) {
			count2 += 1;
		}
	}
	cout << "#2: Passwords passing: " << count2 << endl;
}