#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> parse_list(const string file_name) {
	ifstream input(file_name);
	string line;

	vector<string> vec{};

	if (!input) {
		throw new invalid_argument("Invalid file name: " + file_name);
	}

	while (getline(input, line)) {
		if (line.back() == '\r') {
			line.pop_back();
		}
		vec.push_back(line);
	}
	return vec;
}

vector<int> parse_int_list(const string file_name) {
	vector<int> vec{};
	for (string line : parse_list(file_name)) {
		vec.push_back(stoi(line));
	}
	return vec;
}

vector<vector<bool>> parse_bit_grid(const string file_name) {
	vector<vector<bool>> grid{};
	for (string string_line : parse_list(file_name)) {
		vector<bool> bit_line;
		for (char bit : string_line) {
			if (bit == '.') {
				bit_line.push_back(0);
			} else if (bit == '#') {
				bit_line.push_back(1);
			} else {
				cout << bit << " is an invalid bit entry for the map" << endl;
			}
		}
		grid.push_back(bit_line);
	}
	return grid;
}