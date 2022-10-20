#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>

#include "instructions/instructions_assembler/instructionsI/instructionsI.cpp"
#include "instructions/instructions_assembler/instructionsR/instructionsR.cpp"
#include "instructions/instructions_assembler/instructionsP/instructionsP.cpp"
#include "instructions/instructions_assembler/instructionsS/instructionsS.cpp"
#include "instructions/instructions_assembler/instructionsI/instructionsI_load.cpp"
#include "accumulator/instruction_ACML.cpp"
#include "misc/auxiliar_methods/auxiliar_methods.hpp"

#include "input_output/file_controller/file_controller.hpp"

// #include "misc/input_methods/input_methods.hpp"
// #include "file/file_controller.hpp"

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

    std::fstream input_file;

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

    R_assembler *assembler_R = new R_assembler();
    I_assembler *assembler_I = new I_assembler();
    S_assembler *assembler_S = new S_assembler();
    L_assembler *assembler_L = new L_assembler(filepath);
    P_assembler *assembler_P = new P_assembler(filepath);

    Instruction_accumulator  *input_accumulator  = new Instruction_accumulator();
    Instruction_accumulator  *output_accumulator = new Instruction_accumulator();
    Auxiliar_methods         *auxiliar_methods   = new Auxiliar_methods();
    File_controller          *file_controller    = new File_controller();

    int read_file_result = file_controller -> read(&input_file, input_filename);


    while (getline(input_file, file_line)){

        /* caso a string for vazia */
        if (auxiliar_methods -> is_empty(file_line)){
            continue;
        }
        input_accumulator -> set_instruction(file_line);
    }

    std::string instruction;

    while (input_accumulator -> get_instruction(&instruction)){
        
        /* ::::::::::::::::::::: I FORMAT INSTRUCTIONS ::::::::::::::::::::: */

        if (instruction.substr(0, 4).compare("addi") == 0){
            assembler_I -> ADDI(instruction, output_accumulator);
        }
        else if (instruction.substr(0, 4).compare("ori") == 0){
            assembler_I -> ORI(instruction, output_accumulator);
        }
        else if (instruction.substr(0, 4).compare("andi") == 0){
            assembler_I -> ANDI(instruction, output_accumulator);
        }
        else if (instruction.substr(0, 4).compare("xori") == 0){
            assembler_I -> XORI(instruction, output_accumulator);
        }
        else if (instruction.substr(0, 4).compare("slli") == 0){
            assembler_I -> SLLI(instruction, output_accumulator);
        }
        else if (instruction.substr(0, 4).compare("srli") == 0){
            assembler_I -> SRLI(instruction, output_accumulator);
        }

        /* ::::::::::::::::::::: R FORMAT INSTRUCTIONS ::::::::::::::::::::: */

        else if (instruction.substr(0, 3).compare("add") == 0){
            assembler_R -> ADD(instruction, output_accumulator);
        }
        else if (instruction.substr(0, 3).compare("sub") == 0){
            assembler_R -> SUB(instruction, output_accumulator);
        }
        else if (instruction.substr(0, 3).compare("and") == 0){
            assembler_R -> AND(instruction, output_accumulator);
        }
        else if (instruction.substr(0, 3).compare("or") == 0){
            assembler_R -> OR(instruction, output_accumulator);
        }
        else if (instruction.substr(0, 3).compare("xor") == 0){
            assembler_R -> XOR(instruction, output_accumulator);
        }
        else if (instruction.substr(0, 3).compare("sll") == 0){
            assembler_R -> SLL(instruction, output_accumulator);
        }
        else if (instruction.substr(0, 3).compare("srl") == 0){
            assembler_R -> SRL(instruction, output_accumulator);
        }
        
        /* ::::::::::::::::::::: L FORMAT INSTRUCTIONS ::::::::::::::::::::: */

        else if (instruction.substr(0, 2).compare("lb") == 0){
            assembler_L -> LB(instruction, output_accumulator);
        }
        else if (instruction.substr(0, 2).compare("lh") == 0){
            assembler_L -> LH(instruction, output_accumulator);
        }
        else if (instruction.substr(0, 2).compare("lw") == 0){
            assembler_L -> LW(instruction, output_accumulator);
        }
        else if (instruction.substr(0, 2).compare("ld") == 0){
            assembler_L -> LD(instruction, output_accumulator);
        }

        /* ::::::::::::::::::::: P FORMAT INSTRUCTIONS ::::::::::::::::::::: */

        else if (instruction.substr(0, 2).compare("mv") == 0){
            assembler_P -> MV(instruction, output_accumulator);
        }
        else if (instruction.substr(0, 2).compare("li") == 0){
            assembler_P -> LI(instruction, output_accumulator);
        }

        else if (instruction.substr(0, 2).compare("sb") == 0){
            assembler_S -> SB(instruction, output_accumulator);
        }

        else {
            std::cout << "deu ruim" << std::endl;
        }
    }

    file_controller -> write(output_accumulator, "a.txt");
    return 0;
}