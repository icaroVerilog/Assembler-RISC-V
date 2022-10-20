#include "file_controller.hpp"

File_controller::File_controller(){
    
}

int File_controller::write(Instruction_accumulator *accumulator, std::string filename){

    std::fstream output_file;
    std::string binary_instruction;

    try {
        output_file.open(filename, std::fstream::app);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    while (accumulator -> get_instruction(&binary_instruction)){
        output_file << binary_instruction;
        output_file << std::endl;
    }

    output_file.close();
}

int File_controller::read(std::fstream *file, std::string filename){

    // std::fstream file;

    try {
        if (filename.find(".asm", filename.size() - 4) == -1){
            throw std::runtime_error("assembler error: invalid input file");
        }

        file -> open("../" + filename, std::fstream::in);

        if (file -> is_open() == 0){
            throw std::runtime_error("assembler error: cannot open the file");
        }

        return 1;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        return 0;
    }
}