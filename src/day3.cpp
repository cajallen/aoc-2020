#include <vector>
#include <iostream>
#include "basic_parser.hpp"

using namespace std;

#define FILE_NAME "data/day3_input.txt"

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

int main () {
	vector<vector<bool>> grid = parse_bit_grid(FILE_NAME);

	long slope11 = count_trees(grid, 1, 1);
	long slope31 = count_trees(grid, 3, 1);
	cout << "#1: Slope 3, 1: " << slope31 << endl;
	long slope51 = count_trees(grid, 5, 1);
	long slope71 = count_trees(grid, 7, 1);
	long slope12 = count_trees(grid, 1, 2);

	long product = slope11*slope31*slope51*slope71*slope12;
	cout << "#2: Product: " << product << endl;
}