#include "day10.hpp"

int main(int a, char **b) {
    day10::setup();
    cout << "#1: " << day10::solve1() << endl;
    cout << "#2: " << day10::solve2() << endl;
}

namespace day10 {

vector<int> increments;
vector<int> one_sequences;
map<int, int> seq_poss_combinations;

void setup() {
    increments.clear();
    one_sequences.clear();
	seq_poss_combinations.clear();

	vector<int> adapters = parse_list<int>(INPUT_FILE10);
	adapters.push_back(0);
	sort(adapters.begin(), adapters.end());
	adapters.push_back(adapters.back() + 3);

	for (uint i = 1; i < adapters.size(); i++) {
		increments.push_back(adapters[i] - adapters[i - 1]);
	}
}

int solve1() {
    vector<int> difference_sums{0, 0, 0, 0};
    for (int a : increments) {
        difference_sums[a] += 1;
    }
    return difference_sums[1] * difference_sums[3];
}

long solve2() {
    long possibilities = 1;
	
	int counter = 0;
	for (uint i = 0; i < increments.size(); i++) {
		if (increments[i] == 1) {
			counter += 1;
		} else {
			if (counter > 1) { possibilities *= seq_ones_combinations(counter); }
			counter = 0;
		}
	}
    return possibilities;
}

int seq_ones_combinations(int amt) {
    if (seq_poss_combinations.count(amt) == 1) {
        return seq_poss_combinations[amt];
    } else {
        vector<int> one_list(amt, 1);
        seq_poss_combinations[amt] = count_list_possibilities(one_list.begin(), one_list.end());
        return seq_poss_combinations[amt];
    }
}

int count_list_possibilities(vector<int>::iterator start, vector<int>::iterator end) {
    if (end - start <= 1) {
        return 1;
    }
    int sum = 0;
    for (uint i = 1; i <= 3; i++) {
        if (start + i > end) {
            continue;
        }
        int first_slice_sum = 0;
        for (vector<int>::iterator fs_i = start; fs_i < start + i; fs_i++) {
            first_slice_sum += *fs_i;
        }
        if (first_slice_sum > 3) {
            return sum;
        }
        sum += count_list_possibilities(start + i, end);
    }
    return sum;
}

} // namespace day10
