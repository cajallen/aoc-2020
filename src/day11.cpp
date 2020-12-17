#include "day11.hpp"


int main(int a, char** b) {
	day11::setup();
	cout << "#1: " << day11::solve1() << endl;
	day11::setup();
	cout << "#2: " << day11::solve2() << endl;
	return 0;
}


namespace day11 {


Grid grid;


void setup() {
	grid = Grid();
	vector<string> lines = parse_list<string>(INPUT_FILE11);
	grid.width = lines.front().size();
	grid.height = lines.size();
	for (string line : lines) {
		for (char c : line) {
			switch(c) {
				case '.':
					grid.seats.push_back(false);
					grid.occupied.push_back(false);
					break;
				case 'L':
					grid.seats.push_back(true);
					grid.occupied.push_back(false);
					break;
			}
		}
	}
}


int solve1() {
	while (step(&Grid::count_neighbors, 4)) { }
	return count(grid.occupied.begin(), grid.occupied.end(), true);
}


int solve2() {
	while (step(&Grid::count_los, 5)) {  }
	return count(grid.occupied.begin(), grid.occupied.end(), true);
}


bool step(step_function func, int max) {
	vector<bool> new_occupied{};
	bool changed = false;
	for (int y = 0; y < grid.height; y++) {
		for (int x = 0; x < grid.width; x++) {
			if (!grid.is_seat(x, y)) { 
				new_occupied.push_back(false);
				continue;
			}

			int neighbors = (grid.*func)(x, y);
			if (neighbors == 0 && !grid.is_occupied(x, y)) {
				changed = true;
				new_occupied.push_back(true);
			} else if (neighbors >= max && grid.is_occupied(x, y)) {
				changed = true;
				new_occupied.push_back(false);
			} else {
				new_occupied.push_back(grid.is_occupied(x, y));
			}
		}
	}
	if (changed) {
		grid.occupied = new_occupied;
	}
	return changed;
} 


bool Grid::is_seat(int x, int y) {
	return seats[y * width + x];
}


bool Grid::is_occupied(int x, int y) {
	if (x < 0 || width <= x) { return false; }
	if (y < 0 || height <= y) { return false; }
	return occupied[y * width + x];
}


int Grid::count_neighbors(int x, int y) {
	int occupied_neighbors = 0;
	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			if (dx == 0 && dy == 0) { continue; }
			if (is_occupied(x+dx, y+dy)) { occupied_neighbors += 1; }
		}
	}
	return occupied_neighbors;
}


int Grid::count_los(int x1, int y1) {
	int occupied_neighbors = 0;
	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			if (dx == 0 && dy == 0) { continue; }
			int x = x1 + dx;
			int y = y1 + dy;
			bool done = false;
			// out of bounds or marked done
			while ((0 <= x && x < width) && (0 <= y && y < height) && !done) {
				if (is_occupied(x, y)) {
					occupied_neighbors += 1;
				}
				if (is_seat(x, y)) {
					done = true;
				}
				x += dx;
				y += dy;
			}
		}
	}
	return occupied_neighbors;
}


void Grid::print() {
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (!is_seat(x, y)) {
				cout << '.';
				continue;
			}
			if (is_occupied(x, y)) {
				cout << '#';
				continue;
			}
			cout << 'L';
		}
		cout << endl;
	}
}


}  // namespace day11
