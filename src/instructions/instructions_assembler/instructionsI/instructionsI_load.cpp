#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <boost/convert.hpp>
#include <bitset>
#include "../../instructions_structures/type_L.hpp"
#include "../../convert_methods/convert_methods.hpp"
#include "../../instruction_parser/instruction_parser.hpp"
#include "../../../accumulator/instruction_ACML.hpp"

class L_assembler: public Convert_methods, Instruction_parser {

    private: std::string opcode_I_load;

    private:
        std::string funct3_LB;
        std::string funct3_LH;
        std::string funct3_LW;
        std::string funct3_LD;

    public: L_assembler(){

        this -> opcode_I_load.assign("0000011");

        this -> funct3_LB.assign("000");
        this -> funct3_LH.assign("001");
        this -> funct3_LW.assign("010");
        this -> funct3_LD.assign("011");
    }

    public: void LB(std::string& string, Instruction_accumulator *accumulator){
        
        L_instruction instruction = L_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.pointer_register);
        std::string binary_immediate = immediate_to_binary(instruction.jump_immediate);

        std::string assembled_binary = l_binary_to_string(
            binary_immediate,
            parameter_register1,
            this -> funct3_LB,
            destination_register,
            this -> opcode_I_load
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void LH(std::string& string, Instruction_accumulator *accumulator){
        
        L_instruction instruction = L_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.pointer_register);
        std::string binary_immediate = immediate_to_binary(instruction.jump_immediate);

        std::string assembled_binary = l_binary_to_string(
            binary_immediate,
            parameter_register1,
            this -> funct3_LH,
            destination_register,
            this -> opcode_I_load
        );

        accumulator -> set_instruction(assembled_binary);
    }
    
    public: void LW(std::string& string, Instruction_accumulator *accumulator){
        
        L_instruction instruction = L_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.pointer_register);
        std::string binary_immediate = immediate_to_binary(instruction.jump_immediate);

        std::string assembled_binary = l_binary_to_string(
            binary_immediate,
            parameter_register1,
            this -> funct3_LW,
            destination_register,
            this -> opcode_I_load
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void LD(std::string& string, Instruction_accumulator *accumulator){
        
        L_instruction instruction = L_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.pointer_register);
        std::string binary_immediate = immediate_to_binary(instruction.jump_immediate);

        std::string assembled_binary = l_binary_to_string(
            binary_immediate,
            parameter_register1,
            this -> funct3_LD,
            destination_register,
            this -> opcode_I_load
        );

        accumulator -> set_instruction(assembled_binary);
    }
};