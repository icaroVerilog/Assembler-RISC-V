#include "convert_operations.hpp"

std::string Convert_operations::register_to_binary(std::string& reg){

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

std::string Convert_operations::immediate_to_binary(std::string& number){

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

I_instruction Convert_operations::I_type_split (std::string& string1){

    std::size_t found1 = string1.find_first_of(" ");
    std::string operation = string1.substr(0,found1);
    std::string string2 = string1.substr(found1 + 1);
    
    /* Removendo espaços */
    string2.erase(remove_if(string2.begin(), string2.end(), isspace), string2.end());

    std::size_t found2 = string2.find_first_of(',');
    std::string destination = string2.substr(0,found2);
    std::string string3 = string2.substr(found2 + 1);

    std::size_t found3 = string3.find_first_of(',');
    std::string parameter1 = string3.substr(0,found3);
    std::string string4 = string3.substr(found3 + 1);

    std::size_t found4 = string4.find_first_of(',');
    std::string immediate = string4.substr(0,found4);

    I_instruction new_instruction;

    new_instruction.operation = operation;
    new_instruction.destination_register = destination;
    new_instruction.parameter_register1 = parameter1;
    new_instruction.immediate = immediate;

    return new_instruction;
}

L_instruction Convert_operations::L_type_split (std::string& string1){

    std::regex L_format_regex("([0-9]{1,2})+[(]([a-z][0-9]{1,2})[)]");

    try {

        std::size_t found1 = string1.find_first_of(" ");
        std::string operation = string1.substr(0,found1);
        std::string string2 = string1.substr(found1 + 1);

        string2.erase(remove_if(string2.begin(), string2.end(), isspace), string2.end());

        std::size_t found2 = string2.find_first_of(',');
        std::string destination = string2.substr(0,found2);
        std::string string3 = string2.substr(found2 + 1);

        std::smatch regex_result;

        /* verifica por meio da RegEx se a instrução está no formato certo */
        if (std::regex_match(string3, regex_result, L_format_regex) == false){
            throw std::runtime_error("assembler error: invalid load struction format");
        }    

        L_instruction new_instruction;

        new_instruction.operation = operation;
        new_instruction.destination_register = destination;
        new_instruction.jump_immediate = regex_result[1];
        new_instruction.pointer_register = regex_result[2];

        return new_instruction;

    }

    catch (const std::invalid_argument& error){
        std::cerr << error.what() << std::endl;
        std::exit(0);
    }
}

R_instruction Convert_operations::R_type_split (std::string& string1){

    std::regex R_format_regex("(([a-z][0-9]{1,2})+([,][a-z][0-9]{1,2})+([,][a-z][0-9]{1,2}))");

    try {

        std::size_t found1 = string1.find_first_of(" ");
        std::string operation = string1.substr(0,found1);
        std::string string2 = string1.substr(found1 + 1);

        /*  
            remove_if() can't change the string length(only modify the values) 
            we have called string::erase to actually modify the length of the string
        */

        string2.erase(remove_if(string2.begin(), string2.end(), isspace), string2.end());

        /* verifica por meio da RegEx se a instrução está no formato certo */
        if (std::regex_match(string2, R_format_regex) == false){
            throw std::runtime_error("assembler error: invalid type R struction format");
        } 

        std::size_t found2 = string2.find_first_of(',');
        std::string destination = string2.substr(0,found2);
        std::string string3 = string2.substr(found2 + 1);

        std::size_t found3 = string3.find_first_of(',');
        std::string parameter1 = string3.substr(0,found3);
        std::string string4 = string3.substr(found3 + 1);

        std::size_t found4 = string4.find_first_of(',');
        std::string parameter2 =string4.substr(0,found4);

        R_instruction new_instruction;

        new_instruction.operation = operation;
        new_instruction.destination_register = destination;
        new_instruction.parameter_register1 = parameter1;
        new_instruction.parameter_register2 = parameter2;

        return new_instruction;

    }

    catch (const std::invalid_argument& error){
        std::cerr << error.what() << std::endl;
        std::exit(0);
    }
}

P_instruction Convert_operations::P_type_split (std::string& string1){

    try {
    
        std::size_t found1 = string1.find_first_of(" ");
        std::string operation = string1.substr(0,found1);
        std::string string2 = string1.substr(found1 + 1);

        string2.erase(remove_if(string2.begin(), string2.end(), isspace), string2.end());

        std::size_t found2 = string2.find_first_of(',');
        std::string destination = string2.substr(0,found2);
        std::string string3 = string2.substr(found2 + 1);

        std::size_t found3 = string3.find_first_of(',');
        std::string parameter = string3.substr(0,found3);

        P_instruction new_instruction;
        
        new_instruction.operation = operation;
        new_instruction.destination_register = destination;
        new_instruction.parameter = parameter;
   
        return new_instruction;
    }

    catch (const std::invalid_argument& error){
        std::cerr << error.what() << std::endl;
        std::exit(0);
    }
}
