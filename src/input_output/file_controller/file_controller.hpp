#include <iostream>
#include <fstream>
#include "../../accumulator/instruction_accumulator.hpp"

#ifndef FILE_CONTROLLER_HEADER
#define FILE_CONTROLLER_HEADER


class File_controller {
    public: File_controller();
    public: int write(Instruction_accumulator *accumulator, std::string filename);
    public: void read(std::fstream *file, std::string filename);
};

#endif /* FILE_CONTROLLER_HEADER */
