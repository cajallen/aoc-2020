#include "day3.hpp"


int main(int a, char** b) {
	day3::setup();
	cout << "#1: " << day3::solve1() << endl;
	cout << "#2: " << day3::solve2() << endl;
}


namespace day3 {


vector<vector<bool>> grid;


void setup() {
	grid = parse_bit_grid(INPUT_FILE3);
}

int solve1() {
	return count_trees(grid, 3, 1);
}

int solve2() {
	long slope11 = count_trees(grid, 1, 1);
	long slope31 = count_trees(grid, 3, 1);
	long slope51 = count_trees(grid, 5, 1);
	long slope71 = count_trees(grid, 7, 1);
	long slope12 = count_trees(grid, 1, 2);

	return slope11*slope31*slope51*slope71*slope12;
}

int count_trees(const vector<vector<bool>> grid, const int x_increment, const int y_increment) {
	int trees = 0;

	int x = 0;
	int y = 0;
	for (y = 0; y < grid.size(); y += y_increment) {
		if (grid[y][x % grid[y].size()]) {
			trees += 1;
		}
		x += x_increment;
	}
	return trees;
}


}  // namespace day3
