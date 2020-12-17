#include "day09.hpp"

int main(int a, char** b) {
	day09::setup();
	cout << "#1: " << day09::solve1() << endl;
	cout << "#2: " << day09::solve2() << endl;
}


namespace day09 {


vector<long> numbers;


void setup() {
	numbers = parse_list<long>(INPUT_FILE09);
}

int solve1() {
	for (uint i = 25; i < numbers.size(); i++) {
		if (!sums(i)) {
			return numbers[i];
		}
	}
	return -1;
}

bool sums(int i) {
	for (int j = i - 25; j < i; j++) {
		for (int k = j + 1; k < i; k++) {
			if ((numbers[j] + numbers[k]) == numbers[i]) {
				return true;
			}
		}
	}
	return false;
}

int solve2() {
	for (uint i = 0; i < numbers.size(); i++) {
		int index = i;
		int sum = numbers[index];

		while (sum < 258585477) {
			index += 1;
			sum += numbers[index];
		}
		if (sum == 258585477) {
			vector<long>::iterator start = numbers.begin() + i;
			vector<long>::iterator end = numbers.begin() + index;
			return *min_element(start, end+1) + *max_element(start, end+1);
		}
	}
	return -1;
}

}