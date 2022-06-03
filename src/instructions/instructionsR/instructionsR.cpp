#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <boost/convert.hpp>
#include <bitset>
#include "../convert_methods/convert_methods.hpp"

class R_assembler: public Convert_methods {

    private: std::fstream output_file;
    private: std::string opcode_R;
    private: std::string output_filename;

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

    public: R_assembler(std::string& output_filename){

        this -> output_filename = output_filename;
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

    public: void ADD(std::string& string, bool print_flag){

        R_instruction instruction = R_type_split(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        if (print_flag == false){

            this -> output_file.open(output_filename, std::fstream::app);

            this -> output_file << this -> funct7_ADD;
            this -> output_file << parameter_register2;
            this -> output_file << parameter_register1;
            this -> output_file << this -> funct3_ADD;
            this -> output_file << destination_register;
            this -> output_file << this -> opcode_R;
            this -> output_file << std::endl;

            this -> output_file.close();
        }

        if (print_flag == true){

            std::string output;

            output.append(this -> funct7_ADD);
            output.append(parameter_register2);
            output.append(parameter_register1);
            output.append(this -> funct3_ADD);
            output.append(destination_register);
            output.append(this -> opcode_R);

            std::cout << output << std::endl;
        }
    }
    public: void SUB(std::string& string, bool print_flag){

        R_instruction instruction = R_type_split(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        if (print_flag == false){

            this -> output_file.open(output_filename, std::fstream::app);

            this -> output_file << this -> funct7_SUB;
            this -> output_file << parameter_register2;
            this -> output_file << parameter_register1;
            this -> output_file << this -> funct3_SUB;
            this -> output_file << destination_register;
            this -> output_file << this -> opcode_R;
            this -> output_file << std::endl;

            this -> output_file.close();
        }

        if (print_flag == true){

            std::string output;

            output.append(this -> funct7_SUB);
            output.append(parameter_register2);
            output.append(parameter_register1);
            output.append(this -> funct3_SUB);
            output.append(destination_register);
            output.append(this -> opcode_R);

            std::cout << output << std::endl;
        }
    }
    public: void AND(std::string& string, bool print_flag){

        R_instruction instruction = R_type_split(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        if (print_flag == false){

            this -> output_file.open(output_filename, std::fstream::app);

            this -> output_file << this -> funct7_AND;
            this -> output_file << parameter_register2;
            this -> output_file << parameter_register1;
            this -> output_file << this -> funct3_AND;
            this -> output_file << destination_register;
            this -> output_file << this -> opcode_R;
            this -> output_file << std::endl;

            this -> output_file.close();
        }

        if (print_flag == true){

            std::string output;

            output.append(this -> funct7_AND);
            output.append(parameter_register2);
            output.append(parameter_register1);
            output.append(this -> funct3_AND);
            output.append(destination_register);
            output.append(this -> opcode_R);

            std::cout << output << std::endl;
        }
    }
    public: void OR(std::string& string, bool print_flag){

        R_instruction instruction = R_type_split(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        if (print_flag == false){

            this -> output_file.open(output_filename, std::fstream::app);

            this -> output_file << this -> funct7_OR;
            this -> output_file << parameter_register2;
            this -> output_file << parameter_register1;
            this -> output_file << this -> funct3_OR;
            this -> output_file << destination_register;
            this -> output_file << this -> opcode_R;
            this -> output_file << std::endl;

            this -> output_file.close();
        }

        if (print_flag == true){

            std::string output;

            output.append(this -> funct7_OR);
            output.append(parameter_register2);
            output.append(parameter_register1);
            output.append(this -> funct3_OR);
            output.append(destination_register);
            output.append(this -> opcode_R);

            std::cout << output << std::endl;
        }
    }
    public: void XOR(std::string& string, bool print_flag){

        R_instruction instruction = R_type_split(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        if (print_flag == false){

            this -> output_file.open(output_filename, std::fstream::app);

            this -> output_file << this -> funct7_XOR;
            this -> output_file << parameter_register2;
            this -> output_file << parameter_register1;
            this -> output_file << this -> funct3_XOR;
            this -> output_file << destination_register;
            this -> output_file << this -> opcode_R;
            this -> output_file << std::endl;

            this -> output_file.close();
        }

        if (print_flag == true){

            std::string output;

            output.append(this -> funct7_XOR);
            output.append(parameter_register2);
            output.append(parameter_register1);
            output.append(this -> funct3_XOR);
            output.append(destination_register);
            output.append(this -> opcode_R);

            std::cout << output << std::endl;
        }
    }
    public: void SLL(std::string& string, bool print_flag){

        R_instruction instruction = R_type_split(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        if (print_flag == false){

            this -> output_file.open(output_filename, std::fstream::app);

            this -> output_file << this -> funct7_SLL;
            this -> output_file << parameter_register2;
            this -> output_file << parameter_register1;
            this -> output_file << this -> funct3_SLL;
            this -> output_file << destination_register;
            this -> output_file << this -> opcode_R;
            this -> output_file << std::endl;

            this -> output_file.close();
        }

        if (print_flag == true){

            std::string output;

            output.append(this -> funct7_SLL);
            output.append(parameter_register2);
            output.append(parameter_register1);
            output.append(this -> funct3_SLL);
            output.append(destination_register);
            output.append(this -> opcode_R);

            std::cout << output << std::endl;
        }
    }
    public: void SRL(std::string& string, bool print_flag){

        R_instruction instruction = R_type_split(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        if (print_flag == false){

            this -> output_file.open(output_filename, std::fstream::app);

            this -> output_file << this -> funct7_SRL;
            this -> output_file << parameter_register2;
            this -> output_file << parameter_register1;
            this -> output_file << this -> funct3_SRL;
            this -> output_file << destination_register;
            this -> output_file << this -> opcode_R;
            this -> output_file << std::endl;

            this -> output_file.close();
        }

        if (print_flag == true){

            std::string output;

            output.append(this -> funct7_SRL);
            output.append(parameter_register2);
            output.append(parameter_register1);
            output.append(this -> funct3_SRL);
            output.append(destination_register);
            output.append(this -> opcode_R);

            std::cout << output << std::endl;
        }
    }
};