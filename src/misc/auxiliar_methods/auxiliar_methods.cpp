#include "auxiliar_methods.hpp"

bool Auxiliar_methods::remove_space(std::string& string){

    int counter = 0;

    for (int index = 0; index < string.size(); index++){
        
        if (string[index] == (char) 32){
            counter++;
        }
        if (string[index] != (char) 32){
            break;
        }
    }
    string.erase(0, counter);

    return true;
}

bool Auxiliar_methods::is_empty(std::string file_line){

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