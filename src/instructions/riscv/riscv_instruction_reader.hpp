#ifndef RISCV_INSTRUCTION_READER_HEADER
#define RISCV_INSTRUCTION_READER_HEADER

#include "../../accumulator/instruction_accumulator.hpp"
#include "../../accumulator/label_accumulator.hpp"

#include "instructions_assembler/instructionsI/instructionsI.cpp"
#include "instructions_assembler/instructionsB/instructionsB.cpp"
#include "instructions_assembler/instructionsR/instructionsR.cpp"
#include "instructions_assembler/instructionsP/instructionsP.cpp"
#include "instructions_assembler/instructionsS/instructionsS.cpp"
#include "instructions_assembler/instructionsI/instructionsI_load.cpp"
#include "instructions_assembler/extensions/instructionsM/instructionsM.cpp"

class Riscv_instruction_reader {
    public: void execute(
        Instruction_accumulator  *instructions, 
        Instruction_accumulator  *output, 
        Label_accumulator        *labels
    );
};

#endif