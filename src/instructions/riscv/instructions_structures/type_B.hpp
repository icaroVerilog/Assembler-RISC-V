#ifndef TYPE_B
#define TYPE_B

#include <string>

typedef struct B_instruction B_instruction;

struct B_instruction {
    std::string source_register1;
    std::string source_register2;
    std::string label_name;
};

#endif 