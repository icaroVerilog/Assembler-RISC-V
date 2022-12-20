#include "convert_methods.hpp"

std::string Convert_methods::register_to_binary(std::string& reg){

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

std::string Convert_methods::immediate_to_binary(std::string& immediate){

    /* Caso se trate de um valor haxadecimal */
    if (immediate.substr(0, 2) == "0x"){
    
        try {

            std::string hex = immediate.substr(2, immediate.length());
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

    else if (immediate.substr(0, 2) == "0b"){

        std::string binary = immediate.substr(2, immediate.length());

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
            std::string binary_string = std::bitset<12>(stoi(immediate)).to_string();

            return binary_string;
        }
        catch (const std::invalid_argument& error){
            std::cerr << "assembler error: invalid decimal on immediate field" << std::endl;
            std::exit(0);
        }
    }
}

std::string Convert_methods::label_address_to_binary(int address){

    std::string binary_string = std::bitset<13>(address).to_string();

    return binary_string;
}

std::string Convert_methods::r_binary_to_string(std::string funct7, std::string reg1, std::string reg2, std::string funct3, std::string dest_reg, std::string opcode){
    
    std::string assembled_binary;

    assembled_binary.append(funct7);
    assembled_binary.append(reg2);
    assembled_binary.append(reg1);
    assembled_binary.append(funct3);
    assembled_binary.append(dest_reg);
    assembled_binary.append(opcode);

    return assembled_binary;
}

std::string Convert_methods::i_binary_to_string(std::string immediate, std::string reg1, std::string funct3, std::string dest_reg, std::string opcode){
    
    std::string assembled_binary;

    assembled_binary.append(immediate);
    assembled_binary.append(reg1);
    assembled_binary.append(funct3);
    assembled_binary.append(dest_reg);
    assembled_binary.append(opcode);

    return assembled_binary;
}

std::string Convert_methods::l_binary_to_string(std::string immediate, std::string reg1, std::string funct3, std::string dest_reg, std::string opcode){
    
    std::string assembled_binary;

    assembled_binary.append(immediate);
    assembled_binary.append(reg1);
    assembled_binary.append(funct3);
    assembled_binary.append(dest_reg);
    assembled_binary.append(opcode);

    return assembled_binary;
}

std::string Convert_methods::s_binary_to_string(std::string immediate, std::string source_reg2, std::string funct3, std::string source_reg1, std::string opcode){

    std::string assembled_binary;

    assembled_binary.append(immediate.substr(0, 7));
    assembled_binary.append(source_reg2);
    assembled_binary.append(source_reg1);
    assembled_binary.append(funct3);
    assembled_binary.append(immediate.substr(7, 5));
    assembled_binary.append(opcode);

    return assembled_binary;
}

std::string Convert_methods::b_binary_to_string(std::string label_address, std::string source_reg2, std::string source_reg1, std::string funct3, std::string opcode){

    std::string assembled_binary;

    assembled_binary.append(label_address.substr(0, 1));
    assembled_binary.append(label_address.substr(2, 6));
    assembled_binary.append(source_reg2);
    assembled_binary.append(source_reg1);
    assembled_binary.append(funct3);
    assembled_binary.append(label_address.substr(8, 4));
    assembled_binary.append(label_address.substr(1, 1));
    assembled_binary.append(opcode);

    return assembled_binary;    
}