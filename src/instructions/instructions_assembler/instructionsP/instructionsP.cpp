#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <boost/convert.hpp>
#include <bitset>
#include "../../instructions_structures/type_P.hpp"
#include "../../convert_methods/convert_methods.hpp"
#include "../../instruction_parser/instruction_parser.hpp"
#include "../../../accumulator/instruction_accumulator.hpp"

/* P instruction means Pseudo instruction */

class P_assembler: public Convert_methods, Instruction_parser {

    private: std::string opcode_I; /* for ADDI */
    private: std::string zero_register;
    private: std::string zero_immediate;

    private: std::string funct3_ADDI;

    public: P_assembler(){

        this -> opcode_I.assign("0010011");
        this -> funct3_ADDI.assign("000");
        this -> zero_register = "x1";
        this -> zero_immediate.assign("0");

    }
    public: void LI(std::string& string, Instruction_accumulator *accumulator){
        
        P_instruction instruction = P_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register = register_to_binary(this -> zero_register);
        std::string binary_immediate = immediate_to_binary(instruction.parameter);

        std::string assembled_binary = i_binary_to_string(
            binary_immediate,
            parameter_register,
            this -> funct3_ADDI,
            destination_register,
            this -> opcode_I
        );
        
        accumulator -> set_instruction(assembled_binary);
    }

    public: void MV(std::string& string, Instruction_accumulator *accumulator){

        P_instruction instruction = P_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register = register_to_binary(instruction.parameter);
        std::string binary_immediate = immediate_to_binary(this -> zero_immediate);

        std::string assembled_binary = i_binary_to_string(
            binary_immediate,
            parameter_register,
            this -> funct3_ADDI,
            destination_register,
            this -> opcode_I
        );

        accumulator -> set_instruction(assembled_binary);
    }
};