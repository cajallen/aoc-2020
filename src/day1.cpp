#include "day1.hpp"


int main(int a, char** b) {
	day1::setup();
	cout << "#1: " << day1::solve1() << endl;
	cout << "#2: " << day1::solve2() << endl;
}


namespace day1 {


vector<int> numbers;


void setup() {
	numbers = parse_int_list(INPUT_FILE1);
}	


int solve1() {
	for (int i = 0; i < numbers.size(); i++) {
		for (int j = i + 1; j < numbers.size(); j++) {
			if (numbers[i] + numbers[j] == 2020) {
				return numbers[i] * numbers[j];
			}
		} 
	}
	return -1;
}


int solve2() {
	for (int i = 0; i < numbers.size(); i++) {
		for (int j = i + 1; j < numbers.size(); j++) {
			int ij_sum = numbers[i] + numbers[j];
			if (ij_sum >= 2020) {
				continue;	
			} for (int k = j + 1; k < numbers.size(); k++) {
				if (ij_sum + numbers[k] == 2020) {
					return numbers[i] * numbers[j] * numbers[k];
				}
			}
		} 
	}
	return -1;
}


}  // namespace day1
