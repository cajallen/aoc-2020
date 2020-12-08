#ifndef DAY_8_
#define DAY_8_

#define INPUT_FILE8 "data/day8_input.txt"

#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include "basic_parser.hpp"

using namespace std;

int main(int, char**) __attribute__((weak));

namespace day8 {

class jmp {
 public:
	jmp() { }
    jmp(int arg);
	virtual ~jmp() { }
    virtual bool execute();
    int next_offset = 1;
	int argument = 0;
	bool executed = false;
};

class acc : public jmp {
 public:
	acc() { }
    acc(int arg);
	~acc() { }
    bool execute();
};

class nop : public jmp {
 public:
	nop() { }
    nop(int arg);
	~nop() { }
};

void setup();
void teardown();
int solve1();
int solve2();

jmp* instruction_factory(string line);
void reset_instructions();

}

#endif