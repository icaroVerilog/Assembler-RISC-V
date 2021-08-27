#include <iostream>
#include <string>
#include <cstddef>
#include <vector>
#include "instruction_accumulator.cpp"

class Label_accumulator: public Instruction_accumulator {

    public: std::string label_name;

};