#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <boost/convert.hpp>
#include <bitset>
#include "../../instructions_structures/type_R.hpp"
#include "../../convert_methods/convert_methods.hpp"
#include "../../instruction_parser/instruction_parser.hpp"
#include "../../../accumulator/instruction_ACML.hpp"

class R_assembler: public Convert_methods, public Instruction_parser {

    private: std::string opcode_R;
    private: std::fstream output_file;
    private: std::string output_filename;
    private: std::string assembled_binary;

    private:
        std::string funct7_ADD;
        std::string funct7_SUB;
        std::string funct7_XOR;
        std::string funct7_OR;
        std::string funct7_AND;
        std::string funct7_SLL;
        std::string funct7_SRL;

        std::string funct3_ADD;
        std::string funct3_SUB;
        std::string funct3_XOR;
        std::string funct3_OR;
        std::string funct3_AND;
        std::string funct3_SLL;
        std::string funct3_SRL;

    public: R_assembler(){

        this -> opcode_R.assign("0110011");
        
        this -> funct7_ADD.assign("0000000");
        this -> funct7_SUB.assign("0100000");
        this -> funct7_XOR.assign("0000000");
        this -> funct7_OR.assign ("0000000");
        this -> funct7_AND.assign("0000000");
        this -> funct7_SLL.assign("0000000");
        this -> funct7_SRL.assign("0000000");

        this -> funct3_ADD.assign("000");
        this -> funct3_SUB.assign("000");
        this -> funct3_XOR.assign("100");
        this -> funct3_OR.assign ("110");
        this -> funct3_AND.assign("111");
        this -> funct3_SLL.assign("001");
        this -> funct3_SRL.assign("101");
    }

    public: void ADD(std::string& string, Instruction_accumulator* accumulator){

        R_instruction instruction = R_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        std::string assembled_binary = r_binary_to_string(
            this -> funct7_ADD, 
            parameter_register1, 
            parameter_register2, 
            this -> funct3_ADD, 
            destination_register, 
            opcode_R
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void SUB(std::string& string, Instruction_accumulator* accumulator){

        R_instruction instruction = R_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        std::string assembled_binary = r_binary_to_string(
            this -> funct7_SUB, 
            parameter_register1, 
            parameter_register2, 
            this -> funct3_SUB, 
            destination_register, 
            opcode_R
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void AND(std::string& string, Instruction_accumulator* accumulator){

        R_instruction instruction = R_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        std::string assembled_binary = r_binary_to_string(
            this -> funct7_AND, 
            parameter_register1, 
            parameter_register2, 
            this -> funct3_AND, 
            destination_register, 
            opcode_R
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void OR(std::string& string, Instruction_accumulator* accumulator){

        R_instruction instruction = R_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        std::string assembled_binary = r_binary_to_string(
            this -> funct7_OR, 
            parameter_register1, 
            parameter_register2, 
            this -> funct3_OR, 
            destination_register, 
            opcode_R
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void XOR(std::string& string, Instruction_accumulator* accumulator){

        R_instruction instruction = R_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        std::string assembled_binary = r_binary_to_string(
            this -> funct7_XOR, 
            parameter_register1, 
            parameter_register2, 
            this -> funct3_XOR, 
            destination_register, 
            opcode_R
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void SLL(std::string& string, Instruction_accumulator* accumulator){

        R_instruction instruction = R_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        std::string assembled_binary = r_binary_to_string(
            this -> funct7_SLL, 
            parameter_register1, 
            parameter_register2, 
            this -> funct3_SLL, 
            destination_register, 
            opcode_R
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void SRL(std::string& string, Instruction_accumulator* accumulator){

        R_instruction instruction = R_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        std::string assembled_binary = r_binary_to_string(
            this -> funct7_SRL, 
            parameter_register1, 
            parameter_register2, 
            this -> funct3_SRL, 
            destination_register, 
            opcode_R
        );

        accumulator -> set_instruction(assembled_binary);
    }
};