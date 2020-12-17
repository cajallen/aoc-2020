#include "day7.hpp"

int main(int a, char** b) {
	day7::setup();
	cout << "#1: " << day7::solve1() << endl;
	cout << "#2: " << day7::solve2() << endl;
}

namespace day7 {


map<string, set<string>> upwards{};
map<string, set<pair<string, int>>> downwards{};


void setup() {
	vector<string> lines = parse_list<string>(INPUT_FILE7, '\n');
	for (string line : lines) {
		register_line(line);
	}
}

int solve1() {
	unordered_set<string> visited{};
	traverse_tree_up("shiny gold", visited);
	return visited.size() - 1;
}


int solve2() {
	return traverse_tree_down("shiny gold");
}	


void register_line(const string line) {
	string inp = line;
	string key, color;
	smatch matches;
	if (regex_search(inp, matches, regex("^([a-z]+ [a-z]+)"))) {
		color = matches[1].str();
		key = color;
		downwards[key] = set<pair<string, int>>{};

		inp = matches.suffix().str();
	} else {
		throw new invalid_argument("register line called on bad line");
	}

	while (regex_search(inp, matches, regex(" (\\d) ([a-z]+ [a-z]+)"))) {
		int count = stoi(matches[1].str());
		color = matches[2].str();
		if (upwards.find(color) == upwards.end()) {
			upwards[color] = set<string>{};
		}
		upwards[color].insert(key);
		downwards[key].insert(pair<string, int>(color, count));

		inp = matches.suffix().str();
	}
}

void traverse_tree_up(string element_to_visit, unordered_set<string> &visited) {
	visited.insert(element_to_visit);
	for (string neighbor : upwards[element_to_visit]) {
		if (visited.count(neighbor) != 0) { continue; }
		traverse_tree_up(neighbor, visited);
	}
}

int traverse_tree_down(string element_to_visit) {
	int sum = 0;
	for (pair<string, int> neighbor : downwards[element_to_visit]) {
		sum += neighbor.second;
		sum += neighbor.second * traverse_tree_down(neighbor.first);
	}
	return sum;
}


}  // namespace day7
