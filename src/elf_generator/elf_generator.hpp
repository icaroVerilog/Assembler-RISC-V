#include <iostream>
#include <cstdio>
#include <string>

#include "../misc/messages/error_messages.hpp"
#include "elf_parameters.hpp"
#include "riscv_elf/riscv_elf.hpp"

#ifndef ELF_GENERATOR_HEADER
#define ELF_GENERATOR_HEADER
class ELF_generator: public Riscv_elf {

    private: FILE *output_file;
    
    public: ELF_generator(std::string filename);

};

#endif /* ELF_GENERATOR_HEADER */