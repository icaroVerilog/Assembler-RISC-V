#include <iostream>
#include <string>
#include <cstddef>
#include <vector>

class Instruction_accumulator {

    private: std::vector<std::string> instructions_vector;
    private: unsigned int counter;

    public: Instruction_accumulator(){
        counter = 0;
    }

    public: void set_instruction(std::string& instruction){
        this -> instructions_vector.push_back(instruction);
    }

    public: int get_instruction(std::string *instruction){

        std::string current_instruction;

        /* 
            Percorre todo o vector retornando o valor armazenado a cada chamada da função
            Caso chegue no final, volta para o inicio
        */
        if (counter != instructions_vector.size()){

            current_instruction = instructions_vector.at(this -> counter);
            this -> counter ++;

            /* envia as instruções para o parametro passdo por refência*/
            *instruction = current_instruction;

            return 1;
        }

        else {
            
            counter = 0;
            return 0;
        }
    }

    public: int size(){
        
        int size = instructions_vector.size();
        return size;
    }
};