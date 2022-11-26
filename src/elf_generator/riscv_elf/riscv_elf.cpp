#include "riscv_elf.hpp"

Elf64_Ehdr Riscv_elf::get_riscv_elf_header(){

    Elf64_Ehdr header;

    header.e_ident[0]  = ELFMAG0;
    header.e_ident[1]  = ELFMAG1;
    header.e_ident[2]  = ELFMAG2;
    header.e_ident[3]  = ELFMAG3;
    header.e_ident[4]  = ELFCLASS64;
    header.e_ident[5]  = ELFDATA2MSB;
    header.e_ident[6]  = EV_CURRENT;
    header.e_ident[7]  = ELFOSABI_NONE;
    header.e_ident[8]  = UNSPEFICIED;
    header.e_ident[9]  = 0x00; /* values between 9 and 15 of EI_PAD should be 0, because is unused */
    header.e_ident[10] = 0x00;
    header.e_ident[11] = 0x00;
    header.e_ident[12] = 0x00;
    header.e_ident[13] = 0x00;
    header.e_ident[14] = 0x00;
    header.e_ident[15] = 0x00;

    header.e_type      = 0x00;
    header.e_machine   = 0x00;
    header.e_version   = 0x00;
    header.e_entry     = 0x00;
    header.e_phoff     = 0x00;
    header.e_shoff     = 0x00;
    header.e_flags     = 0x00;
    header.e_ehsize    = 0x00;
    header.e_phentsize = 0x00;
    header.e_phnum     = 0x00;
    header.e_shentsize = 0x00;
    header.e_shnum     = 0x00;
    header.e_shstrndx  = 0x00;

    return header;
}