#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <boost/convert.hpp>
#include <bitset>

typedef struct R_instruction R_instruction;

struct R_instruction {

    std::string operation;
    std::string destination_register;
    std::string parameter_register1;
    std::string parameter_register2;

};

class R_assembler {

    private: std::fstream output_file;
    private: std::string opcode_R;

    private:
        std::string funct7_ADD;
        std::string funct7_SUB;
        std::string funct7_XOR;
        std::string funct7_OR;
        std::string funct7_AND;
        std::string funct7_SLL;
        std::string funct7_SLR;

        std::string funct3_ADD;
        std::string funct3_SUB;
        std::string funct3_XOR;
        std::string funct3_OR;
        std::string funct3_AND;
        std::string funct3_SLL;
        std::string funct3_SLR;

    public: R_assembler(){
        this -> opcode_R.assign("0110011");
        
        this -> funct7_ADD.assign("0000000");
        this -> funct7_SUB.assign("0100000");
        this -> funct7_XOR.assign("0000000");
        this -> funct7_OR.assign ("0000000");
        this -> funct7_AND.assign("0000000");
        this -> funct7_SLL.assign("0000000");
        this -> funct7_SLR.assign("0000000");

        this -> funct3_ADD.assign("000");
        this -> funct3_SUB.assign("000");
        this -> funct3_XOR.assign("100");
        this -> funct3_OR.assign ("110");
        this -> funct3_AND.assign("111");
        this -> funct3_SLL.assign("001");
        this -> funct3_SLR.assign("101");
    }

    public: void ADD(std::string& string){

        this -> output_file.open("output.txt", std::fstream::app);

        R_instruction instruction = R_type_split(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        this -> output_file << funct7_ADD;
        this -> output_file << parameter_register2;
        this -> output_file << parameter_register1;
        this -> output_file << funct3_ADD;
        this -> output_file << destination_register;
        this -> output_file << opcode_R;
        this -> output_file << std::endl;
        
        this -> output_file.close();
    }
    public: void SUB(std::string& string){

        this -> output_file.open("output.txt", std::fstream::app);

        R_instruction instruction = R_type_split(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        this -> output_file << funct7_ADD;
        this -> output_file << parameter_register2;
        this -> output_file << parameter_register1;
        this -> output_file << funct3_ADD;
        this -> output_file << destination_register;
        this -> output_file << opcode_R;
        this -> output_file << std::endl;
        
        this -> output_file.close();
    }
    public: void AND(std::string& string){

        this -> output_file.open("output.txt", std::fstream::app);

        R_instruction instruction = R_type_split(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        this -> output_file << funct7_ADD;
        this -> output_file << parameter_register2;
        this -> output_file << parameter_register1;
        this -> output_file << funct3_ADD;
        this -> output_file << destination_register;
        this -> output_file << opcode_R;
        this -> output_file << std::endl;
        
        this -> output_file.close();
    }
    public: void OR(std::string& string){

        this -> output_file.open("output.txt", std::fstream::app);

        R_instruction instruction = R_type_split(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        this -> output_file << funct7_ADD;
        this -> output_file << parameter_register2;
        this -> output_file << parameter_register1;
        this -> output_file << funct3_ADD;
        this -> output_file << destination_register;
        this -> output_file << opcode_R;
        this -> output_file << std::endl;
        
        this -> output_file.close();
    }
    public: void XOR(std::string& string){

        this -> output_file.open("output.txt", std::fstream::app);

        R_instruction instruction = R_type_split(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        this -> output_file << funct7_ADD;
        this -> output_file << parameter_register2;
        this -> output_file << parameter_register1;
        this -> output_file << funct3_ADD;
        this -> output_file << destination_register;
        this -> output_file << opcode_R;
        this -> output_file << std::endl;
        
        this -> output_file.close();
    }
    public: void SLL(std::string& string){

        this -> output_file.open("output.txt", std::fstream::app);

        R_instruction instruction = R_type_split(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        this -> output_file << funct7_ADD;
        this -> output_file << parameter_register2;
        this -> output_file << parameter_register1;
        this -> output_file << funct3_ADD;
        this -> output_file << destination_register;
        this -> output_file << opcode_R;
        this -> output_file << std::endl;
        
        this -> output_file.close();
    }
    public: void SRL(std::string& string){

        this -> output_file.open("output.txt", std::fstream::app);

        R_instruction instruction = R_type_split(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        this -> output_file << funct7_ADD;
        this -> output_file << parameter_register2;
        this -> output_file << parameter_register1;
        this -> output_file << funct3_ADD;
        this -> output_file << destination_register;
        this -> output_file << opcode_R;
        this -> output_file << std::endl;
        
        this -> output_file.close();
    }
    
    private: R_instruction R_type_split (std::string& string1){

        std::size_t found1 = string1.find_first_of(" ");
        std::string operation = string1.substr(0,found1);
        std::string string2 = string1.substr(found1 + 1);
        
        std::size_t found2 = string2.find_first_of(" ");
        std::string destination = string2.substr(0,found2);
        std::string string3 = string2.substr(found2 + 1);

        std::size_t found3 = string3.find_first_of(" ");
        std::string parameter1 = string3.substr(0,found3);
        std::string string4 = string3.substr(found3 + 1);

        std::size_t found4 = string4.find_first_of(" ");
        std::string parameter2 =string4.substr(0,found4);

        destination.erase (destination.begin() + 2);
        parameter1.erase (parameter1.begin() + 2);
        
        R_instruction new_instruction;
        new_instruction.operation = operation;
        new_instruction.destination_register = destination;
        new_instruction.parameter_register1 = parameter1;
        new_instruction.parameter_register2 = parameter2;

        return new_instruction;
    }

    private: std::string register_to_binary(std::string& reg){

        try {

            /* caso o registrador tenha mais de 3 digitos, diferente de xAA */
            if (reg.length() > 3){
                throw("assembler error: invalid register name");
            }

            /* caso o registrador não comece com x */
            if (reg.substr(0, 1) != "x"){
                throw("assembler error: invalid register name");
            }

            /* caso o numero do registrador for maior que 31 */
            if (stoi(reg.substr(1, reg.length())) > 31 ){
                throw ("assembler error: invalid register name");
            }

            std::string aux = reg.substr(1, reg.size());
            std::string binary_string = std::bitset<5>(std::stoi(aux)).to_string();

            return binary_string;

        }
        catch(...){
            throw;
            return "";
        }
        
        
    }
};