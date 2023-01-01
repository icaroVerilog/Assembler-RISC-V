#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <boost/convert.hpp>
#include <bitset>
#include "../../../instructions_structures/type_I.hpp"
#include "../../../convert_methods/convert_methods.hpp"
#include "../../../instruction_parser/instruction_parser.hpp"
#include "../../../../../accumulator/instruction_accumulator.hpp"
#include "../../../../../accumulator/label_accumulator.hpp"
#include "../../../../../misc/messages/error_messages.hpp"

class M_assembler: public Convert_methods, public Instruction_parser {

    private: std::string opcode_M_32;
    private: std::string opcode_M_64;
    private: std::string assembled_binary;

    private:
        std::string funct7;

        /* 32 bits instructions */

        std::string funct3_MUL;
        std::string funct3_MULH;
        std::string funct3_MULHSU;
        std::string funct3_MULHU;
        std::string funct3_DIV;
        std::string funct3_DIVU;
        std::string funct3_REM;
        std::string funct3_REMU;

        /* 64 bits instructions */

        std::string funct3_MULW;
        std::string funct3_DIVW;
        std::string funct3_DIVUW;
        std::string funct3_REMW;
        std::string funct3_REMUW;


    public: M_assembler(){

        this -> opcode_M_32.assign("0110011");
        this -> opcode_M_64.assign("0111011");

        this -> funct7.assign("0000001");

        this -> funct3_MUL.assign   ("000");
        this -> funct3_MULH.assign  ("001");
        this -> funct3_MULHSU.assign("010");
        this -> funct3_MULHU.assign ("011");
        this -> funct3_DIV.assign   ("100");
        this -> funct3_DIVU.assign  ("101");
        this -> funct3_REM.assign   ("110");
        this -> funct3_REMU.assign  ("111");

        this -> funct3_MULW.assign  ("000");
        this -> funct3_DIVW.assign  ("100");
        this -> funct3_DIVUW.assign ("101");
        this -> funct3_REMW.assign  ("110");
        this -> funct3_REMUW.assign ("111");
    }

    public: void MUL(std::string& string, Instruction_accumulator* accumulator){

        M_instruction instruction = M_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        std::string assembled_binary = m_binary_to_string(
            this -> funct7, 
            parameter_register1, 
            parameter_register2, 
            this -> funct3_MUL, 
            destination_register, 
            opcode_M_32
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void MULH(std::string& string, Instruction_accumulator* accumulator){

        M_instruction instruction = M_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        std::string assembled_binary = m_binary_to_string(
            this -> funct7, 
            parameter_register1, 
            parameter_register2, 
            this -> funct3_MULH, 
            destination_register, 
            opcode_M_32
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void MULHSU(std::string& string, Instruction_accumulator* accumulator){

        M_instruction instruction = M_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        std::string assembled_binary = m_binary_to_string(
            this -> funct7, 
            parameter_register1, 
            parameter_register2, 
            this -> funct3_MULHSU, 
            destination_register, 
            opcode_M_32
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void MULHU(std::string& string, Instruction_accumulator* accumulator){

        M_instruction instruction = M_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        std::string assembled_binary = m_binary_to_string(
            this -> funct7, 
            parameter_register1, 
            parameter_register2, 
            this -> funct3_MULHU, 
            destination_register, 
            opcode_M_32
        );

        accumulator -> set_instruction(assembled_binary);
    }
    
    public: void DIV(std::string& string, Instruction_accumulator* accumulator){

        M_instruction instruction = M_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        std::string assembled_binary = m_binary_to_string(
            this -> funct7, 
            parameter_register1, 
            parameter_register2, 
            this -> funct3_DIV, 
            destination_register, 
            opcode_M_32
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void DIVU(std::string& string, Instruction_accumulator* accumulator){

        M_instruction instruction = M_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        std::string assembled_binary = m_binary_to_string(
            this -> funct7, 
            parameter_register1, 
            parameter_register2, 
            this -> funct3_DIVU, 
            destination_register, 
            opcode_M_32
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void REM(std::string& string, Instruction_accumulator* accumulator){

        M_instruction instruction = M_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        std::string assembled_binary = m_binary_to_string(
            this -> funct7, 
            parameter_register1, 
            parameter_register2, 
            this -> funct3_REM, 
            destination_register, 
            opcode_M_32
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void REMU(std::string& string, Instruction_accumulator* accumulator){

        M_instruction instruction = M_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        std::string assembled_binary = m_binary_to_string(
            this -> funct7, 
            parameter_register1, 
            parameter_register2, 
            this -> funct3_REMU, 
            destination_register, 
            opcode_M_32
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void MULW(std::string& string, Instruction_accumulator* accumulator){

        M_instruction instruction = M_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        std::string assembled_binary = m_binary_to_string(
            this -> funct7, 
            parameter_register1, 
            parameter_register2, 
            this -> funct3_MULW, 
            destination_register, 
            opcode_M_64
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void DIVW(std::string& string, Instruction_accumulator* accumulator){

        M_instruction instruction = M_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        std::string assembled_binary = m_binary_to_string(
            this -> funct7, 
            parameter_register1, 
            parameter_register2, 
            this -> funct3_DIVW, 
            destination_register, 
            opcode_M_64
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void DIVUW(std::string& string, Instruction_accumulator* accumulator){

        M_instruction instruction = M_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        std::string assembled_binary = m_binary_to_string(
            this -> funct7, 
            parameter_register1, 
            parameter_register2, 
            this -> funct3_DIVUW, 
            destination_register, 
            opcode_M_64
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void REMW(std::string& string, Instruction_accumulator* accumulator){

        M_instruction instruction = M_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        std::string assembled_binary = m_binary_to_string(
            this -> funct7, 
            parameter_register1, 
            parameter_register2, 
            this -> funct3_REMW, 
            destination_register, 
            opcode_M_64
        );

        accumulator -> set_instruction(assembled_binary);
    }

    public: void MULW(std::string& string, Instruction_accumulator* accumulator){

        M_instruction instruction = M_type_parse(string);

        std::string destination_register = register_to_binary(instruction.destination_register);
        std::string parameter_register1 = register_to_binary(instruction.parameter_register1);
        std::string parameter_register2 = register_to_binary(instruction.parameter_register2);

        std::string assembled_binary = m_binary_to_string(
            this -> funct7, 
            parameter_register1, 
            parameter_register2, 
            this -> funct3_REMUW, 
            destination_register, 
            opcode_M_64
        );

        accumulator -> set_instruction(assembled_binary);
    }
};