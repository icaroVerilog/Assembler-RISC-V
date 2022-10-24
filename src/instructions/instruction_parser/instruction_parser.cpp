#include "instruction_parser.hpp"

I_instruction Instruction_parser::I_type_parse (std::string& instruction){

    std::size_t found1 = instruction.find_first_of(" ");
    std::string operation = instruction.substr(0,found1);
    std::string string2 = instruction.substr(found1 + 1);
    
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

L_instruction Instruction_parser::L_type_parse (std::string& instruction){

    std::regex L_format_regex("([x][0-9]{1,2})[,]([0-9]{1,3})[(]([x][0-9]{1,2})[)]");

    try {

        std::size_t found1 = instruction.find_first_of(" ");
        std::string operation = instruction.substr(0,found1);
        std::string string2 = instruction.substr(found1 + 1);

        string2.erase(remove_if(string2.begin(), string2.end(), isspace), string2.end());

        std::smatch regex_result;

        /* verifica por meio da RegEx se a instrução está no formato certo */
        if (std::regex_match(string2, regex_result, L_format_regex) == false){
            throw std::runtime_error("assembler error: invalid load struction format");
        }    

        L_instruction new_instruction;

        new_instruction.operation = operation;
        new_instruction.destination_register = regex_result[1];
        new_instruction.jump_immediate = regex_result[2];
        new_instruction.pointer_register = regex_result[3];

        return new_instruction;

    }

    catch (const std::invalid_argument& error){
        std::cerr << error.what() << std::endl;
        std::exit(0);
    }
}

R_instruction Instruction_parser::R_type_parse (std::string& instruction){

    std::regex R_format_regex("(([a-z][0-9]{1,2})+([,][a-z][0-9]{1,2})+([,][a-z][0-9]{1,2}))");

    try {

        std::size_t found1 = instruction.find_first_of(" ");
        std::string operation = instruction.substr(0,found1);
        std::string string2 = instruction.substr(found1 + 1);

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

P_instruction Instruction_parser::P_type_parse (std::string& instruction){

    try {
    
        std::size_t found1 = instruction.find_first_of(" ");
        std::string operation = instruction.substr(0,found1);
        std::string string2 = instruction.substr(found1 + 1);

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

S_instruction Instruction_parser::S_type_parse (std::string& instruction){

    std::regex S_format_regex("([x][0-9]{1,2})[,]([0-9]{1,3})[(]([x][0-9]{1,2})[)]");

    try {
    
        std::size_t found1 = instruction.find_first_of(" ");
        std::string operation = instruction.substr(0,found1);
        std::string string2 = instruction.substr(found1 + 1);

        string2.erase(remove_if(string2.begin(), string2.end(), isspace), string2.end());

        std::smatch regex_result;

        /* verifica por meio da RegEx se a instrução está no formato certo */
        if (std::regex_match(string2, regex_result, S_format_regex) == false){
            throw std::runtime_error("assembler error: invalid load struction format");
        }    

        S_instruction new_instruction;

        new_instruction.data_register = regex_result[1];
        new_instruction.immediate = regex_result[2];
        new_instruction.base_memory_address_register = regex_result[3];

        return new_instruction;
    }
    catch (const std::invalid_argument& error){
        std::cerr << error.what() << std::endl;
        std::exit(0);
    }
}

B_instruction Instruction_parser::B_type_parse(std::string& instruction){
    
    B_instruction new_instruction;


    return new_instruction;
}
