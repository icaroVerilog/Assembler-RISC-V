#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <boost/convert.hpp>
#include <bitset>
#include "../convert_methods/convert_methods.hpp"
#include "../instruction_parser/instruction_parser.hpp"

class L_assembler: public Convert_methods, Instruction_parser {

    private: std::string opcode_I_load;
    private: std::string output_filename;
    private: std::fstream output_file;

    private:
        std::string funct3_LB;
        std::string funct3_LH;
        std::string funct3_LW;
        std::string funct3_LD;

    public: L_assembler(std::string& output_filename){

        this -> output_filename = output_filename;
        this -> opcode_I_load.assign("0000011");

        this -> funct3_LB.assign("000");
        this -> funct3_LH.assign("001");
        this -> funct3_LW.assign("010");
        this -> funct3_LD.assign("011");
    }

    public: void LB(std::string& string, bool print_flag){
        
        L_instruction instruction = L_type_split(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.pointer_register);
        std::string binary_immediate = immediate_to_binary(instruction.jump_immediate);

        if (print_flag == false){

            this -> output_file.open(output_filename, std::fstream::app);

            this -> output_file << binary_immediate;
            this -> output_file << parameter_register1;
            this -> output_file << this -> funct3_LB;
            this -> output_file << destination_register;
            this -> output_file << this -> opcode_I_load;
            this -> output_file << std::endl;

            this -> output_file.close();
        }

        if (print_flag == true){

            std::string output;

            output.append(binary_immediate);
            output.append(parameter_register1);
            output.append(this -> funct3_LB);
            output.append(destination_register);
            output.append(this -> opcode_I_load);

            std::cout << output << std::endl;
        }
    }

    public: void LH(std::string& string, bool print_flag){
        
        L_instruction instruction = L_type_split(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.pointer_register);
        std::string binary_immediate = immediate_to_binary(instruction.jump_immediate);

        if (print_flag == false){

            this -> output_file.open(output_filename, std::fstream::app);

            this -> output_file << binary_immediate;
            this -> output_file << parameter_register1;
            this -> output_file << this -> funct3_LH;
            this -> output_file << destination_register;
            this -> output_file << this -> opcode_I_load;
            this -> output_file << std::endl;

            this -> output_file.close();
        }

        if (print_flag == true){

            std::string output;

            output.append(binary_immediate);
            output.append(parameter_register1);
            output.append(this -> funct3_LH);
            output.append(destination_register);
            output.append(this -> opcode_I_load);

            std::cout << output << std::endl;
        }
    }
    
    public: void LW(std::string& string, bool print_flag){
        
        L_instruction instruction = L_type_split(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.pointer_register);
        std::string binary_immediate = immediate_to_binary(instruction.jump_immediate);

        if (print_flag == false){

            this -> output_file.open(output_filename, std::fstream::app);

            this -> output_file << binary_immediate;
            this -> output_file << parameter_register1;
            this -> output_file << this -> funct3_LW;
            this -> output_file << destination_register;
            this -> output_file << this -> opcode_I_load;
            this -> output_file << std::endl;

            this -> output_file.close();
        }

        if (print_flag == true){

            std::string output;

            output.append(binary_immediate);
            output.append(parameter_register1);
            output.append(this -> funct3_LW);
            output.append(destination_register);
            output.append(this -> opcode_I_load);

            std::cout << output << std::endl;
        }
    }

    public: void LD(std::string& string, bool print_flag){
        
        L_instruction instruction = L_type_split(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.pointer_register);
        std::string binary_immediate = immediate_to_binary(instruction.jump_immediate);

        if (print_flag == false){

            this -> output_file.open(output_filename, std::fstream::app);

            this -> output_file << binary_immediate;
            this -> output_file << parameter_register1;
            this -> output_file << this -> funct3_LD;
            this -> output_file << destination_register;
            this -> output_file << this -> opcode_I_load;
            this -> output_file << std::endl;

            this -> output_file.close();
        }

        if (print_flag == true){

            std::string output;

            output.append(binary_immediate);
            output.append(parameter_register1);
            output.append(this -> funct3_LD);
            output.append(destination_register);
            output.append(this -> opcode_I_load);

            std::cout << output << std::endl;
        }
    }
};