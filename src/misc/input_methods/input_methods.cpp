#include "input_methods.hpp"

std::fstream Input_methods::open_input_file(std::string filename){

    std::fstream file;

    try {
        file.open("../" + filename, std::fstream::in);

        if (file.is_open() == 0){
            throw std::runtime_error("assembler error: cannot open the file");
        }

        return file;
    }
    catch(const std::runtime_error &error){
        std::cerr << error.what() << std::endl;

        return file;
    }
}

// int Input_methods::handle_program_parameters() {
    
// }