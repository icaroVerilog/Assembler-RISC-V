#include <iostream>
#include <fstream>
#include <string>

class Input_methods {
    public: int handle_program_parameters();
    public: std::fstream open_input_file(std::string filename);
};