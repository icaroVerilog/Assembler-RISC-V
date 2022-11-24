#include "accumulator/instruction_ACML.hpp"
#include "inttypes.h"
#include "elfcommon.h"

/* e_ident values */

#define ELFMAG0             0x7F;
#define ELFMAG1             0x45;
#define ELFMAG2             0x4C;
#define ELFMAG3             0x46;

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