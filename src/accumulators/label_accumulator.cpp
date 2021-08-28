#include <iostream>
#include <string>
#include <cstddef>
#include <vector>
#include "instruction_accumulator.cpp"

class Label_accumulator: public Instruction_accumulator {

    public: std::string label_name;

    public: Label_accumulator(std::string& label_name){
        this -> label_name = label_name;
    }
};

/* Controlador  responsável por armazenar todos os rótulos e suas respectivas instruções*/
class Label_accumulator_controller {

    private: std::vector<Label_accumulator> controller;
    private: unsigned int counter;

    public: void new_accumulator(std::string& label_name){

        counter = 0;

        Label_accumulator *new_label_accumulator = new Label_accumulator(label_name);
        this -> controller.push_back(*new_label_accumulator);
    }

    /* Verifica se existe uma label com o nome passado dentre do controlador, retornando o indice do mesmo */
    public: int find_accumulator(std::string& label_name){

        for (int index = 0; index < controller.size(); index++){
            if (this -> controller[index].label_name == label_name){
                return index;
            }
        }
        
        return 0;
    }

    public: int set_label_instruction(std::string& label_name, std::string instruction){

        int accumulator_index = find_accumulator(label_name);
        this -> controller.at(accumulator_index).set_instruction(instruction);

        return 1;
    }

    /* 
        Caso o rótulo desejado esteja dentro do controlador, a função irá ler todas as suas intruções
        até a função get_instruction retornar 0
    */
    public: int get_label_instruction(std::string& label_name, std::string *instruction){

        std::string current_instruction;

        for (int index = 0; index < controller.size(); index++){
            if (this -> controller[index].label_name == label_name){
                
                this -> controller[index].get_instruction(&current_instruction);
                *instruction = current_instruction;
    
            }
        }
        return 0;
    }
};