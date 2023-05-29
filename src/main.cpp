#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>


#include "accumulator/instruction_accumulator.hpp"
#include "accumulator/label_accumulator.hpp"
#include "misc/auxiliar_methods/auxiliar_methods.hpp"
#include "input_output/file_controller/file_controller.hpp"
#include "input_output/parameter_reader/parameter_reader.cpp"

#include "misc/messages/error_messages.hpp"


#include "instructions/riscv/riscv_instruction_reader.hpp"

// RVI 64bits

int main(int argc, char *argv[]){

    /*
    
        ┬  ┬┌─┐┬─┐┬┌─┐┌┐ ┬  ┌─┐  ┌─┐┌┐┌┌┬┐  ┌─┐┌─┐┌┐┌┌─┐┌┬┐┌─┐┌┐┌┌┬┐┌─┐  ┌┬┐┌─┐┌─┐┬  ┌─┐┬─┐┌─┐┌┬┐┬┌─┐┌┐┌┌─┐
        └┐┌┘├─┤├┬┘│├─┤├┴┐│  ├┤   ├─┤│││ ││  │  │ ││││└─┐ │ ├─┤│││ │ └─┐   ││├┤ │  │  ├─┤├┬┘├─┤ │ ││ ││││└─┐
         └┘ ┴ ┴┴└─┴┴ ┴└─┘┴─┘└─┘  ┴ ┴┘└┘─┴┘  └─┘└─┘┘└┘└─┘ ┴ ┴ ┴┘└┘ ┴ └─┘  ─┴┘└─┘└─┘┴─┘┴ ┴┴└─┴ ┴ ┴ ┴└─┘┘└┘└─┘

    */

    int register_counter = 0;

    std::string file_line;
    std::string filepath;
    std::string current_instruction;

    std::fstream input_file;

    /*
    
        ┌─┐┬  ┌─┐┌─┐┌─┐  ┬┌┐┌┌─┐┌┬┐┌─┐┌┐┌┌┬┐┬┌─┐┌┬┐┬┌─┐┌┐┌┌─┐
        │  │  ├─┤└─┐└─┐  ││││└─┐ │ ├─┤│││ │ │├─┤ │ ││ ││││└─┐
        └─┘┴─┘┴ ┴└─┘└─┘  ┴┘└┘└─┘ ┴ ┴ ┴┘└┘ ┴ ┴┴ ┴ ┴ ┴└─┘┘└┘└─┘

    */

    Parameter_reader *parameter_reader = new Parameter_reader();

    Instruction_accumulator  *input_accumulator  = new Instruction_accumulator();
    Instruction_accumulator  *output_accumulator = new Instruction_accumulator();
    Auxiliar_methods         *auxiliar_methods   = new Auxiliar_methods();
    File_controller          *file_controller    = new File_controller();
    Label_accumulator        *label_accumulator  = new Label_accumulator();

    Riscv_instruction_reader *RISCV = new Riscv_instruction_reader();

    /*
    
        ┌─┐┬  ┌─┐┌─┐┬─┐┬┌┬┐┬ ┬┌┬┐  ┬  ┌─┐┌─┐┬┌─┐
        ├─┤│  │ ┬│ │├┬┘│ │ ├─┤│││  │  │ ││ ┬││  
        ┴ ┴┴─┘└─┘└─┘┴└─┴ ┴ ┴ ┴┴ ┴  ┴─┘└─┘└─┘┴└─┘

    */


    try {

        // type_parameter parameter_values = parameter_reader -> read(argc, argv);
        // int read_file_result = file_controller -> read(&input_file, parameter_values.input_file);

        file_controller -> read(&input_file, "example.asm");

        while (getline(input_file, file_line)){

            /* caso a string for vazia */
            if (auxiliar_methods -> is_empty(file_line)){
                continue;
            }

            auxiliar_methods  -> remove_space(file_line);
            
            bool label_founded = label_accumulator -> find_label(file_line, register_counter);

            if (label_founded == false){
                register_counter++;
                input_accumulator -> set_instruction(file_line);
            }
        }
        
        RISCV -> execute(input_accumulator, output_accumulator, label_accumulator);

        file_controller -> write(output_accumulator, "a.txt");
        return 0;

    }
    catch (const std::invalid_argument& error){
        std::cerr << error.what() << std::endl;
        std::exit(0);
    }
}