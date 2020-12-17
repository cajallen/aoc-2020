#include "day01.hpp"


int main(int a, char** b) {
	day01::setup();
	cout << "#1: " << day01::solve1() << endl;
	cout << "#2: " << day01::solve2() << endl;
}


namespace day01 {


vector<int> numbers;
bitset<2020> bs_numbers{};


void setup() {
	numbers = parse_list<int>(INPUT_FILE01);
	for (int num : numbers) {
		bs_numbers[num] = true;
	}
}	


int solve1() {
	for (int x : numbers) {
		int y = 2020 - x;
		if (bs_numbers[y]) {
			return x * y;
		}
	}
	return -1;
}


int solve2() {
	for (uint i = 0; i < numbers.size(); i++) {
		for (uint j = i + 1; j < numbers.size(); j++) {
			int ij_sum = numbers[i] + numbers[j];
			if (ij_sum >= 2020) {
				continue;	
			}
			int k = 2020 - ij_sum;
			if (bs_numbers[k]) {
				return numbers[i] * numbers[j] * k;
			}
		} 
	}
	return -1;
}


}  // namespace day01
