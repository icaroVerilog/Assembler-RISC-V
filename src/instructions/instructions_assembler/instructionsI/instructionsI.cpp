#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <boost/convert.hpp>
#include <bitset>
#include "../../instructions_structures/type_I.hpp"
#include "../../../convert_methods/convert_methods.hpp"
#include "../../../instruction_parser/instruction_parser.hpp"


class I_assembler: public Convert_methods, public Instruction_parser {

    private: std::string opcode_I;
    private: std::fstream output_file;
    private: std::string output_filename;

    private:
        std::string funct3_ADDI;
        std::string funct3_ANDI;
        std::string funct3_ORI;
        std::string funct3_XORI;
        std::string funct3_SLLI;
        std::string funct3_SRLI;

    public: I_assembler(std::string& output_filename){

        this -> output_filename = output_filename;
        this -> opcode_I.assign("0010011");

        this -> funct3_ADDI.assign("000");
        this -> funct3_ANDI.assign("111");
        this ->  funct3_ORI.assign("110");
        this -> funct3_XORI.assign("100");
        this -> funct3_SLLI.assign("001");
        this -> funct3_SRLI.assign("101");        
    }

    public: void ADDI(std::string& string){

        I_instruction instruction = I_type_parse(string);

        std::string binary_immediate = immediate_to_binary(instruction.immediate);
        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);

            
        this -> output_file.open(output_filename, std::fstream::app);

        this -> output_file << binary_immediate;
        this -> output_file << parameter_register1;
        this -> output_file << this -> funct3_ADDI;
        this -> output_file << destination_register;
        this -> output_file << this -> opcode_I;
        this -> output_file << std::endl;

        this -> output_file.close();
    }
    public: void ANDI(std::string& string){

        I_instruction instruction = I_type_parse(string);

        std::string binary_immediate = immediate_to_binary(instruction.immediate);
        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);


        this -> output_file.open(output_filename, std::fstream::app);

        this -> output_file << binary_immediate;
        this -> output_file << parameter_register1;
        this -> output_file << this -> funct3_ANDI;
        this -> output_file << destination_register;
        this -> output_file << this -> opcode_I;
        this -> output_file << std::endl;

        this -> output_file.close();
    }
    public: void ORI(std::string& string){

        I_instruction instruction = I_type_parse(string);

        std::string binary_immediate = immediate_to_binary(instruction.immediate);
        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);

        this -> output_file.open(output_filename, std::fstream::app);

        this -> output_file << binary_immediate;
        this -> output_file << parameter_register1;
        this -> output_file << this -> funct3_ORI;
        this -> output_file << destination_register;
        this -> output_file << this -> opcode_I;
        this -> output_file << std::endl;

        this -> output_file.close();
    }
    public: void XORI(std::string& string){

        I_instruction instruction = I_type_parse(string);

        std::string binary_immediate = immediate_to_binary(instruction.immediate);
        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);


        this -> output_file.open(output_filename, std::fstream::app);

        this -> output_file << binary_immediate;
        this -> output_file << parameter_register1;
        this -> output_file << this -> funct3_XORI;
        this -> output_file << destination_register;
        this -> output_file << this -> opcode_I;
        this -> output_file << std::endl;

        this -> output_file.close();
    }
    public: void SLLI(std::string& string){

        I_instruction instruction = I_type_parse(string);

        std::string binary_immediate = immediate_to_binary(instruction.immediate);
        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);

        this -> output_file.open(output_filename, std::fstream::app);

        this -> output_file << binary_immediate;
        this -> output_file << parameter_register1;
        this -> output_file << this -> funct3_SLLI;
        this -> output_file << destination_register;
        this -> output_file << this -> opcode_I;
        this -> output_file << std::endl;

        this -> output_file.close();
    }
    public: void SRLI(std::string& string){

        I_instruction instruction = I_type_parse(string);

        std::string binary_immediate = immediate_to_binary(instruction.immediate);
        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);


        this -> output_file.open(output_filename, std::fstream::app);

        this -> output_file << binary_immediate;
        this -> output_file << parameter_register1;
        this -> output_file << this -> funct3_SRLI;
        this -> output_file << destination_register;
        this -> output_file << this -> opcode_I;
        this -> output_file << std::endl;

        this -> output_file.close();
    }
};