#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include "instructions/instructions_assembler/instructionsI/instructionsI.cpp"
#include "instructions/instructions_assembler/instructionsB/instructionsB.cpp"
#include "instructions/instructions_assembler/instructionsR/instructionsR.cpp"
#include "instructions/instructions_assembler/instructionsP/instructionsP.cpp"
#include "instructions/instructions_assembler/instructionsS/instructionsS.cpp"
#include "instructions/instructions_assembler/instructionsI/instructionsI_load.cpp"

#include "accumulator/instruction_accumulator.hpp"
#include "accumulator/label_accumulator.hpp"
#include "misc/auxiliar_methods/auxiliar_methods.hpp"
#include "input_output/file_controller/file_controller.hpp"
#include "input_output/parameter_reader/parameter_reader.cpp"

#include "misc/messages/error_messages.hpp"

// RVI 64bits

int main(int argc, char *argv[]){

    /*
    
        ┬  ┬┌─┐┬─┐┬┌─┐┌┐ ┬  ┌─┐  ┌─┐┌┐┌┌┬┐  ┌─┐┌─┐┌┐┌┌─┐┌┬┐┌─┐┌┐┌┌┬┐┌─┐  ┌┬┐┌─┐┌─┐┬  ┌─┐┬─┐┌─┐┌┬┐┬┌─┐┌┐┌┌─┐
        └┐┌┘├─┤├┬┘│├─┤├┴┐│  ├┤   ├─┤│││ ││  │  │ ││││└─┐ │ ├─┤│││ │ └─┐   ││├┤ │  │  ├─┤├┬┘├─┤ │ ││ ││││└─┐
         └┘ ┴ ┴┴└─┴┴ ┴└─┘┴─┘└─┘  ┴ ┴┘└┘─┴┘  └─┘└─┘┘└┘└─┘ ┴ ┴ ┴┘└┘ ┴ └─┘  ─┴┘└─┘└─┘┴─┘┴ ┴┴└─┴ ┴ ┴ ┴└─┘┘└┘└─┘

    */

    int register_counter = 0;

    std::string file_line;
    std::string filepath;
    std::string current_instruction;

    std::fstream input_file;

    /*
    
        ┌─┐┬  ┌─┐┌─┐┌─┐  ┬┌┐┌┌─┐┌┬┐┌─┐┌┐┌┌┬┐┬┌─┐┌┬┐┬┌─┐┌┐┌┌─┐
        │  │  ├─┤└─┐└─┐  ││││└─┐ │ ├─┤│││ │ │├─┤ │ ││ ││││└─┐
        └─┘┴─┘┴ ┴└─┘└─┘  ┴┘└┘└─┘ ┴ ┴ ┴┘└┘ ┴ ┴┴ ┴ ┴ ┴└─┘┘└┘└─┘

    */

    Parameter_reader *parameter_reader = new Parameter_reader();

    R_assembler *assembler_R = new R_assembler();
    B_assembler *assembler_B = new B_assembler();
    I_assembler *assembler_I = new I_assembler();
    S_assembler *assembler_S = new S_assembler();
    L_assembler *assembler_L = new L_assembler();
    P_assembler *assembler_P = new P_assembler();

    Instruction_accumulator  *input_accumulator  = new Instruction_accumulator();
    Instruction_accumulator  *output_accumulator = new Instruction_accumulator();
    Auxiliar_methods         *auxiliar_methods   = new Auxiliar_methods();
    File_controller          *file_controller    = new File_controller();
    Label_accumulator        *label_accumulator  = new Label_accumulator();


    /*
    
        ┌─┐┬  ┌─┐┌─┐┬─┐┬┌┬┐┬ ┬┌┬┐  ┬  ┌─┐┌─┐┬┌─┐
        ├─┤│  │ ┬│ │├┬┘│ │ ├─┤│││  │  │ ││ ┬││  
        ┴ ┴┴─┘└─┘└─┘┴└─┴ ┴ ┴ ┴┴ ┴  ┴─┘└─┘└─┘┴└─┘

    */


    try {

        // type_parameter parameter_values = parameter_reader -> read(argc, argv);
        // int read_file_result = file_controller -> read(&input_file, parameter_values.input_file);

        file_controller -> read(&input_file, "example.asm");

        while (getline(input_file, file_line)){

            /* caso a string for vazia */
            if (auxiliar_methods -> is_empty(file_line)){
                continue;
            }

            auxiliar_methods  -> remove_space(file_line);
            
            bool label_founded = label_accumulator -> find_label(file_line, register_counter);

            if (label_founded == false){
                register_counter++;
                input_accumulator -> set_instruction(file_line);
            }
        }

        while (input_accumulator -> get_instruction(&current_instruction)){

            /* ::::::::::::::::::::: I FORMAT INSTRUCTIONS ::::::::::::::::::::: */

            if (current_instruction.substr(0, 4).compare("addi") == 0){
                assembler_I -> ADDI(current_instruction, output_accumulator);
            }
            else if (current_instruction.substr(0, 3).compare("ori") == 0){
                assembler_I -> ORI(current_instruction, output_accumulator);
            }
            else if (current_instruction.substr(0, 4).compare("andi") == 0){
                assembler_I -> ANDI(current_instruction, output_accumulator);
            }
            else if (current_instruction.substr(0, 4).compare("xori") == 0){
                assembler_I -> XORI(current_instruction, output_accumulator);
            }
            else if (current_instruction.substr(0, 4).compare("slli") == 0){
                assembler_I -> SLLI(current_instruction, output_accumulator);
            }
            else if (current_instruction.substr(0, 4).compare("srli") == 0){
                assembler_I -> SRLI(current_instruction, output_accumulator);
            }

            /* ::::::::::::::::::::: R FORMAT INSTRUCTIONS ::::::::::::::::::::: */

            else if (current_instruction.substr(0, 3).compare("add") == 0){
                assembler_R -> ADD(current_instruction, output_accumulator);
            }
            else if (current_instruction.substr(0, 3).compare("sub") == 0){
                assembler_R -> SUB(current_instruction, output_accumulator);
            }
            else if (current_instruction.substr(0, 3).compare("and") == 0){
                assembler_R -> AND(current_instruction, output_accumulator);
            }
            else if (current_instruction.substr(0, 2).compare("or") == 0){
                assembler_R -> OR(current_instruction, output_accumulator);
            }
            else if (current_instruction.substr(0, 3).compare("xor") == 0){
                assembler_R -> XOR(current_instruction, output_accumulator);
            }
            else if (current_instruction.substr(0, 3).compare("sll") == 0){
                assembler_R -> SLL(current_instruction, output_accumulator);
            }
            else if (current_instruction.substr(0, 3).compare("srl") == 0){
                assembler_R -> SRL(current_instruction, output_accumulator);
            }
            
            /* ::::::::::::::::::::: L FORMAT INSTRUCTIONS ::::::::::::::::::::: */

            else if (current_instruction.substr(0, 2).compare("lb") == 0){
                assembler_L -> LB(current_instruction, output_accumulator);
            }
            else if (current_instruction.substr(0, 2).compare("lh") == 0){
                assembler_L -> LH(current_instruction, output_accumulator);
            }
            else if (current_instruction.substr(0, 2).compare("lw") == 0){
                assembler_L -> LW(current_instruction, output_accumulator);
            }
            else if (current_instruction.substr(0, 2).compare("ld") == 0){
                assembler_L -> LD(current_instruction, output_accumulator);
            }

            /* ::::::::::::::::::::: S FORMAT INSTRUCTIONS ::::::::::::::::::::: */

            else if (current_instruction.substr(0, 2).compare("sb") == 0){
                assembler_S -> SB(current_instruction, output_accumulator);
            }
            else if (current_instruction.substr(0, 2).compare("sh") == 0){
                assembler_S -> SH(current_instruction, output_accumulator);
            }
            else if (current_instruction.substr(0, 2).compare("sw") == 0){
                assembler_S -> SW(current_instruction, output_accumulator);
            }
            else if (current_instruction.substr(0, 2).compare("sd") == 0){
                assembler_S -> SD(current_instruction, output_accumulator);
            }

            /* ::::::::::::::::::::: P FORMAT INSTRUCTIONS ::::::::::::::::::::: */

            else if (current_instruction.substr(0, 2).compare("mv") == 0){
                assembler_P -> MV(current_instruction, output_accumulator);
            }
            else if (current_instruction.substr(0, 2).compare("li") == 0){
                assembler_P -> LI(current_instruction, output_accumulator);
            }

            /* ::::::::::::::::::::: B FORMAT INSTRUCTIONS ::::::::::::::::::::: */

            else if (current_instruction.substr(0, 3).compare("beq") == 0){
                assembler_B -> BEQ(current_instruction, output_accumulator, label_accumulator);
            }
            else if (current_instruction.substr(0, 3).compare("bne") == 0){
                assembler_B -> BNE(current_instruction, output_accumulator, label_accumulator);
            }
            else if (current_instruction.substr(0, 3).compare("blt") == 0){
                assembler_B -> BLT(current_instruction, output_accumulator, label_accumulator);
            }
            else if (current_instruction.substr(0, 3).compare("bge") == 0){
                assembler_B -> BGE(current_instruction, output_accumulator, label_accumulator);
            }
            else if (current_instruction.substr(0, 4).compare("bltu") == 0){
                assembler_B -> BLTU(current_instruction, output_accumulator, label_accumulator);
            }
            else if (current_instruction.substr(0, 4).compare("bgeu") == 0){
                assembler_B -> BGEU(current_instruction, output_accumulator, label_accumulator);
            }

            else {
                throw std::invalid_argument(error_messages::INVALID_INSTRUCTION);
            }
        }

        file_controller -> write(output_accumulator, "a.txt");
        return 0;

    }
    catch (const std::invalid_argument& error){
        std::cerr << error.what() << std::endl;
        std::exit(0);
    }
}