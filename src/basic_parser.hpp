#ifndef BASIC_PARSER_H_
#define BASIC_PARSER_H_

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

inline void rtrim(string &s) { s.erase(s.find_last_not_of(" \n\r\t\f\v") + 1); }
template <typename T> vector<T> parse_list(const string file_name, char delim = '\n');
vector<string> split(string line, char delim, bool trim = false);
vector<vector<bool>> parse_bit_grid(const string file_name);
vector<string> parse_double_newline_delimited(const string file_name);

template<>
inline vector<string> parse_list<string>(const string file_name, char delim) {
	ifstream input(file_name);
	if (!input) { throw new invalid_argument("Invalid file name: " + file_name); }

	vector<string> lines{};
	string line;
	while (getline(input, line, delim)) {
		rtrim(line);
		lines.push_back(line);
	}
	return lines;	
}


template <typename T>
vector<T> parse_list(const string file_name, char delim) {
	ifstream input(file_name);
	if (!input) { throw new invalid_argument("Invalid file name: " + file_name); }

	vector<T> lines{};
	T val;
	while (!input.eof()) {
		input >> val;
		lines.push_back(val);
	}
	return lines;
}


#endif
