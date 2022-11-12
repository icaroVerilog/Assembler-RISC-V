#include "auxiliar_methods.hpp"


bool Auxiliar_methods::remove_space(std::string& file_line){
    /*  
        remove_if() can't change the string length(only modify the values) 
        we have called string::erase to actually modify the length of the string
    */
    
    file_line.erase(remove_if(file_line.begin(), file_line.end(), isspace), file_line.end());

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