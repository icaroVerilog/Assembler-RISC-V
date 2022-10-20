#ifndef INSTRUCTION_PARSER_HEADER
#define INSTRUCTION_PARSER_HEADER

#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <boost/convert.hpp>
#include <bitset>
#include <regex>

#include "../instructions_structures/type_I.hpp"
#include "../instructions_structures/type_L.hpp"
#include "../instructions_structures/type_P.hpp"
#include "../instructions_structures/type_R.hpp"
#include "../instructions_structures/type_S.hpp"

class Instruction_parser {
    protected: I_instruction I_type_parse (std::string& instruction);
    protected: L_instruction L_type_parse (std::string& instruction);
    protected: R_instruction R_type_parse (std::string& instruction);
    protected: P_instruction P_type_parse (std::string& instruction);
    protected: S_instruction S_type_parse (std::string& instruction);
};

#endif /* INSTRUCTION_PARSER_HEADER */