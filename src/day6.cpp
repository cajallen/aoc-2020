#include "day6.hpp"


int main(int a, char** b) {
	day6::setup();
	cout << "#1: " << day6::solve1() << endl;
	cout << "#2: " << day6::solve2() << endl;
}


namespace day6 {


vector<string> lines;


void setup () {
	lines = parse_double_newline_delimited(INPUT_FILE6);
}


int solve1() {
	int sum_any = 0;
	for (string line : lines) {
		sum_any += count_line_any(line);
	}
	return sum_any;
}


int solve2() {
	int sum_every = 0;
	for (string line : lines) {
		sum_every += count_line_every(line);
	}
	return sum_every;
}


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
	int mask = (1 << (group_member + 1)) - 1;
	for (int bits : letters) {
		if (bits == mask) {
			count += 1;
		}
	}
	return count;
}


}  // namespace day6
