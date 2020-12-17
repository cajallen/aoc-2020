#include "day13.hpp"

using namespace std;

int main(int a, char** b) {
    day13::setup();
    cout << "#1: " << day13::solve1() << endl;
	cout << "#2: " << day13::solve2() << endl;
    return 1;
}

namespace day13 {

vector<int> num;
vector<int> rem;

void setup() {
    num = vector<int>{17,41,983,29,19,23,397,37,13};
    rem = vector<int>{};
}

long solve1() {
	/*
	int estimate = 92130912;
	int soonest_i = 0;
	int soonest_eta = busses[0] - estimate % busses[0];
	for (uint i = 1; i < busses.size(); i++) { 
		int bus_eta = busses[i] - estimate % busses[i];
		if (bus_eta < soonest_eta) {
			soonest_i = i;
			soonest_eta = bus_eta;
		}
	}
	return soonest_eta * busses[soonest_i];
	*/
}

long solve2() {
	return find_min(num, rem);
}

int inv(int input, int mod_0) {
    int mod_x = mod_0;
    int y = 0;
	int x = 1;

    if (mod_x == 1) return 0;
    while (input > 1) {
        int quotient = input / mod_x;
        int old_mod_x = mod_x;
        mod_x = input % mod_x;
		input = old_mod_x;
        int temp = y;
        y = x - quotient * y;
        x = temp;
    }
    if (x < 0) { x += mod_0; }

    return x;
}

long find_min(vector<int> nums, vector<int> rems) {
    long product = 1;
    for (uint i = 0; i < nums.size(); i++) { product *= nums[i]; }

    long result = 0;

    for (uint i = 0; i < nums.size(); i++) {
        long part_product = product / nums[i];
        result += rems[i] * inv(part_product, nums[i]) * part_product;
    }

    return result % product;
}

}  // namespace day13
