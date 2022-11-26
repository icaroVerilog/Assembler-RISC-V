#include <string>


#ifndef ERROR_MESSAGES_HEADER
#define ERROR_MESSAGES_HEADER

namespace error_messages {

    const std::string R_TYPE_ASSEMBLER_ERROR    = "assembler error: invalid type R struction format";
    const std::string I_TYPE_ASSEMBLER_ERROR    = "assembler error: invalid type I struction format";
    const std::string S_TYPE_ASSEMBLER_ERROR    = "assembler error: invalid type S struction format";
    const std::string B_TYPE_ASSEMBLER_ERROR    = "assembler error: invalid type B struction format";

    const std::string INVALID_INSTRUCTION       = "assembler error: invalid instruction (unsupported instruction)";
    const std::string INVALID_REGISTER          = "assembler error: invalid register";
    const std::string INVALID_HEX_IMMEDIATE     = "assembler error: invalid hexadecimal value in immediate field";
    const std::string INVALID_BIN_IMMEDIATE     = "assembler error: invalid binary value in immediate field";
    const std::string INVALID_DEC_IMMEDIATE     = "assembler error: invalid decimal value in immediate field";

    const std::string INVALID_INPUT_FILE_FORMAT = "parameter error: invalid input file format";
    const std::string OPEN_INPUT_FILE_ERROR     = "runtime error: cannot open input file";
    const std::string OPEN_OUTPUT_FILE_ERROR    = "runtime error: cannot open output file";

    const std::string INVALID_LABEL_ERROR       = "assembler error: invalid instruction label, unknow label";
}


#endif /* ERROR_MESSAGES_HEADER */