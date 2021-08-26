#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <boost/convert.hpp>
#include <bitset>

/* P instruction means Pseudo instruction */

typedef struct P_instruction P_instruction;

struct P_instruction {

    std::string operation;
    std::string destination_register;
    std::string parameter_register;

};

class P_assembler {

    public: void li(std::string& string, bool print_flag){
        
    }
    public: void mv(std::string& string, bool print_flag){

    }
    
};