#include <string>
#include <regex>
#include <vector>

#define INSTRUCTION_LEAP 4;

struct label_properties {
    std::string label_name;
    int first_instruction_address;
};

typedef struct label_properties label_properties;

class Label_accumulator {

    private: std::regex label_regex;
    private: std::vector<label_properties> label_vector;
    private: unsigned int counter;
    
    Label_accumulator();
    public: bool get_label(label_properties *label);
    public: bool find_label(std::string file_line, int instruction_counter);
}; 