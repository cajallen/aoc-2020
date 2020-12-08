#include "day5.hpp"

int main(int a, char** b) {
	day5::setup();
	cout << "#1: " << day5::solve1() << endl;
	cout << "#2: " << day5::solve2() << endl;
}


namespace day5 {


vector<string> lines;


void setup() {
	lines = parse_list(INPUT_FILE5, '\n');
}


int solve1() {
	int highest_id = 0;
	for (string line : lines) {
		Seat seat(line);
		highest_id = seat.id > highest_id ? seat.id : highest_id;
	}
	return highest_id;
}


int solve2() {
	const int max_seat = 1000;
	vector<Seat> seats{};
	bool unfilled_seats[max_seat] = {};

	for (string line : lines) {
		Seat seat(line);
		unfilled_seats[seat.id] = true;
	}

	for (int i = 0; i < max_seat - 2; i++) {
		if (unfilled_seats[i] && !unfilled_seats[i + 1] && unfilled_seats[i + 2]) {
			return i + 1;
		} 
	}
	return -1;
}


Seat::Seat(const string line) {
	for (uint i = 0; i < line.length(); i++) {
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
}


int Seat::GetRow() const {
	return id >> columns;
}


int Seat::GetColumn() const {
	int mask = (1 << columns) - 1;
	return id & mask;
}


ostream& operator << (ostream& os, const Seat& seat) {
	os << "row " << seat.GetRow() << ", column " << seat.GetColumn() << ", seat ID " << seat.id;
	return os;
}


}  //namespace day5
