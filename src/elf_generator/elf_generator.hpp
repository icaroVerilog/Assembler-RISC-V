#include "accumulator/instruction_ACML.hpp"
#include "inttypes.h"
#include "elfcommon.h"


#define EIPAD_BIT_SIZE 56;

struct {
    uint8_t   EI_MAG0                   = 0x7f;
    uint8_t   EI_MAG1                   = 0x45;
    uint8_t   EI_MAG2                   = 0x4c;
    uint8_t   EI_MAG3                   = 0x46;
    uint8_t   EI_CLASS                  = 0x02;
    uint8_t   EI_DATA                   = 0x01;
    uint8_t   EI_VERSION                = 0x01;
    uint8_t   EI_OSABI                  = 0x03;
    uint8_t   EI_ABIVERSION             = 0x08;
    uint64_t  EI_PAD: EIPAD_BIT_SIZE    = 0x00;
} e_ident;

struct {
    Elf64_I         e_ident;
    Elf64_Half      e_type      = 0x02;
    Elf64_Half      e_machine   = 0xf3;
    Elf64_Word      e_version   = 0x01;
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