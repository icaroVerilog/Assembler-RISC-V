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