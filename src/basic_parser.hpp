#ifndef BASIC_PARSER_H_
#define BASIC_PARSER_H_

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

static inline void rtrim(string &s);

vector<string> parse_list(const string file_name, char delim = '\n');
vector<int> parse_int_list(const string file_name);
vector<vector<bool>> parse_bit_grid(const string file_name);
vector<string> parse_double_newline_delimited(const string file_name);

#endif
