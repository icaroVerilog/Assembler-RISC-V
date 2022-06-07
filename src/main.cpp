#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>

#include "instructions/instructions_assembler/instructionsI/instructionsI.cpp"
#include "instructions/instructions_assembler/instructionsR/instructionsR.cpp"
// #include "instructions/instructions_assembler/instructionsP/instructionsP.cpp"
// #include "instructions/instructions_assembler/instructionsI/instructionsI_load.cpp"
#include "accumulator/instruction_ACML.cpp"
#include "auxiliar_methods/auxiliar_methods.hpp"
#include "auxiliar_methods/input_methods/input_methods.hpp"

// RVI 64bits

int error_message(){

    std::cout << std::endl;
    std::cout << "Parameters must be follow this format:" << std::endl;
    std::cout << "filename.asm output_param filename or filename.asm output_param filename" << std::endl;
    std::cout << std::endl;
    std::cout << "suported params:" << std::endl;
    std::cout << "output: --output, -o" << std::endl;
    std::cout << std::endl;

    return 0;
}

int main(int argc, char *argv[]){

    bool print_flag;

    std::string input_filename;
    std::string open_parameter;
    std::string output_filename;

    std::string file_line;
    std::string filepath;

    std::fstream file;

    try {

        if (argc == 4){

            input_filename = argv[1];
            open_parameter = argv[2];
            output_filename = argv[3];

            if (input_filename.find(".asm", input_filename.size() - 4) == -1){
                throw std::runtime_error("assembler error: invalid input file");
            }

            if (open_parameter != "-o" && open_parameter != "--output"){
                throw std::runtime_error("assembler error: invalid parameters");
            }

            filepath = "../" + output_filename;
            print_flag = false;
        }

        else if (argc == 2){

            input_filename = argv[1];

            if (input_filename.find(".asm", input_filename.size() - 4) == -1){
                throw std::runtime_error("assembler error: invalid input file");
            }

            print_flag = true;
        }
        else {
            error_message();
            throw std::runtime_error("assembler error: invalid parameters");
        }
    }
    catch(const std::runtime_error &error){
        error_message();
        std::cerr << error.what() << std::endl;

        return 0;
    }

    /* code block responsible for opening the input file  */
    // try {
    //     file.open("../" + input_filename, std::fstream::in);

    //     if (file.is_open() == 0){
    //         throw std::runtime_error("assembler error: cannot open the file");
    //     }
    // }
    // catch(const std::runtime_error &error){
    //     std::cerr << error.what() << std::endl;

    //     return 0;
    // }

    Auxiliar_methods *auxiliar_methods = new Auxiliar_methods();

    R_assembler *assembler_R = new R_assembler(filepath);
    I_assembler *assembler_I = new I_assembler(filepath);
    // L_assembler *assembler_L = new L_assembler(filepath);
    // P_assembler *assembler_P = new P_assembler(filepath);

    Instruction_accumulator *accumulator = new Instruction_accumulator();


    Input_methods *input_methods = new Input_methods();

    file = input_methods -> open_input_file(input_filename);







    while (getline(file, file_line)){

        /* caso a string for vazia */
        if (auxiliar_methods -> is_empty(file_line)){
            continue;
        }

        accumulator -> set_instruction(file_line);
    }

    std::string instruction;

    while (accumulator -> get_instruction(&instruction)){

        /* ::::::::::::::::::::: I FORMAT INSTRUCTIONS ::::::::::::::::::::: */

        if (instruction.substr(0, 4).compare("addi") == 0){
            assembler_I -> ADDI(instruction, print_flag);
        }
        else if (instruction.substr(0, 4).compare("ori") == 0){
            assembler_I -> ORI(instruction, print_flag);
        }
        else if (instruction.substr(0, 4).compare("andi") == 0){
            assembler_I -> ANDI(instruction, print_flag);
        }
        else if (instruction.substr(0, 4).compare("xori") == 0){
            assembler_I -> XORI(instruction, print_flag);
        }
        else if (instruction.substr(0, 4).compare("alli") == 0){
            assembler_I -> SLLI(instruction, print_flag);
        }
        else if (instruction.substr(0, 4).compare("srli") == 0){
            assembler_I -> SRLI(instruction, print_flag);
        }

        /* ::::::::::::::::::::: R FORMAT INSTRUCTIONS ::::::::::::::::::::: */

        else if (instruction.substr(0, 3).compare("add") == 0){
            assembler_R -> ADD(instruction, print_flag);
        }
        else if (instruction.substr(0, 3).compare("sub") == 0){
            assembler_R -> SUB(instruction, print_flag);
        }
        else if (instruction.substr(0, 3).compare("and") == 0){
            assembler_R -> AND(instruction, print_flag);
        }
        else if (instruction.substr(0, 3).compare("or") == 0){
            assembler_R -> OR(instruction, print_flag);
        }
        else if (instruction.substr(0, 3).compare("xor") == 0){
            assembler_R -> XOR(instruction, print_flag);
        }
        else if (instruction.substr(0, 3).compare("sll") == 0){
            assembler_R -> SLL(instruction, print_flag);
        }
        else if (instruction.substr(0, 3).compare("srl") == 0){
            assembler_R -> SRL(instruction, print_flag);
        }
        /* ::::::::::::::::::::: L FORMAT INSTRUCTIONS ::::::::::::::::::::: */

        // else if (instruction.substr(0, 2).compare("lb") == 0){
        //     assembler_L -> LB(instruction, print_flag);
        // }

        // else if (instruction.substr(0, 2).compare("lh") == 0){
        //     assembler_L -> LH(instruction, print_flag);
        // }

        // else if (instruction.substr(0, 2).compare("lw") == 0){
        //     assembler_L -> LW(instruction, print_flag);
        // }

        // else if (instruction.substr(0, 2).compare("ld") == 0){
        //     assembler_L -> LD(instruction, print_flag);
        // }

        // /* ::::::::::::::::::::: P FORMAT INSTRUCTIONS ::::::::::::::::::::: */

        // else if (instruction.find("mv") == 0){
        //     assembler_P -> MV(instruction, print_flag);
        // }

        // else if (instruction.find("li") == 0){
        //     assembler_P -> LI(instruction, print_flag);
        // }

    }
    return 0;
}