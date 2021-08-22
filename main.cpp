#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include "instructionsI/instructionsI.cpp"
#include "instructionsR/instructionsR.cpp"

// ADD(R), SUB(R), AND(R), OR(R), XOR(R), ADDI(I), ANDI(I), ORI(I), SLL(R), SRL(R)

int error_message(){

    std::cout << std::endl;
    std::cout << "Parameters must be follow this format:" << std::endl;
    std::cout << "input_param filename.asm output_param filename.txt" << std::endl;
    std::cout << std::endl;
    std::cout << "suported params:" << std::endl;
    std::cout << "input: --input, -i" << std::endl;
    std::cout << "output: --output, -o" << std::endl;
    std::cout << std::endl;

    return 0;
}


int main(int argc, char *argv[]){


    std::fstream file;
    file.open("teste.asm", std::fstream::in);

    R_assembler *assembler_R = new R_assembler();
    I_assembler *assembler_I = new I_assembler();

    std::string file_line;

    while (getline(file, file_line)){
        std::cout << file_line << std::endl;
        
        if (file_line.find("addi") == 0 && file_line.find("i") == 3){
            assembler_I -> ADDI(file_line);
        }

        else if (file_line.find("ori") == 0 && file_line.find("i") == 3){
            assembler_I -> ORI(file_line);
        }

        else if (file_line.find("andi") == 0 && file_line.find("i") == 3){
            assembler_I -> ANDI(file_line);
        }
        
        else if (file_line.find("add") == 0){
            assembler_R -> ADD(file_line);
        }

        else if (file_line.find("sub") == 0){
            assembler_R -> SUB(file_line);
        }

        else if (file_line.find("and") == 0){
            assembler_R -> AND(file_line);
        }

        else if (file_line.find("or") == 0){
            assembler_R -> OR(file_line);
        }

        else if (file_line.find("xor") == 0){
            assembler_R -> XOR(file_line);
        }

        else if (file_line.find("sll") == 0){
            assembler_R -> SLL(file_line);
        }

        else if (file_line.find("srl") == 0){
            assembler_R -> SRL(file_line);
        }
    }

    return 0;
}


