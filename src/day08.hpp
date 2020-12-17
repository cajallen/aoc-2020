#ifndef DAY_8_
#define DAY_8_

#define INPUT_FILE08 "data/day08_input.txt"

#include <string>
#include <vector>
#include <iostream>
#include "basic_parser.hpp"

using namespace std;

int main(int, char**) __attribute__((weak));

namespace day08 {

class instr {
 public:
	instr() { }
	instr(string line);
	~instr() { }

	void execute();
	bool is_acc();
	bool is_jmp();

	void swap_jmp_nop();

	int argument = -1;
	int next_offset = 1;
	int acc_increase = 0;
	bool executed = false;
};

ostream& operator << (ostream& os, const instr& i);

void setup();
void teardown();
int solve1();
int solve2();

void reset_instructions();

}

#endif