#include <string>
#ifndef type_R
#define type_R

typedef struct R_instruction R_instruction;

struct R_instruction {

    std::string operation;
    std::string destination_register;
    std::string parameter_register1;
    std::string parameter_register2;

};

#endif