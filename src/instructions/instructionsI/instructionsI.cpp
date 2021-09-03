#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <boost/convert.hpp>
#include <bitset>
#include "../convert_operations.hpp"


class I_assembler: public Convert_operations {

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

    public: void ADDI(std::string& string, bool print_flag){

        I_instruction instruction = I_type_split(string);

        std::string binary_immediate = immediate_to_binary(instruction.immediate);
        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);

        if (print_flag == false){
            
            this -> output_file.open(output_filename, std::fstream::app);

            this -> output_file << binary_immediate;
            this -> output_file << parameter_register1;
            this -> output_file << this -> funct3_ADDI;
            this -> output_file << destination_register;
            this -> output_file << this -> opcode_I;
            this -> output_file << std::endl;

            this -> output_file.close();
        }

        if (print_flag == true){

            std::string output;

            output.append(binary_immediate);
            output.append(parameter_register1);
            output.append(this -> funct3_ADDI);
            output.append(destination_register);
            output.append(this -> opcode_I);

            std::cout << output << std::endl;
        }
    }
    public: void ANDI(std::string& string, bool print_flag){

        I_instruction instruction = I_type_split(string);

        std::string binary_immediate = immediate_to_binary(instruction.immediate);
        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);

        if (print_flag == false){

            this -> output_file.open(output_filename, std::fstream::app);

            this -> output_file << binary_immediate;
            this -> output_file << parameter_register1;
            this -> output_file << this -> funct3_ANDI;
            this -> output_file << destination_register;
            this -> output_file << this -> opcode_I;
            this -> output_file << std::endl;

            this -> output_file.close();
        }

        if (print_flag == true){

            std::string output;

            output.append(binary_immediate);
            output.append(parameter_register1);
            output.append(this -> funct3_ANDI);
            output.append(destination_register);
            output.append(this -> opcode_I);

            std::cout << output << std::endl;
        }
    }
    public: void ORI(std::string& string, bool print_flag){

        I_instruction instruction = I_type_split(string);

        std::string binary_immediate = immediate_to_binary(instruction.immediate);
        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);

        if (print_flag == false){

            this -> output_file.open(output_filename, std::fstream::app);

            this -> output_file << binary_immediate;
            this -> output_file << parameter_register1;
            this -> output_file << this -> funct3_ORI;
            this -> output_file << destination_register;
            this -> output_file << this -> opcode_I;
            this -> output_file << std::endl;

            this -> output_file.close();
        }

        if (print_flag == true){

            std::string output;

            output.append(binary_immediate);
            output.append(parameter_register1);
            output.append(this -> funct3_ORI);
            output.append(destination_register);
            output.append(this -> opcode_I);

            std::cout << output << std::endl;
        }
    }
    public: void XORI(std::string& string, bool print_flag){

        I_instruction instruction = I_type_split(string);

        std::string binary_immediate = immediate_to_binary(instruction.immediate);
        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);

        if (print_flag == false){

            this -> output_file.open(output_filename, std::fstream::app);

            this -> output_file << binary_immediate;
            this -> output_file << parameter_register1;
            this -> output_file << this -> funct3_XORI;
            this -> output_file << destination_register;
            this -> output_file << this -> opcode_I;
            this -> output_file << std::endl;

            this -> output_file.close();
        }

        if (print_flag == true){

            std::string output;

            output.append(binary_immediate);
            output.append(parameter_register1);
            output.append(this -> funct3_XORI);
            output.append(destination_register);
            output.append(this -> opcode_I);

            std::cout << output << std::endl;
        }
    }
    public: void SLLI(std::string& string, bool print_flag){

        I_instruction instruction = I_type_split(string);

        std::string binary_immediate = immediate_to_binary(instruction.immediate);
        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);

        if (print_flag == false){

            this -> output_file.open(output_filename, std::fstream::app);

            this -> output_file << binary_immediate;
            this -> output_file << parameter_register1;
            this -> output_file << this -> funct3_SLLI;
            this -> output_file << destination_register;
            this -> output_file << this -> opcode_I;
            this -> output_file << std::endl;

            this -> output_file.close();
        }

        if (print_flag == true){

            std::string output;

            output.append(binary_immediate);
            output.append(parameter_register1);
            output.append(this -> funct3_SLLI);
            output.append(destination_register);
            output.append(this -> opcode_I);

            std::cout << output << std::endl;
        }
    }
    public: void SRLI(std::string& string, bool print_flag){

        I_instruction instruction = I_type_split(string);

        std::string binary_immediate = immediate_to_binary(instruction.immediate);
        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);

        if (print_flag == false){

            this -> output_file.open(output_filename, std::fstream::app);

            this -> output_file << binary_immediate;
            this -> output_file << parameter_register1;
            this -> output_file << this -> funct3_SRLI;
            this -> output_file << destination_register;
            this -> output_file << this -> opcode_I;
            this -> output_file << std::endl;

            this -> output_file.close();
        }

        if (print_flag == true){

            std::string output;

            output.append(binary_immediate);
            output.append(parameter_register1);
            output.append(this -> funct3_SRLI);
            output.append(destination_register);
            output.append(this -> opcode_I);

            std::cout << output << std::endl;
        }
    }
};