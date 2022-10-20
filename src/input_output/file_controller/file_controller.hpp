#include <iostream>
#include <fstream>
#include "../../accumulator/instruction_ACML.hpp"

class File_controller {
    public: File_controller();
    public: int write(Instruction_accumulator *accumulator, std::string filename);
    public: int read(std::fstream *file, std::string filename);
};
