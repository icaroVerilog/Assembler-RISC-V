#ifndef instruction_parser
#define instruction_parser

#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <boost/convert.hpp>
#include <bitset>
#include <regex>

#include "../instructions/instructions_structures/type_I.hpp"
#include "../instructions/instructions_structures/type_L.hpp"
#include "../instructions/instructions_structures/type_P.hpp"
#include "../instructions/instructions_structures/type_R.hpp"

class Instruction_parser {
    protected: I_instruction I_type_parse (std::string& instruction);
    protected: L_instruction L_type_parse (std::string& instruction);
    protected: R_instruction R_type_parse (std::string& instruction);
    protected: P_instruction P_type_parse (std::string& instruction);
};

#endif /* instruction_parser */