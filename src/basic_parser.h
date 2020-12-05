#include <fstream>
#include <string>
#include <vector>

using namespace std;

template <typename T> vector<T> parse_type_list(string file_name) {
	ifstream input(file_name);
	T temp;
	vector<T> vec;
	if (!input) {
		cout << "Error while opening file...";
		cin.ignore();
		return vector<T>();
	}
	while (!input.eof()) {
		input >> temp;
		vec.push_back(temp);
	}
	return vec;
}