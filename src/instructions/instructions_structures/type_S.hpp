#include <string>
#ifndef TYPE_S
#define TYPE_S

typedef struct S_instruction S_instruction;

struct S_instruction {
    std::string operation;
    std::string base_memory_address_register; //rs1
    std::string data_register; //rs2
    std::string immediate;
};

#endif 