
#include <string>
#include <regex>
#include <vector>

#define INSTRUCTION_LEAP 4;

struct label_properties {
    std::string label_name;
    int first_instruction_address;
};

typedef struct label_properties label_properties;

class Label_identifier {

    private: std::regex label_regex;
    private: std::vector<label_properties> label_vector;
    
    Label_identifier(){
        this -> label_regex.assing("([A-Z]{1,10}|[a-z]{1,10})[:]");
    }

    private: bool find_label(std::string file_line, int instruction_counter){
        
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
};