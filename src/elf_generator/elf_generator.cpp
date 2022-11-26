#include "elf_generator.hpp"


ELF_generator::ELF_generator(std::string filename){
    try {
        this -> output_file = fopen("filename", "wb");

        if (this -> output_file == NULL){
            throw std::runtime_error(error_messages::OPEN_OUTPUT_FILE_ERROR);
        }
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        std::exit(0);
    }
}