#include <vector>
#include <string>
#include <iostream>
#include <bitset>
#include <cmath>
#include "basic_parser.h"

using namespace std;

#define FILE_NAME "data/day5_input.txt"

class Seat {
 public:
	int id = 0;
	int rows = 0;
	int columns = 0;

	Seat(const string line) {
		for (int i = 0; i < line.length(); i++) {
			if (line.at(i) == 'F' || line.at(i) == 'B') {
				rows += 1;
			} else if (line.at(i) == 'L' || line.at(i) == 'R') {
				columns += 1;
			}

			if (line.at(i) == 'B' || line.at(i) == 'R') {
				int bit_pos = line.length() - 1 - i;
				id |= (1 << bit_pos);
			}
		}
		bitset<10> bs_id(id);
	}

	int GetRow() const {
		return id >> columns;
	}
	int GetColumn() const {
		int mask = (1 << columns) - 1;
		return id & mask;
	}
};

ostream& operator << (ostream& os, const Seat& seat) {
	os << "row " << seat.GetRow() << ", column " << seat.GetColumn() << ", seat ID " << seat.id;
	return os;
}

int main() {
	const int max_seat = 1000;

	vector<string> lines = parse_list(FILE_NAME, '\n');
	vector<Seat> seats{};

	int highest_id = 0;
	for (string line : lines) {
		seats.push_back(Seat(line));
		if (seats.back().id > highest_id) {
			highest_id = seats.back().id;
		}
	}
	cout << "Highest ID: " << highest_id << endl;

	bool unfilled_seats[max_seat];
	for (Seat seat : seats) {
		unfilled_seats[seat.id] = true;
	}
	for (int i = 0; i < max_seat - 2; i++) {
		if (unfilled_seats[i] && !unfilled_seats[i + 1] && unfilled_seats[i + 2]) {
			cout << "Looks like " << i + 1 << " is unfilled." << endl;
		} 
	}
}