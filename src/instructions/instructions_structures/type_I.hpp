#ifndef TYPE_I
#define TYPE_I

#include <string>

typedef struct I_instruction I_instruction;

struct I_instruction {
    std::string operation;
    std::string destination_register;
    std::string parameter_register1;
    std::string immediate;
};

#endif 