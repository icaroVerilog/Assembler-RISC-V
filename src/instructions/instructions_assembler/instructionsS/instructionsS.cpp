#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <boost/convert.hpp>
#include <bitset>
#include "../../instructions_structures/type_S.hpp"
#include "../../convert_methods/convert_methods.hpp"
#include "../../instruction_parser/instruction_parser.hpp"
#include "../../../accumulator/instruction_ACML.hpp"

class S_assembler: public Convert_methods, Instruction_parser {

    private: std::string opcode_S;
    private: std::string output_filename;
    private: std::fstream output_file;

    private:
        std::string funct3_SB;
        std::string funct3_SH;
        std::string funct3_SW;
        std::string funct3_SD;

    public: S_assembler(){

        this -> output_filename = output_filename;
        this -> opcode_S.assign("0100011");

        this -> funct3_SB.assign("000");
        this -> funct3_SH.assign("001");
        this -> funct3_SW.assign("010");
        this -> funct3_SD.assign("011");
    }

    public: void SB(std::string& string, Instruction_accumulator* accumulator){
        
        S_instruction instruction = S_type_parse(string);

        std::string binary_immediate = immediate_to_binary(instruction.immediate);
        std::string memory_address_register = register_to_binary(instruction.base_memory_address_register);
        std::string data_register = register_to_binary(instruction.data_register);

        std::string assembled_binary = s_binary_to_string(
            binary_immediate,
            data_register,
            this -> funct3_SB,
            memory_address_register,
            this -> opcode_S
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void SH(std::string& string, Instruction_accumulator* accumulator){

        S_instruction instruction = S_type_parse(string);

        std::string binary_immediate = immediate_to_binary(instruction.immediate);
        std::string memory_address_register = register_to_binary(instruction.base_memory_address_register);
        std::string data_register = register_to_binary(instruction.data_register);

        std::string assembled_binary = s_binary_to_string(
            binary_immediate,
            data_register,
            this -> funct3_SH,
            memory_address_register,
            this -> opcode_S
        );

        accumulator -> set_instruction(assembled_binary);

    }

    public: void SW(std::string& string, Instruction_accumulator* accumulator){

        S_instruction instruction = S_type_parse(string);

        std::string binary_immediate = immediate_to_binary(instruction.immediate);
        std::string memory_address_register = register_to_binary(instruction.base_memory_address_register);
        std::string data_register = register_to_binary(instruction.data_register);

        std::string assembled_binary = s_binary_to_string(
            binary_immediate,
            data_register,
            this -> funct3_SW,
            memory_address_register,
            this -> opcode_S
        );

        accumulator -> set_instruction(assembled_binary);

    }

    public: void SD(std::string& string, Instruction_accumulator* accumulator){

        S_instruction instruction = S_type_parse(string);

        std::string binary_immediate = immediate_to_binary(instruction.immediate);
        std::string memory_address_register = register_to_binary(instruction.base_memory_address_register);
        std::string data_register = register_to_binary(instruction.data_register);

        std::string assembled_binary = s_binary_to_string(
            binary_immediate,
            data_register,
            this -> funct3_SD,
            memory_address_register,
            this -> opcode_S
        );

        accumulator -> set_instruction(assembled_binary);

    }
};