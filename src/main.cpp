#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include "instructions/instructionsI/instructionsI.cpp"
#include "instructions/instructionsR/instructionsR.cpp"
#include "instructions/instructionsP/instructionsP.cpp"

// ADD(R), SUB(R), AND(R), OR(R), XOR(R), ADDI(I), ANDI(I), ORI(I), SLL(R), SRL(R)

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

    R_assembler *assembler_R = new R_assembler(filepath);
    I_assembler *assembler_I = new I_assembler(filepath);
    P_assembler *assembler_P = new P_assembler(filepath);

    while (getline(file, file_line)){
        
        if (file_line.find("addi") == 0 && file_line.find("i") == 3){
            assembler_I -> ADDI(file_line, print_flag);
        }

        else if (file_line.find("ori") == 0 && file_line.find("i") == 3){
            assembler_I -> ORI(file_line, print_flag);
        }

        else if (file_line.find("andi") == 0 && file_line.find("i") == 3){
            assembler_I -> ANDI(file_line, print_flag);
        }
        
        else if (file_line.find("add") == 0){
            assembler_R -> ADD(file_line, print_flag);
        }

        else if (file_line.find("sub") == 0){
            assembler_R -> SUB(file_line, print_flag);
        }

        else if (file_line.find("and") == 0){
            assembler_R -> AND(file_line, print_flag);
        }

        else if (file_line.find("or") == 0){
            assembler_R -> OR(file_line, print_flag);
        }

        else if (file_line.find("xor") == 0){
            assembler_R -> XOR(file_line, print_flag);
        }

        else if (file_line.find("sll") == 0){
            assembler_R -> SLL(file_line, print_flag);
        }

        else if (file_line.find("srl") == 0){
            assembler_R -> SRL(file_line, print_flag);
        }

        else if (file_line.find("mv") == 0){
            assembler_P -> MV(file_line, print_flag);
        }

        else if (file_line.find("li") == 0){
            assembler_P -> LI(file_line, print_flag);
        }

    }
    return 0;
}


