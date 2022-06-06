#include <string>
#ifndef type_P
#define type_P

typedef struct P_instruction P_instruction;

struct P_instruction {

    std::string operation;
    std::string destination_register;
    std::string parameter;
};

#endif