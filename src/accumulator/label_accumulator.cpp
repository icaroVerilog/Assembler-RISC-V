#include "./label_accumulator.hpp"

Label_accumulator::Label_accumulator(){
    this -> label_regex.assign("([A-Z]{1,10}|[a-z]{1,10})[:]");
    this -> counter = 0;
    this -> break_loop_flag = false;
}

bool Label_accumulator::get_label(label_properties *label){

    label_properties current_label;
    bool break_loop_flag = false;

    if (break_loop_flag == true){
        return false;
    }

    if (counter != this -> label_vector.size()){

        current_label = this -> label_vector.at(this -> counter);
        this -> counter++;

        /* envia as instruções para o parametro passdo por refência*/
        *label = current_label;

        return true;
    }
    else {
        this -> counter = 0;
        this -> break_loop_flag = true;
        
        return true;
    }
}

bool Label_accumulator::find_label(std::string file_line, int instruction_counter){

    std::smatch regex_result;

    if (std::regex_match(file_line, regex_result, this -> label_regex) == true){

        label_properties new_label;

        file_line = file_line.substr(0, file_line.size() - 1);

        new_label.label_name = file_line;
        new_label.first_instruction_address = instruction_counter * 4;

        this -> label_vector.push_back(new_label);

        return true;
    }
    else {
        return false;
    }
}