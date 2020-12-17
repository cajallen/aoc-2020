#include "day8.hpp"


int main(int a, char** b) {
	day8::setup();
	cout << "#1: " << day8::solve1() << endl;
	cout << "#2: " << day8::solve2() << endl;
}



namespace day8 {


vector<instr> instructions;
uint line_index;
int acc_total;


void setup() {
	vector<string> lines = parse_list<string>(INPUT_FILE8);
	instructions = vector<instr>{};
	for (string line : lines) {
		instructions.push_back(instr(line));
	}
}

int solve1() {
	reset_instructions();
	while (line_index < instructions.size()) {
		if (instructions[line_index].executed) { break; }
		instructions[line_index].execute();
	}
	return acc_total;
}

int solve2() {
	for (uint swap_index = 0; swap_index < instructions.size(); swap_index++) {
		// set up swap
		if (instructions[swap_index].argument == 0) { continue; }
		if (instructions[swap_index].is_acc()) { continue; }
		instructions[swap_index].swap_jmp_nop();
		
		// execute commands
		reset_instructions();
		while (line_index < instructions.size()) {
			if (instructions[line_index].executed) { break; }

			instructions[line_index].execute();
		}

		instructions[swap_index].swap_jmp_nop();
		if (line_index >= instructions.size()) {
			return acc_total;
		}
	}
	return -1;
}

instr::instr(string line) {
	vector<string> args = split(line, ' ');
	argument = stoi(args.at(1));
	if (args.at(0) == "acc") {
		acc_increase = argument;
	} else if (args.at(0) == "jmp") {
		next_offset = argument;
	}
}

void instr::execute() {
	acc_total += acc_increase;
	line_index += next_offset;
	executed = true;
}

bool instr::is_acc() {
	return acc_increase != 0;
}

bool instr::is_jmp() {
	return next_offset != 1;
}

void instr::swap_jmp_nop() {
	if (is_jmp()) {
		next_offset = 1;
	} else {
		next_offset = argument;
	}
}

void reset_instructions() {
	line_index = 0;
	acc_total = 0;
	for (uint i = 0; i < instructions.size(); i++) {
		instructions[i].executed = false;
	}
}

ostream& operator << (ostream& os, const instr& i) {
	os << "arg:" << i.argument << ", offset:" << i.next_offset << ", acc:" << i.acc_increase << ", exe:" << i.executed;
	return os;
}

}  // namespace day8
