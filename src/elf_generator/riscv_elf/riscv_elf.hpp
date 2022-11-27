#ifndef RISCV_ELF_HEADER
#define RISCV_ELF_HEADER

#include "inttypes.h"
#include "../elf_parameters.hpp"


class Riscv_elf {
    protected: Elf64_Ehdr get_riscv_elf_header();
};

#endif /* RISCV_ELF_HEADER */