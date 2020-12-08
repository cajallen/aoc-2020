#include "day8.hpp"

int main(int a, char** b) {
	day8::setup();
	cout << "#1: " << day8::solve1() << endl;
	cout << "#2: " << day8::solve2() << endl;
	day8::teardown();
}

namespace day8 {

vector<jmp*> instructions;
uint line_index;
int acc_total;

void setup() {
	vector<string> lines = parse_list(INPUT_FILE8);
	for (string line : lines) {
		instructions.push_back(instruction_factory(line));
	}
}

void teardown() {
	for (jmp* e : instructions) {
		delete e;
	}
	instructions = vector<jmp*>{};
}

int solve1() {
	reset_instructions();
	while (line_index < instructions.size()) {
		if (instructions[line_index]->executed) { break; }
		instructions[line_index]->execute();
	}
	return acc_total;
}

int solve2() {
	for (uint swap_index = 0; swap_index < instructions.size(); swap_index++) {
		if (dynamic_cast<acc*>(instructions[swap_index]) != NULL) { continue; }
		if (instructions[swap_index]->next_offset == 0) { continue; }

		reset_instructions();
		while (line_index < instructions.size()) {
			if (instructions[line_index]->executed) { break; }

			if (line_index == swap_index) {
				jmp* jmp_p = dynamic_cast<jmp*>(instructions[line_index]);
				nop* nop_p = dynamic_cast<nop*>(instructions[line_index]);
				if (nop_p == NULL) {
					nop(jmp_p->argument).execute();
				} else {
					jmp(nop_p->argument).execute();
				}
				continue;
			}

			instructions[line_index]->execute();
		}
		
		if (line_index >= instructions.size()) {
			return acc_total;
		}
	}
	return -1;
}


void reset_instructions() {
	line_index = 0;
	acc_total = 0;
	for (jmp* jmp_p : instructions) {
		jmp_p->executed = false;
	}
}


jmp::jmp(int arg) {
	next_offset = arg;
	argument = arg;
}

bool jmp::execute() {
	line_index += next_offset;
	executed = true;
	return true;
}

acc::acc(int arg) {
	next_offset = 1;
	argument = arg;
}

bool acc::execute() {
	jmp::execute();
	acc_total += argument;
	return true;
}

nop::nop(int arg) {
	next_offset = 1;
	argument = arg;
}

jmp* instruction_factory(string line) {
	vector<string> inputs = split(line, ' ');
	string operation = inputs.at(0);
	int argument = stoi(inputs.at(1));

	if (operation == "jmp" ) {
		return new jmp(argument);
	} else if (operation == "acc") {
		return new acc(argument);
	} else if (operation == "nop") {
		return new nop(argument);
	} else {
		throw new invalid_argument("Instruction factory can only make jmp, acc, nop, not " + line);
	}
	return new nop(0);
}

}