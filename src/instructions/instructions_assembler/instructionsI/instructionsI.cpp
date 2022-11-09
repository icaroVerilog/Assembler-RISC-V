#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <boost/convert.hpp>
#include <bitset>
#include "../../instructions_structures/type_B.hpp"
#include "../../convert_methods/convert_methods.hpp"
#include "../../instruction_parser/instruction_parser.hpp"
#include "../../../accumulator/instruction_ACML.hpp"

class I_assembler: public Convert_methods, public Instruction_parser {

    private: std::string opcode_I;

    private:
        std::string funct3_ADDI;
        std::string funct3_ANDI;
        std::string funct3_ORI;
        std::string funct3_XORI;
        std::string funct3_SLLI;
        std::string funct3_SRLI;

    public: I_assembler(){

        this -> opcode_I.assign("0010011");

        this -> funct3_ADDI.assign("000");
        this -> funct3_ANDI.assign("111");
        this -> funct3_ORI.assign("110");
        this -> funct3_XORI.assign("100");
        this -> funct3_SLLI.assign("001");
        this -> funct3_SRLI.assign("101");        
    }

    public: void ADDI(std::string& string, Instruction_accumulator* accumulator){

        I_instruction instruction = I_type_parse(string);

        std::string binary_immediate = immediate_to_binary(instruction.immediate);
        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);

        std::string assembled_binary = i_binary_to_string(
            binary_immediate,
            parameter_register1,
            this -> funct3_ADDI,
            destination_register,
            this -> opcode_I
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void ANDI(std::string& string, Instruction_accumulator* accumulator){

        I_instruction instruction = I_type_parse(string);

        std::string binary_immediate = immediate_to_binary(instruction.immediate);
        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);

        std::string assembled_binary = i_binary_to_string(
            binary_immediate,
            parameter_register1,
            this -> funct3_ANDI,
            destination_register,
            this -> opcode_I
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void ORI(std::string& string, Instruction_accumulator* accumulator){

        I_instruction instruction = I_type_parse(string);

        std::string binary_immediate = immediate_to_binary(instruction.immediate);
        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);

        std::string assembled_binary = i_binary_to_string(
            binary_immediate,
            parameter_register1,
            this -> funct3_ANDI,
            destination_register,
            this -> opcode_I
        );
        
        accumulator -> set_instruction(assembled_binary);
    }

    public: void XORI(std::string& string, Instruction_accumulator* accumulator){

        I_instruction instruction = I_type_parse(string);

        std::string binary_immediate = immediate_to_binary(instruction.immediate);
        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);

        std::string assembled_binary = i_binary_to_string(
            binary_immediate,
            parameter_register1,
            this -> funct3_ANDI,
            destination_register,
            this -> opcode_I
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void SLLI(std::string& string, Instruction_accumulator* accumulator){

        I_instruction instruction = I_type_parse(string);

        std::string binary_immediate = immediate_to_binary(instruction.immediate);
        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);

        std::string assembled_binary = i_binary_to_string(
            binary_immediate,
            parameter_register1,
            this -> funct3_ANDI,
            destination_register,
            this -> opcode_I
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void SRLI(std::string& string, Instruction_accumulator* accumulator){

        I_instruction instruction = I_type_parse(string);

        std::string binary_immediate = immediate_to_binary(instruction.immediate);
        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);

        std::string assembled_binary = i_binary_to_string(
            binary_immediate,
            parameter_register1,
            this -> funct3_ANDI,
            destination_register,
            this -> opcode_I
        );

        accumulator -> set_instruction(assembled_binary);
    }
};