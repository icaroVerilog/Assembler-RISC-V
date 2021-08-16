#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <boost/convert.hpp>
#include <bitset>

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

    public: I_assembler(){
        this -> opcode_I.assign("0010011");
    }

    public: void ADDI(std::string& string){

        this -> output_file.open("output.txt", std::fstream::app);

        I_instruction instruction = I_type_split(string);

        std::cout << instruction.operation << std::endl;
        std::cout << instruction.destination_register << std::endl;
        std::cout << instruction.parameter_register1 << std::endl;
        std::cout << instruction.immediate << std::endl;

        std::string binary_immediate = immediate_to_binary(instruction.immediate);

        this -> output_file << binary_immediate;
        this -> output_file.close();
    }
    public: void ANDI(std::string& string){



    }
    public: void ORI(std::string& string){



    }

    private: std::string immediate_to_binary(std::string& number){

        /* Caso se trate de um valor haxadecimal */
        if (number.substr(0, 2) == "0x"){

            try {

                std::string return_string(" ");
                std::string hex = number.substr(2, number.length());
                unsigned int hex_value;

                std::stringstream aux;
                aux << std::hex << hex;
                aux >> hex_value;

                int integer_value = static_cast<int>(hex_value);
                std::cout << hex_value << std::endl;
                std::cout << integer_value << std::endl;
                /*

                    nao ta funfando segurar o erro

                    TRATA CASO O VALOR PASSADO COMO PARÂMETRO PARA A FUNÇÃO NÃO SEJA UM HEXADECIMAL DE VERDADE

                    POIS SE N FOR UM HEXADECIMAL integer_value IRÁ TER O VALOR 0
                    SE FOR REALMENTE UM HEXADECIMAL COM O VALOR 0, EM TODA A STRING TERÁ 0, ENTÃO A CONDIÇÃO DO IF SERA FALSA
                
                */
                if (integer_value == 0 && (hex.substr(2, hex.length())) != "0"){
                    throw("assembler error: invalid hexadecimal value");
                }
                
                else {

                    std::string binary_string = std::bitset<12>(integer_value).to_string();
                    return binary_string;

                }
                
            }
            catch (...){
                // TODO: lançar a excessão corretamente e encerrar o algoritmo
                throw;
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
                std::cerr << "invalid decimal on immediate field";
                return "";
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