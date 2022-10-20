#include <iostream>
#include <string>
#include <cstddef>
#include <vector>

#ifndef INSTRUCTION_ACCUMULATOR_HEADER
#define INSTRUCTION_ACCUMULATOR_HEADER

class Instruction_accumulator {
    private: std::vector<std::string> instructions_vector;
    private: unsigned int counter;

    public: Instruction_accumulator();
    public: void set_instruction(std::string& instruction);
    public: int get_instruction(std::string *instruction);
    public: int size();
};

#endif