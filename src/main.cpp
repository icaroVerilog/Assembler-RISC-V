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

    std::fstream file;

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

    std::string file_line;
    std::string filepath = "../" + output_filename;

    R_assembler  *assembler_R  = new R_assembler(filepath);
    I_assembler  *assembler_I  = new I_assembler(filepath);
    IL_assembler *assembler_IL = new IL_assembler(filepath);
    P_assembler  *assembler_P  = new P_assembler(filepath);

    Instruction_accumulator *accumulator = new Instruction_accumulator();
    Label_Accumulator_Controller *controller = new Label_Accumulator_Controller;

    while (getline(file, file_line)){

        /* retirando os espaços da string */
        // file_line.erase(remove_if(file_line.begin(), file_line.end(), isspace), file_line.end());

        /* caso a string for vazia */
        if (is_empty(file_line)){
            continue;
        }

        if (find_label(file_line)){

            std::string label_line;
            std::streampos oldpos;

            std::string label_name = file_line.substr(0, file_line.size() - 1); 
            controller -> new_accumulator(label_name);
            // std::cout <<  label_name << std::endl;
            
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

                    // std::cout << label_line << std::endl;
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

    /*
        Problema: na linha 172 consta que a instrução do rotulo 2 está sendo enviada corretamente
        porem na hora de exibilas não exibe corretamentes
    */




    // std::string instruction;
    // while(accumulator -> get_instruction(&instruction)){

    //     std::cout << instruction << std::endl;

    // }

    std::string instruction3;
    std::string b = "label3";
    
    while(controller -> get_label_instruction(b , &instruction3)){
        std::cout << instruction3 << std::endl;
    }

    // while (getline(file, file_line)){

    //     /* ::::::::::::::::::::: I FORMAT INSTRUCTIONS ::::::::::::::::::::: */

    //     if (file_line.find("addi") == 0 && file_line.find("i") == 3){
    //         assembler_I -> ADDI(file_line, print_flag);
    //     }

    //     else if (file_line.find("ori") == 0 && file_line.find("i") == 3){
    //         assembler_I -> ORI(file_line, print_flag);
    //     }

    //     else if (file_line.find("andi") == 0 && file_line.find("i") == 3){
    //         assembler_I -> ANDI(file_line, print_flag);
    //     }

    //     if (file_line.find("xori") == 0 && file_line.find("i") == 3){
    //         assembler_I -> XORI(file_line, print_flag);
    //     }

    //     if (file_line.find("slli") == 0 && file_line.find("i") == 3){
    //         assembler_I -> SLLI(file_line, print_flag);
    //     }

    //     if (file_line.find("srli") == 0 && file_line.find("i") == 3){
    //         assembler_I -> SRLI(file_line, print_flag);
    //     }

    //     if (file_line.find("srli") == 0 && file_line.find("i") == 3){
    //         assembler_I -> SRLI(file_line, print_flag);
    //     }

    //     /* ::::::::::::::::::::: R FORMAT INSTRUCTIONS ::::::::::::::::::::: */

    //     else if (file_line.find("add") == 0){
    //         assembler_R -> ADD(file_line, print_flag);
    //     }

    //     else if (file_line.find("sub") == 0){
    //         assembler_R -> SUB(file_line, print_flag);
    //     }

    //     else if (file_line.find("and") == 0){
    //         assembler_R -> AND(file_line, print_flag);
    //     }

    //     else if (file_line.find("or") == 0){
    //         assembler_R -> OR(file_line, print_flag);
    //     }

    //     else if (file_line.find("xor") == 0){
    //         assembler_R -> XOR(file_line, print_flag);
    //     }

    //     else if (file_line.find("sll") == 0){
    //         assembler_R -> SLL(file_line, print_flag);
    //     }

    //     else if (file_line.find("srl") == 0){
    //         assembler_R -> SRL(file_line, print_flag);
    //     }

    //     /* ::::::::::::::::::::: P FORMAT INSTRUCTIONS ::::::::::::::::::::: */

    //     else if (file_line.find("mv") == 0){
    //         assembler_P -> MV(file_line, print_flag);
    //     }

    //     else if (file_line.find("li") == 0){
    //         assembler_P -> LI(file_line, print_flag);
    //     }

    // }
    // return 0;
}


