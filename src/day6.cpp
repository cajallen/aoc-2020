#include <vector>
#include <string>
#include <iostream>
#include "basic_parser.hpp"
#include "util_functions.hpp"

#define FILE_NAME "data/day6_input.txt"
#define CHAR_TO_INDEX(c) (int) c - 97

int count_line_any(const string line) {
	bool letters[26] = {};
	for (char letter : line) {
		if (islower(letter)) {
			letters[CHAR_TO_INDEX(letter)] = true;
		}
	}
	int count = 0;
	for (bool bit : letters) {
		if (bit) {
			count += 1;
		}
	}
	return count;
}

int count_line_every(const string line) {
	int group_member = 0;
	int letters[26] = {};
	for (char letter : line) {
		if (islower(letter)) {
			letters[CHAR_TO_INDEX(letter)] |= 1 << group_member;
		} else if (letter == ' ') {
			group_member += 1;
		}
	}
	int count = 0;
	int mask = (1 << group_member + 1) - 1;
	for (int bits : letters) {
		if (bits == mask) {
			count += 1;
		}
	}
	return count;
}

int main() {
	vector<string> lines = parse_double_newline_delimited(FILE_NAME);
	int sum_any = 0;
	int sum_every = 0;
	for (string line : lines) {
		sum_any += count_line_any(line);
		sum_every += count_line_every(line);
	}
	cout << "#1: any sum: " << sum_any << endl;
	cout << "#2: every sum: " << sum_every << endl;
}
