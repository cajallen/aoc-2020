#include "basic_parser.hpp"


inline void rtrim(string &s) {
    s.erase(s.find_last_not_of(" \n\r\t\f\v") + 1);
}


vector<string> split(string line, char delim, bool trim) {
	string temp;
	vector<string> results{};
	istringstream input(line);

	while (getline(input, temp, delim)) {
		results.push_back(temp);
	}
	return results;
}


vector<string> parse_list(const string file_name, char delim) {
	ifstream input(file_name);
	string line;

	vector<string> lines{};

	if (!input) {
		throw new invalid_argument("Invalid file name: " + file_name);
	}

	while (getline(input, line, delim)) {
		rtrim(line);
		lines.push_back(line);
	}
	return lines;
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


vector<string> parse_double_newline_delimited(const string file_name) {
	string input = parse_list(file_name, '\0').front();
	input = regex_replace(input, regex("(.)\\r\\n"), "$1 ");
	
	istringstream iss(input);
	vector<string> lines{};
	string temp;
	while (getline(iss, temp)) {
		rtrim(temp);
		lines.push_back(temp);
	}
	return lines;
}
