
#include <string>
#include <regex>
#include <vector>

struct label_properties {
    std::string label_name;
    int first_instruction_address;
    int instruction_leap;
};

typedef struct label_properties label_properties;

class Label_identifier {

    private: std::regex label_regex;
    
    private: std::vector<label_properties> label_vector;
    
    Label_identifier(){
        this -> label_regex.assing("([A-Z]{1,10}|[a-z]{1,10})[:]");
    }

    private: bool find_label(std::string file_line, int instruction_counter){

    }
};