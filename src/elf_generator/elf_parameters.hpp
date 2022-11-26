#include "inttypes.h"

#ifndef ELF_PARAMETERS_HEADER
#define ELF_PARAMETERS_HEADER


typedef uint8_t  Elf64_Byte;
typedef uint16_t Elf64_Half;
typedef uint32_t Elf64_Word;
typedef uint64_t Elf64_Off;
typedef uint64_t Elf64_Addr;

typedef struct Elf64_Ehdr Elf64_Ehdr;


/* e_ident values */

#define ELFMAG0             0x7F;   /*          Magic number                        */
#define ELFMAG1             0x45;   /*          E                                   */
#define ELFMAG2             0x4C;   /*          L                                   */
#define ELFMAG3             0x46;   /*          F                                   */

/* EI_CLASS */
#define ELFCLASS32          0x01;
#define ELFCLASS64          0x02;
/* EI_DATA */
#define ELFDATA2LSB         0x01;   /*          Little endian */
#define ELFDATA2MSB         0x02;   /*          Big endian */
/* EI_VERSION */
#define EV_CURRENT          0x01;
/* EI_OSABI */
#define ELFOSABI_NONE       0x00;   /*          No extensions or unspecified         */
#define ELFOSABI_HPUX       0x01;   /*          Hewlett-Packard HP-UX                */
#define ELFOSABI_NETBSD     0x02;   /*          NetBSD                               */
#define ELFOSABI_LINUX      0x03;   /*          Linux                                */
#define ELFOSABI_SOLARIS    0x06;   /*          Sun Solaris                          */
#define ELFOSABI_AIX        0x07;   /*          AIX                                  */
#define ELFOSABI_IRIX       0x08;   /*          IRIX                                 */
#define ELFOSABI_FREEBSD    0x09;   /*          FreeBSD                              */
#define ELFOSABI_TRU64      0x0A;   /*          Compaq TRU64 UNIX                    */
#define ELFOSABI_MODESTO    0x0B;   /*          Novell Modesto                       */
#define ELFOSABI_OPENBSD    0x0C;   /*          Open BSD                             */
#define ELFOSABI_OPENVMS    0x0D;   /*          Open VMS                             */
#define ELFOSABI_NSK        0x0E;   /*          Hewlett-Packard Non-Stop Kernel      */
/* EI_ABIVERSION */
#define UNSPEFICIED         0x00;


/* e_type values */

#define ET_NONE             0x00;   /*          Unknown                              */
#define ET_REL              0x01;   /*          Relocatable file                     */
#define ET_EXEC             0x02;   /*          Executable file                      */
#define ET_DYN              0x03;   /*          Shared object                        */
#define ET_CORE             0x04;   /*          Core file                            */

/* e_machine values */
#define EM_RISCV            0xF3;
#define EM_X86_64           0x3E;

/* e_version values */
#define EV_CURRENT          0x01;






struct Elf64_Ehdr {
    Elf64_Byte      e_ident[16];
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
};


#endif /* ELF_PARAMETERS_HEADER */