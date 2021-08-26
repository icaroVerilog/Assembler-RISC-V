#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <boost/convert.hpp>
#include <bitset>
#include <array>

typedef struct I_instruction I_instruction;

struct I_instruction {

    std::string operation;
    std::string destination_register;
    std::string parameter_register1;
    std::string immediate;

};

class I_assembler {

    private: std::string opcode_I;
    private: std::fstream output_file;
    private: std::string output_filename;

    private:
        std::string funct3_ADDI;
        std::string funct3_ANDI;
        std::string funct3_ORI;

    public: I_assembler(std::string& output_filename){

        this -> output_filename = output_filename;

        this -> opcode_I.assign("0010011");

        this -> funct3_ADDI.assign("000");
        this -> funct3_ANDI.assign("111");
        this -> funct3_ORI.assign("110");
    }

    public: void ADDI(std::string& string, bool print_flag){

        I_instruction instruction = I_type_split(string);

        std::string binary_immediate = immediate_to_binary(instruction.immediate);
        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::cout << "aaaa" << std::endl;
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

    private: std::string register_to_binary(std::string& reg){

        try {

            /* caso o registrador tenha mais de 3 digitos, diferente de xAA */
            if (reg.length() > 3){
                throw std::invalid_argument("assembler error: invalid register");
            }

            /* caso o registrador não comece com x */
            if (reg.substr(0, 1) != "x"){
                throw std::invalid_argument("assembler error: invalid register");
            }

            /* caso o numero do registrador for maior que 31 */
            if (stoi(reg.substr(1, reg.length())) > 31 ){
                throw std::invalid_argument("assembler error: invalid register");
            }

            std::string aux = reg.substr(1, reg.size());
            std::string binary_string = std::bitset<5>(std::stoi(aux)).to_string();

            return binary_string;
        }
        catch (const std::invalid_argument& error){
            std::cerr << error.what() << std::endl;
            std::exit(0);
        }   
    }

    private: std::string immediate_to_binary(std::string& number){

        /* Caso se trate de um valor haxadecimal */
        if (number.substr(0, 2) == "0x"){

            try {

                std::string hex = number.substr(2, number.length());
                unsigned int hex_value;

                std::stringstream aux;
                aux << std::hex << hex;
                aux >> hex_value;

                int integer_value = static_cast<int>(hex_value);
                
                /*
                    TRATA CASO O VALOR PASSADO COMO PARÂMETRO PARA A FUNÇÃO NÃO SEJA UM HEXADECIMAL DE VERDADE

                    POIS SE N FOR UM HEXADECIMAL integer_value IRÁ TER O VALOR 0
                    SE FOR REALMENTE UM HEXADECIMAL COM O VALOR 0, EM TODA A STRING TERÁ 0, ENTÃO A CONDIÇÃO DO IF SERA FALSA
                
                */
                if (integer_value == 0){

                    for (int index = 0; index < hex.length(); index++){
                        if (hex.at(index) != '0'){
                            throw std::invalid_argument("assembler error: invalid hexadecimal value in immediate field");
                        }
                    }
                }
                
                std::string binary_string = std::bitset<12>(integer_value).to_string();
                return binary_string;
                
            }
            catch (const std::invalid_argument& error){
                std::cerr << error.what() << std::endl;
                std::exit(0);
            }
        }

        else if (number.substr(0, 2) == "0b"){

            std::string binary = number.substr(2, number.length());

            try {

                if (binary.length() > 12){
                    throw std::invalid_argument("assembler error: binary overflow");
                }

                else {

                    if (binary.length() < 12){

                        int missing_values = 12 - binary.length();

                        std::string binary_treated;
                        binary_treated.resize(12);
                        

                        for (int index = 0; index < missing_values; index++){
                            binary_treated.at(index) = '0';
                        }

                        for (int index = missing_values; index < 12; index++){
                            binary_treated.at(index) = binary.at(index - missing_values);
                        }

                        binary.erase();
                        binary.resize(12);
                        binary = binary_treated;
                    }

                    for (int index = 0; index < binary.length(); index++){

                        char current_char = binary.at(index);

                        if (current_char != '1' && current_char != '0'){
                            throw std::invalid_argument("assembler error: invalid binary value on immediate field");
                        }
                    }

                    return binary;
                }
            }
            catch (const std::invalid_argument& error){
                std::cerr << error.what() << std::endl;
                std::exit(0);
            }
        }

        /*  caso se trate de um valor decimal  */
        else {

            /*  bloco try trata caso for passado um valor diferente de um decimal para algum campo immediate  */
            try {
                std::string binary_string = std::bitset<12>(stoi(number)).to_string();

                return binary_string;
            }
            catch (const std::invalid_argument& error){
                std::cerr << "assembler error: invalid decimal on immediate field" << std::endl;
                std::exit(0);
            }
        }
    }

    private: I_instruction I_type_split (std::string& string1){

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
        std::string immediate = string4.substr(0,found4);

        destination.erase (destination.begin() + 2);
        parameter1.erase (parameter1.begin() + 2);

        I_instruction new_instruction;
        new_instruction.operation = operation;
        new_instruction.destination_register = destination;
        new_instruction.parameter_register1 = parameter1;
        new_instruction.immediate = immediate;

        return new_instruction;
    }
};