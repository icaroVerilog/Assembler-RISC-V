#include "instruction_parser.hpp"

I_instruction Instruction_parser::I_type_parse (std::string& instruction){

    std::regex I_format_regex("[a-z]{4}([x][0-9]{1,2})[,]([x][0-9]{1,2})[,]([0-9]{1,10})");
    std::smatch regex_result;

    try {

        /* verifica por meio da RegEx se a instrução está no formato certo */
        if (std::regex_match(instruction, regex_result, I_format_regex) == false){
            throw std::runtime_error("assembler error: invalid type R struction format");
        } 

        I_instruction new_instruction;

        new_instruction.destination_register = regex_result[1];
        new_instruction.parameter_register1 = regex_result[2];
        new_instruction.immediate = regex_result[3];        

        return new_instruction;
    }
    catch (const std::invalid_argument& error){
        std::cerr << error.what() << std::endl;
        std::exit(0);
    }
}

R_instruction Instruction_parser::R_type_parse (std::string& instruction){

    std::regex R_format_regex("[a-z]{2,3}([x][0-9]{1,2})[,]([x][0-9]{1,2})[,]([x][0-9]{1,2})");
    std::smatch regex_result;

    try {

        /* verifica por meio da RegEx se a instrução está no formato certo */
        if (std::regex_match(instruction, regex_result, R_format_regex) == false){
            throw std::runtime_error("assembler error: invalid type R struction format");
        } 

        R_instruction new_instruction;

        new_instruction.destination_register = regex_result[1];
        new_instruction.parameter_register1 = regex_result[2];
        new_instruction.parameter_register2 = regex_result[3];        

        return new_instruction;
    }
    catch (const std::invalid_argument& error){
        std::cerr << error.what() << std::endl;
        std::exit(0);
    }
}

L_instruction Instruction_parser::L_type_parse (std::string& instruction){

    std::regex L_format_regex("[a-z]{2}([x][0-9]{1,2})[,]([0-9]{1,10})[(]([x][0-9]{1,2})[)]");
    std::smatch regex_result;

    try {

        /* verifica por meio da RegEx se a instrução está no formato certo */
        if (std::regex_match(instruction, regex_result, L_format_regex) == false){
            throw std::runtime_error("assembler error: invalid type L struction format");
        } 

        L_instruction new_instruction;

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

    std::regex S_format_regex("[a-z]{2}([x][0-9]{1,2})[,]([0-9]{1,10})[(]([x][0-9]{1,2})[)]");
    std::smatch regex_result;

    try {

        /* verifica por meio da RegEx se a instrução está no formato certo */
        if (std::regex_match(instruction, regex_result, S_format_regex) == false){
            throw std::runtime_error("assembler error: invalid type S struction format");
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
    
    std::regex B_format_regex("[a-z]{3,4}([x][0-9]{1,2})[,]([x][0-9]{1,2})[,]([a-z]{1,20})");
    std::smatch regex_result;

    try {
        /* verifica por meio da RegEx se a instrução está no formato certo */
        if (std::regex_match(instruction, regex_result, B_format_regex) == false){
            throw std::runtime_error("assembler error: invalid type S struction format");
        } 

        B_instruction new_instruction;

        new_instruction.source_register1 = regex_result[1];
        new_instruction.source_register2 = regex_result[2];
        new_instruction.label_name = regex_result[3];

        return new_instruction;

    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    

    B_instruction new_instruction;


    return new_instruction;
}
