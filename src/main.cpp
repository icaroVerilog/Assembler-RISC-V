#include <iostream>
#include <fstream>
#include <cstddef>
#include <string>
#include <map>

#include "instructions/instructionsI/instructionsI.cpp"
#include "instructions/instructionsR/instructionsR.cpp"
#include "instructions/instructionsP/instructionsP.cpp"
#include "accumulators/label_accumulator.cpp"

// ADD(R), SUB(R), AND(R), OR(R), XOR(R), ADDI(I), ANDI(I), ORI(I), SLL(R), SRL(R)

void error_message(){
    std::cout << std::endl;
    std::cout << "Parameters must be follow this format:" << std::endl;
    std::cout << "filename.asm output_param filename or filename.asm output_param filename" << std::endl;
    std::cout << std::endl;
    std::cout << "suported params:" << std::endl;
    std::cout << "output: --output, -o" << std::endl;
    std::cout << std::endl;
}

int get_label(std::string file_line, std::fstream file, Label_accumulator_controller *controller){
    
    std::string label_name = file_line.substr(0, file_line.length());
    std::string substring = file_line.substr(file_line.length() - 1, file_line.length());
    std::string current_line;
    std::string previous_line;

    controller -> new_accumulator(label_name);
    getline(file, current_line);

    while(file.eof() == false){

        /* Caso a proxima linha for o inicio de outra label */
        if (current_line.substr(current_line.length() - 1, current_line.length()) == ":"){
            
            break;
        }

        /* Caso a label esteja vazia */
        if (current_line == ""){
            break;
        }

        else {
            controller -> set_label_instruction(label_name, current_line);
            getline(file, current_line);
        }


    }

}

int main(int argc, char *argv[]){

    Label_accumulator_controller *controller = new Label_accumulator_controller();

    bool print_flag;

    std::string input_filename;
    std::string open_parameter;
    std::string output_filename;
    std::string instruction;
    std::string file_line;

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

            print_flag = false;
        }

        else if (argc == 2){

            input_filename = argv[1];
            print_flag = true;
        }

        else {
            error_message();
            throw std::runtime_error("assembler error: invalid parameters");
        }
    }
    catch (const std::runtime_error &error){
        error_message();
        std::cerr << error.what() << std::endl;
        return 0;
    }

    try {
        file.open("../" + input_filename, std::fstream::in);

        if (file.is_open() == 0){
            throw std::runtime_error("file error: cannot open the file");
        }
    }
    catch (const std::runtime_error &error){
        std::cerr << error.what() << std::endl;
        return 0;
    }

    std::string filepath = "../" + output_filename;

    R_assembler *assembler_R = new R_assembler(filepath);
    I_assembler *assembler_I = new I_assembler(filepath);
    P_assembler *assembler_P = new P_assembler(filepath);

    Instruction_accumulator *instruction_accumulator = new Instruction_accumulator();
    
    while (getline(file, file_line)){

        std::string label_name = file_line.substr(0, file_line.length());
        std::string substring = file_line.substr(file_line.length() - 1, file_line.length());

        if (substring == ":"){
            


        }

        
        std::cout << "entrou" << std::endl;
        instruction_accumulator -> set_instruction(file_line);
        
    }

    while (instruction_accumulator -> get_instruction(&instruction)){

        if (instruction.find("addi") == 0 && instruction.find("i") == 3){
            assembler_I -> ADDI(instruction, print_flag);
        }

        else if (instruction.find("ori") == 0 && instruction.find("i") == 3){
            assembler_I -> ORI(instruction, print_flag);
        }

        else if (instruction.find("andi") == 0 && instruction.find("i") == 3){
            assembler_I -> ANDI(instruction, print_flag);
        }
        
        else if (instruction.find("add") == 0){
            assembler_R -> ADD(instruction, print_flag);
        }

        else if (instruction.find("sub") == 0){
            assembler_R -> SUB(instruction, print_flag);
        }

        else if (instruction.find("and") == 0){
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

        else if (instruction.find("mv") == 0){
            assembler_P -> MV(instruction, print_flag);
        }

        else if (instruction.find("li") == 0){
            assembler_P -> LI(instruction, print_flag);
        }
    }
    return 0;
}