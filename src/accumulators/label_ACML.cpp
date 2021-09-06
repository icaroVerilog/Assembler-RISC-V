#include <iostream>
#include <string>
#include <cstddef>
#include <vector>
#include "instruction_ACML.cpp"

/*
    Definição do acumulador de rótulos que será gerado um para cada rótulo encontrado na stream
*/
class Label_Accumulator: public Instruction_accumulator {

    public: std::string label_name;

    public: Label_Accumulator(std::string& label_name){
        this -> label_name = label_name;
    }
};

class Label_Accumulator_Controller {

    /* 
        deixando o campo estático para criarmo um monostate
        o monostate possibilida acessarmos apenas um objeto mais eficiente que um singleton
    */

    private: static std::vector<Label_Accumulator> controller;
    private: unsigned int counter;

    public: void new_accumulator(std::string& label_name){

        counter = 0;

        Label_Accumulator *new_label_accumulator = new Label_Accumulator(label_name);
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

                /* envia as instruções para o parametro passdo por refência*/
                *instruction = current_instruction;
    
            }
        }
        return 0;
    }
};
