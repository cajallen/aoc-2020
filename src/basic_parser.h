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
		cout << "Error while opening file...";
		cin.ignore();
		return vec;
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