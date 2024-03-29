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
#include "../instructions_structures/type_B.hpp"
#include "../instructions_structures/type_M.hpp"

class Instruction_parser {
    /* base RISCV instructions formats */
    protected: I_instruction I_type_parse (std::string& instruction);
    protected: L_instruction L_type_parse (std::string& instruction);
    protected: R_instruction R_type_parse (std::string& instruction);
    protected: P_instruction P_type_parse (std::string& instruction);
    protected: S_instruction S_type_parse (std::string& instruction);
    protected: B_instruction B_type_parse (std::string& instruction);

    /* M standard extension for integer multiplication and division */
    protected: M_instruction M_type_parse (std::string& instruction);


};

#endif /* INSTRUCTION_PARSER_HEADER */