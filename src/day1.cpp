#include <vector>
#include <iostream>
#include "basic_parser.h"

#define INPUT_NAME "data/day1_input.txt"

using namespace std;

int n2approach1() {
	vector<int> numbers = parse_int_list(INPUT_NAME);
	for (int i = 0; i < numbers.size(); i++) {
		for (int j = i + 1; j < numbers.size(); j++) {
			if (numbers[i] + numbers[j] == 2020) {
				cout << "Answer #1: " << numbers[i] * numbers[j] << endl;
			}
		} 
	}
}

int n2approach2() {
	vector<int> numbers = parse_int_list(INPUT_NAME);
	for (int i = 0; i < numbers.size(); i++) {
		for (int j = i + 1; j < numbers.size(); j++) {
			int ij_sum = numbers[i] + numbers[j];
			if (ij_sum >= 2020) {
				continue;	
			} for (int k = j + 1; k < numbers.size(); k++) {
				if (ij_sum + numbers[k] == 2020) {
					cout << "Answer #2: " << numbers[i] * numbers[j] * numbers[k] << endl;
				}
			}
		} 
	}
}

int main() {
	n2approach1();
	n2approach2();
}