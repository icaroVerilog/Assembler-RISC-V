#ifndef ELF_GENERATOR_HEADER
#define ELF_GENERATOR_HEADER

#include <iostream>
#include <cstdio>
#include <string>

#include "../misc/messages/error_messages.hpp"
#include "elf_parameters.hpp"
#include "riscv_elf/riscv_elf.hpp"

class ELF_generator: public Riscv_elf {

    private: FILE *output_file;
    private: Elf64_Ehdr header;
    
    public: ELF_generator(std::string filename, std::string architecture);

    private: std::string generate_bss_section();
    private: std::string generate_comment_section();
    private: std::string generate_data_section();
    private: std::string generate_debug_section();
    private: std::string generate_dynamic_section();
    private: std::string generate_hash_section();
    private: std::string generate_line_section();
    private: std::string generate_note_section();
    private: std::string generate_rodata_section();
    private: std::string generate_shstrtab_section();
    private: std::string generate_strtab_section();
    private: std::string generate_symtab_section();
    private: std::string generate_text_section();

};

#endif /* ELF_GENERATOR_HEADER */