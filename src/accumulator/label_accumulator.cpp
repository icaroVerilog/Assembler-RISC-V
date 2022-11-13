#include "./label_accumulator.hpp"

Label_accumulator::Label_accumulator(){
    this -> label_regex.assign("([A-Z]{1,10}|[a-z]{1,10})[:]");
    this -> counter = 0;
}

bool Label_accumulator::get_label(label_properties *label){

    label_properties current_label;

    if (counter != this -> label_vector.size()){

        current_label = this -> label_vector.at(this -> counter);
        this -> counter++;

        /* envia as instruções para o parametro passdo por refência*/
        *label = current_label;

        return true;
    }
    else {
        this -> counter = 0;
    }
}

bool Label_accumulator::find_label(std::string file_line, int instruction_counter){
        
    std::smatch regex_result;

    if (std::regex_match(file_line, regex_result, this -> label_regex) == true){
        label_properties new_label;

        /*
            Somado o valor 1, pois o rótulo nao conta como uma instrução, consequentemente
            na chamada da função o contador de insturções não incrementara quando encontrar uma label
            porem a primeira instrução da label estará a uma instrução a frente, por isso
            é incrementado o valor 1, para que a primeira instrução da label seja alcançada corretamente
        */

        new_label.label_name = file_line;
        new_label.first_instruction_address = (instruction_counter + 1) * INSTRUCTION_LEAP;
    }
}