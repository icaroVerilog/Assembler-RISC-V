#include <string>
#include <regex>

struct label_properties {
    int size_in_instructions;
    int size_in_address_leap;
};

typedef struct label_properties label_properties;



class Label_identifier {

    private: std::string label_name;
    private: std::regex label_regex;
    private: std::vector<label_properties> labels_properties;

    private: bool label_founded = false;
    private: bool first_label_founded = false;
    private: int size_in_instructions = 0;
    private: int size_in_address_leap = 0;

    public: Label_identifier() {
        label_regex.assign("([A-Z]{1,12}[:])");
    }

    // public: label_properties get_label_properties(){

    //     label_properties props;
    //     props.size_in_address_leap = this -> size_in_address_leap;
    //     props.size_in_instructions = this -> size_in_instructions;

    //     return props;
    // }

    public: bool find_label(std::string& file_line){

        std::smatch regex_result;

        /*
            Caso a linha seja uma instrução dentro de uma label
            pois label founded terá o valor TRUE
            e a regex for falsa (for uma instrução)
        */
        if (label_founded == true && std::regex_match(file_line, regex_result, label_regex) == false){

            this -> size_in_instructions = this -> size_in_instructions + 1;
            this -> size_in_address_leap = this -> size_in_address_leap + 4;

            return true;
        }
        /*
            Caso a linha seja uma label, devera inserir no vetor
            dos dados das labels, os dados a label que foi lida até o determinado momento
        */
        if (std::regex_match(file_line, regex_result, label_regex) == true){
            
            label_properties props;
            props.size_in_address_leap = this -> size_in_address_leap;
            props.size_in_instructions = this -> size_in_instructions;

            this -> labels_properties.push_back(props);

            /* Zerando os dados do corpo da classe */

            this -> size_in_address_leap = 0;
            this -> size_in_instructions = 0;

            label_founded = true;
            return true;

        }


        // if (std::regex_match(file_line, regex_result, label_regex) == false){
        //     label_founded = false;
        //     return false;
        // }
        // else {
        //     label_founded = true;
        //     return true;
        // }

        // if (label_founded == true){
        //     this -> size_in_instructions = this -> size_in_instructions + 1;
        //     this -> size_in_address_leap = this -> size_in_address_leap + 4;

        //     return true;
        // }   
        // else {
        //     return false;
        // }
    }
};