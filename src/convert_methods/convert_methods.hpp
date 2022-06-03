#ifndef conversion_methods
#define conversion_methods

#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <boost/convert.hpp>
#include <bitset>
#include <regex>

typedef struct I_instruction I_instruction;
typedef struct R_instruction R_instruction;
typedef struct P_instruction P_instruction;

struct L_instruction {

    std::string operation;
    std::string destination_register;
    std::string pointer_register;
    std::string jump_immediate;

};

struct I_instruction {

    std::string operation;
    std::string destination_register;
    std::string parameter_register1;
    std::string immediate;

};

struct R_instruction {

    std::string operation;
    std::string destination_register;
    std::string parameter_register1;
    std::string parameter_register2;

};

struct P_instruction {

    std::string operation;
    std::string destination_register;
    std::string parameter;
};

class Conversion_methods {
    protected: std::string register_to_binary(std::string& reg);
    protected: std::string immediate_to_binary(std::string& number);
};

#endif /* conversion_methods */