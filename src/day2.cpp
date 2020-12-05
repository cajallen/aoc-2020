#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <algorithm>
#include "basic_parser.h"

#define INPUT_FILE "data/day2_input.txt"

using namespace std;

#define MIN_I 1
#define MAX_I 2
#define CHAR_I 3
#define PW_I 4

bool test_line(const string inp) {
	regex pattern("([0-9]+)-([0-9]+) ([a-z]): ([a-z]+)\r?");
	smatch matches;
	if (regex_match(inp, matches, pattern)) {
		int min = stoi(matches[MIN_I]);
		int max = stoi(matches[MAX_I]);
		char mask = ((string) matches[CHAR_I]).front();
		string password = matches[PW_I];

		int char_in_pw = count(password.begin(), password.end(), mask);
		return min <= char_in_pw && char_in_pw <= max;
	} else {
		cout << inp << " doesn't match pattern... Aborting test" << endl;
	}
}


int main() {
	vector<string> lines = parse_list(INPUT_FILE);
	int count = 0;
	for (string line : lines) {
		if (test_line(line)) {
			count += 1;
		}
	}
	cout << "Total passwords that pass: " << count << endl;
}