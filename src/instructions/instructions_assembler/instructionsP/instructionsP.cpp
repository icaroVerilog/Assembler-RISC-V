#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <boost/convert.hpp>
#include <bitset>
#include "../../instructions_structures/type_P.hpp"
#include "../../convert_methods/convert_methods.hpp"
#include "../../instruction_parser/instruction_parser.hpp"
#include "../../../accumulator/instruction_ACML.hpp"

/* P instruction means Pseudo instruction */

class P_assembler: public Convert_methods, Instruction_parser {

    private: std::string opcode_I; /* for ADDI */
    private: std::fstream output_file;
    private: std::string output_filename;
    private: std::string zero_register;
    private: std::string zero_immediate;

    private: std::string funct3_ADDI;

    public: P_assembler(std::string& output_filename){

        this -> output_filename = output_filename;
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

   
        this -> output_file.open(output_filename, std::fstream::app);

        this -> output_file << binary_immediate;
        this -> output_file << parameter_register;
        this -> output_file << this -> funct3_ADDI;
        this -> output_file << destination_register;
        this -> output_file << this -> opcode_I;
        this -> output_file << std::endl;

        this -> output_file.close();

    }
    public: void MV(std::string& string, Instruction_accumulator *accumulator){

        P_instruction instruction = P_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register = register_to_binary(instruction.parameter);
        std::string binary_immediate = immediate_to_binary(this -> zero_immediate);

        this -> output_file.open(output_filename, std::fstream::app);

        this -> output_file << binary_immediate;
        this -> output_file << parameter_register;
        this -> output_file << this -> funct3_ADDI;
        this -> output_file << destination_register;
        this -> output_file << this -> opcode_I;
        this -> output_file << std::endl;

        this -> output_file.close();
    }
};