#include "elf_generator.hpp"

class ELF_generator {
    private: std::fstream output_file;
    
    public: ELF_generator(std::string filename){
       try {
            this -> output_file.open(filename, std::fstream::app);
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        } 
    }

    private: int write_header(){

    }

    public: int write_ELF(){

    }

}