#include "util_functions.hpp"

bool in_range(int v, int min, int max) {
	return min <= v	&& v <= max;
}

void print_as_bits(string name, int i) {
	bitset<10> bs_int(i);
	cout << name << ": " << bs_int << endl;
}