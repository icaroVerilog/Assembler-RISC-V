#include "./instruction_accumulator.hpp"


Instruction_accumulator::Instruction_accumulator() {
    counter = 0;
}

void Instruction_accumulator::set_instruction(std::string& instruction) {
    this -> instructions_vector.push_back(instruction);
}

int Instruction_accumulator::get_instruction(std::string *instruction){
    std::string current_instruction;
    /* 
        Percorre todo o vector retornando o valor armazenado a cada chamada da função
        Caso chegue no final, volta para o inicio
    */
    if (counter != this -> instructions_vector.size()){

        current_instruction = this -> instructions_vector.at(this -> counter);
        this -> counter++;

        /* envia as instruções para o parametro passdo por refência*/
        *instruction = current_instruction;

        return 1;
    }

    else {
        this -> counter = 0;
        return 0;
    }
}