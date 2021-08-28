#ifndef convert_operations
#define convert_operations

#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <boost/convert.hpp>
#include <bitset>

typedef struct I_instruction I_instruction;
typedef struct R_instruction R_instruction;
typedef struct P_instruction P_instruction;

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

class Convert_operations {

    protected: std::string register_to_binary(std::string& reg);
    protected: std::string immediate_to_binary(std::string& number);
    protected: I_instruction I_type_split (std::string& string1);
    protected: R_instruction R_type_split (std::string& string1);
    protected: P_instruction P_type_split (std::string& string1);
};

#endif /* convert_operations */