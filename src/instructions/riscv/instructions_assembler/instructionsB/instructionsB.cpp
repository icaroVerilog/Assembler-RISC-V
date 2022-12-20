#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <boost/convert.hpp>
#include <bitset>
#include "../../instructions_structures/type_I.hpp"
#include "../../convert_methods/convert_methods.hpp"
#include "../../instruction_parser/instruction_parser.hpp"
#include "../../../../accumulator/instruction_accumulator.hpp"
#include "../../../../accumulator/label_accumulator.hpp"
#include "../../../../misc/messages/error_messages.hpp"

class B_assembler: public Convert_methods, public Instruction_parser {

    private: std::string opcode_B;

    private:
        std::string funct3_BEQ;
        std::string funct3_BNE;
        std::string funct3_BLT;
        std::string funct3_BGE;
        std::string funct3_BLTU;
        std::string funct3_BGEU;

    public: B_assembler(){

        this -> opcode_B.assign("1100011");

        this -> funct3_BEQ.assign("000");
        this -> funct3_BNE.assign("001");
        this -> funct3_BLT.assign("100");
        this -> funct3_BGE.assign("101");
        this -> funct3_BLTU.assign("110");
        this -> funct3_BGEU.assign("111");        
    }

    /* Find the label literal and convert to program counter address */
    private: int label_to_address(std::string label, Label_accumulator* label_accumulator){

        try {
            label_properties label_props;

            while (label_accumulator -> get_label(&label_props)){

                if (label_props.label_name == label){
                    return label_props.first_instruction_address;
                }
            }

            /* refatorar erro */
            throw std::runtime_error(error_messages::INVALID_LABEL_ERROR);

        }
        catch(const std::exception& e) {
            std::exit(0);
        }
    }

    public: void BEQ(std::string &string, Instruction_accumulator* accumulator, Label_accumulator* label_accumulator){
        
        B_instruction instruction = B_type_parse(string);

        std::string source_register1 = register_to_binary(instruction.source_register1);
        std::string source_register2 = register_to_binary(instruction.source_register2);
        std::string label_address = label_address_to_binary(this -> label_to_address(instruction.label_name, label_accumulator));

        std::string assembled_binary = b_binary_to_string(
            label_address,
            source_register2,
            source_register1,
            this -> funct3_BEQ,
            this -> opcode_B
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void BNE(std::string& string, Instruction_accumulator* accumulator, Label_accumulator* label_accumulator){

        B_instruction instruction = B_type_parse(string);

        std::string source_register1 = register_to_binary(instruction.source_register1);
        std::string source_register2 = register_to_binary(instruction.source_register2);
        std::string label_address = label_address_to_binary(this -> label_to_address(instruction.label_name, label_accumulator));

        std::string assembled_binary = b_binary_to_string(
            label_address,
            source_register2,
            source_register1,
            this -> funct3_BNE,
            this -> opcode_B
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void BLT(std::string& string, Instruction_accumulator* accumulator, Label_accumulator* label_accumulator){

        B_instruction instruction = B_type_parse(string);

        std::string source_register1 = register_to_binary(instruction.source_register1);
        std::string source_register2 = register_to_binary(instruction.source_register2);
        std::string label_address = label_address_to_binary(this -> label_to_address(instruction.label_name, label_accumulator));

        std::string assembled_binary = b_binary_to_string(
            label_address,
            source_register2,
            source_register1,
            this -> funct3_BLT,
            this -> opcode_B
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void BGE(std::string& string, Instruction_accumulator* accumulator, Label_accumulator* label_accumulator){
        
        B_instruction instruction = B_type_parse(string);

        std::string source_register1 = register_to_binary(instruction.source_register1);
        std::string source_register2 = register_to_binary(instruction.source_register2);
        std::string label_address = label_address_to_binary(this -> label_to_address(instruction.label_name, label_accumulator));

        std::string assembled_binary = b_binary_to_string(
            label_address,
            source_register2,
            source_register1,
            this -> funct3_BGE,
            this -> opcode_B
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void BLTU(std::string& string, Instruction_accumulator* accumulator, Label_accumulator* label_accumulator){

        B_instruction instruction = B_type_parse(string);

        std::string source_register1 = register_to_binary(instruction.source_register1);
        std::string source_register2 = register_to_binary(instruction.source_register2);
        std::string label_address = label_address_to_binary(this -> label_to_address(instruction.label_name, label_accumulator));

        std::string assembled_binary = b_binary_to_string(
            label_address,
            source_register2,
            source_register1,
            this -> funct3_BLTU,
            this -> opcode_B
        );

        accumulator -> set_instruction(assembled_binary);
    }
    
    public: void BGEU(std::string& string, Instruction_accumulator* accumulator, Label_accumulator* label_accumulator){

        B_instruction instruction = B_type_parse(string);

        std::string source_register1 = register_to_binary(instruction.source_register1);
        std::string source_register2 = register_to_binary(instruction.source_register2);
        std::string label_address = label_address_to_binary(this -> label_to_address(instruction.label_name, label_accumulator));

        std::string assembled_binary = b_binary_to_string(
            label_address,
            source_register2,
            source_register1,
            this -> funct3_BGEU,
            this -> opcode_B
        );

        accumulator -> set_instruction(assembled_binary);
    }
};