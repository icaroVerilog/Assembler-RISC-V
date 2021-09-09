#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include "instructions/instructionsI/instructionsI.cpp"
#include "instructions/instructionsR/instructionsR.cpp"
#include "instructions/instructionsP/instructionsP.cpp"
#include "instructions/instructionsI/instructionsI_load.cpp"
// #include "accumulators/instruction_ACML.cpp"
#include "accumulators/label_ACML.cpp"

// RVI 32bits

bool is_empty(std::string file_line){

    if (file_line.size() == 0){
        return true;
    }

    for (int index = 0; index < file_line.size(); index++){

        /* (char) 32 representa o caractere espaço na tabela ASCII */
        if (file_line[index] != (char) 32){
            return false;
        }
    }

    return true;
}

bool find_label(std::string file_line){

    if (file_line[file_line.size() - 1] == ':'){
        return true;
    }

    else {
        return false;
    }
}

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
    try {
        file.open("../" + input_filename, std::fstream::in);

        if (file.is_open() == 0){
            throw std::runtime_error("assembler error: cannot open the file");
        }
    }
    catch(const std::runtime_error &error){
        std::cerr << error.what() << std::endl;

        return 0;
    }


    R_assembler  *assembler_R   = new R_assembler(filepath);
    I_assembler  *assembler_I   = new I_assembler(filepath);
    IL_assembler *assembler_IL  = new IL_assembler(filepath);
    P_assembler  *assembler_P   = new P_assembler(filepath);

    Instruction_accumulator *accumulator = new Instruction_accumulator();
    Label_Accumulator_Controller *controller = new Label_Accumulator_Controller();


    while (getline(file, file_line)){

        /* caso a string for vazia */
        if (is_empty(file_line)){
            continue;
        }

        if (find_label(file_line)){

            std::string label_line;
            std::streampos oldpos;

            std::string label_name = file_line.substr(0, file_line.size() - 1); 
            controller -> new_accumulator(label_name);
            
            /*
                o while le o arquivo até que encoontre outra label, salvando em
                oldpos a posição do ponteiro de leitura e caso encontre um novo
                rótulo, faz o arquivo retroceder uma linha e encerrando o laço
                de repetição.

                Ao encerrar a repetição, o ponteiro estára apontando para uma
                linha antes do novo rotulo, repetindo o processo
            */

            while (file.eof() == false){

                getline(file, label_line);

                if (find_label(label_line)){

                    file.seekg(oldpos);
                    break;
                }

                else {

                    controller -> set_label_instruction(label_name, label_line);
                    oldpos = file.tellg();
                }
            }
        }

        else {
            /* Insere as instruções no acumulador main, ou seja, fora de um rótulo */
            accumulator -> set_instruction(file_line);
        }
    }

    std::string instruction;

    while (accumulator -> get_instruction(&instruction)){

        /* ::::::::::::::::::::: I FORMAT INSTRUCTIONS ::::::::::::::::::::: */

        if (instruction.find("addi") == 0 && instruction.find("i") == 3){
            assembler_I -> ADDI(instruction, print_flag);
        }

        else if (instruction.find("ori") == 0 && instruction.find("i") == 3){
            assembler_I -> ORI(instruction, print_flag);
        }

        else if (instruction.find("andi") == 0 && instruction.find("i") == 3){
            assembler_I -> ANDI(instruction, print_flag);
        }

        else if (instruction.find("xori") == 0 && instruction.find("i") == 3){
            assembler_I -> XORI(instruction, print_flag);
        }

        else if (instruction.find("slli") == 0 && instruction.find("i") == 3){
            assembler_I -> SLLI(instruction, print_flag);
        }

        else if (instruction.find("srli") == 0 && instruction.find("i") == 3){
            assembler_I -> SRLI(instruction, print_flag);
        }

        else if (instruction.find("srli") == 0 && instruction.find("i") == 3){
            assembler_I -> SRLI(instruction, print_flag);
        }

        /* ::::::::::::::::::::: R FORMAT INSTRUCTIONS ::::::::::::::::::::: */

        else if (instruction.find("add") == 0){
            assembler_R -> ADD(instruction, print_flag);
        }

        else if (instruction.find("sub") == 0){
            assembler_R -> SUB(instruction, print_flag);
        }

        else if (instruction.find("and") == 0){
            std::cout << "entrou" << std::endl;
            assembler_R -> AND(instruction, print_flag);
        }

        else if (instruction.find("or") == 0){
            assembler_R -> OR(instruction, print_flag);
        }

        else if (instruction.find("xor") == 0){
            assembler_R -> XOR(instruction, print_flag);
        }

        else if (instruction.find("sll") == 0){
            assembler_R -> SLL(instruction, print_flag);
        }

        else if (instruction.find("srl") == 0){
            assembler_R -> SRL(instruction, print_flag);
        }

        /* ::::::::::::::::::::: P FORMAT INSTRUCTIONS ::::::::::::::::::::: */

        else if (instruction.find("mv") == 0){
            assembler_P -> MV(instruction, print_flag);
        }

        else if (instruction.find("li") == 0){
            assembler_P -> LI(instruction, print_flag);
        }

    }
    return 0;
}