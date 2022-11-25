#include "accumulator/instruction_ACML.hpp"
#include "inttypes.h"


typedef uint16_t Elf64_Half;
typedef uint32_t Elf64_Word;
typedef uint64_t Elf64_Off;
typedef uint64_t Elf64_Addr;

typedef struct Elf64_Ehdr Elf64_Ehdr;



/* e_ident values */

#define ELFMAG0             0x7F;   /* magic number */
#define ELFMAG1             0x45;   /* E */
#define ELFMAG2             0x4C;   /* L */
#define ELFMAG3             0x46;   /* F */

#define ELFCLASS32          0x01;
#define ELFCLASS64          0x02;

#define ELFDATA2LSB         0x01;  /* little endian */
#define ELFDATA2MSB         0x02;  /* big endian */












struct {
    uint8_t         e_ident[16];
    Elf64_Half      e_type;
    Elf64_Half      e_machine;
    Elf64_Word      e_version;
    Elf64_Addr      e_entry;
    Elf64_Off       e_phoff;
    Elf64_Off       e_shoff;
    Elf64_Word      e_flags;
    Elf64_Half      e_ehsize;
    Elf64_Half      e_phentsize;
    Elf64_Half      e_phnum;
    Elf64_Half      e_shentsize;
    Elf64_Half      e_shnum;
    Elf64_Half      e_shstrndx;
} Elf64_Ehdr;




class ELF_generator {

    private: std::fstream output_file;
    
    public: ELF_generator(std::string filename);


    private: int write_elf_header();

}