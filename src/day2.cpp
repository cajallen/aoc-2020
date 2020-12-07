#include "day2.hpp"


int main(int a, char** b) {
	day2::setup();
	cout << "#1: " << day2::solve1() << endl;
	cout << "#2: " << day2::solve2() << endl;
}


namespace day2 {


vector<string> lines;


void setup() {
	lines = parse_list(INPUT_FILE2);
}


int solve1() {
	int count1 = 0;
	for (string line : lines) {
		if (test_line1(line)) {
			count1 += 1;
		}
	}
	return count1;
}

int solve2() {
	int count2 = 0;
	for (string line : lines) {
		if (test_line2(line)) {
			count2 += 1;
		}
	}
	return count2;
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


ostream& operator << (ostream& os, const Line& line) {
	os << line.int1 << '-' << line.int2 << ' ' << line.letter << ": " << line.password;
	return os;
}


}  // namespace day2
