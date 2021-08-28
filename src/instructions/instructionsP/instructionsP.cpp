#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <boost/convert.hpp>
#include <bitset>
#include "../convert_operations.hpp"

/* P instruction means Pseudo instruction */

class P_assembler: public Convert_operations {

    private: std::string opcode_I; /* for ADDI */
    private: std::fstream output_file;
    private: std::string output_filename;
    private: std::string zero_register;
    private: std::string zero_immediate;

    private:
        std::string funct3_ADDI;

    public: P_assembler(std::string& output_filename){

        this -> output_filename = output_filename;
        this -> opcode_I.assign("0010011");
        this -> funct3_ADDI.assign("000");
        this -> zero_register = "x1";
        this -> zero_immediate.assign("0");

    }

    public: void LI(std::string& string, bool print_flag){
        
        P_instruction instruction = P_type_split(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register = register_to_binary(this -> zero_register);
        std::string binary_immediate = immediate_to_binary(instruction.parameter);

        if (print_flag == false){
            
            this -> output_file.open(output_filename, std::fstream::app);

            this -> output_file << binary_immediate;
            this -> output_file << parameter_register;
            this -> output_file << this -> funct3_ADDI;
            this -> output_file << destination_register;
            this -> output_file << this -> opcode_I;
            this -> output_file << std::endl;

            this -> output_file.close();
        }

        if (print_flag == true){

            std::string output;

            output.append(binary_immediate);
            output.append(parameter_register);
            output.append(this -> funct3_ADDI);
            output.append(destination_register);
            output.append(this -> opcode_I);

            std::cout << output << std::endl;
        }
    }
    public: void MV(std::string& string, bool print_flag){

        P_instruction instruction = P_type_split(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register = register_to_binary(instruction.parameter);
        std::string binary_immediate = immediate_to_binary(this -> zero_immediate);

        if (print_flag == false){
            
            this -> output_file.open(output_filename, std::fstream::app);

            this -> output_file << binary_immediate;
            this -> output_file << parameter_register;
            this -> output_file << this -> funct3_ADDI;
            this -> output_file << destination_register;
            this -> output_file << this -> opcode_I;
            this -> output_file << std::endl;

            this -> output_file.close();
        }

        if (print_flag == true){

            std::string output;

            output.append(binary_immediate);
            output.append(parameter_register);
            output.append(this -> funct3_ADDI);
            output.append(destination_register);
            output.append(this -> opcode_I);

            std::cout << output << std::endl;
        }
    }
};