#ifndef TYPE_M
#define TYPE_M

#include <string>

typedef struct M_instruction M_instruction;

struct M_instruction {

    std::string operation;
    std::string destination_register;
    std::string parameter_register1;
    std::string parameter_register2;

};

#endif /* TYPE_M */