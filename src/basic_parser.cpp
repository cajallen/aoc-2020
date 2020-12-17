#include "basic_parser.hpp"


vector<string> split(string line, char delim, bool trim) {
	istringstream input(line);
	vector<string> results{};
	string temp;
	while (getline(input, temp, delim)) {
		if (trim) { rtrim(temp); }
		results.push_back(temp);
	}
	return results;
}


vector<vector<bool>> parse_bit_grid(const string file_name) {
	vector<vector<bool>> grid{};
	for (string string_line : parse_list<string>(file_name)) {
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
	string input = parse_list<string>(file_name, '\0').front();
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
