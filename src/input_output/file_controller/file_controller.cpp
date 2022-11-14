#include "file_controller.hpp"
#include "../../misc/messages/error_messages.hpp"

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

    return 1;
}

void File_controller::read(std::fstream *file, std::string filename){

    try {
        if (filename.find(".asm", filename.size() - 4) == -1){
            throw std::invalid_argument(error_messages::INVALID_INPUT_FILE_FORMAT);
        }

        file -> open("../" + filename, std::fstream::in);

        if (file -> is_open() == 0){
            throw std::runtime_error(error_messages::OPEN_INPUT_FILE_ERROR);
        }
    }
    catch (const std::invalid_argument& error){
        std::cerr << error.what() << std::endl;
        std::exit(0);
    }
    catch (const std::runtime_error& error){
        std::cerr << error.what() << std::endl;
        std::exit(0);
    }
}